import sys
import openai
import random
import subprocess
import os
import stat
import time
import re
from localai import get_responce

openai.api_key = os.getenv("OPENAI_API_KEY")

MAX_ENHENCEMENT_ATTEMPTS = 5

# Prompts
auto_grammar_prompt = """
You are grammar generator. Generate a detailed JSON grammar definition based on the user’s description and a valid example. The grammar must start with <start> and explicitly list every possible rule without relying on abbreviations, shorthand, or syntax resembling EBNF. Each production must be fully expanded and unambiguous.

Here is an example of the required structure:
{
  "<start>": [["<_l_>", "!DOCTYPE html", "<_r_>", "<html_document>"]],
  "<_l_>": [["<"]],
  "<_r_>": [[">"]],
  "<_cl_>": [["</"]],
  "<a_tag>": [["<_l_>", "a", "<d>", "<_r_>", "<a_content-1>", "<_cl_>", "a", "<_r_>"]],
  "<a_content>": [["<heading>"], ["<text>"]],
  "<abbr_tag>": [["<_l_>", "abbr", "<d>", "<_r_>", "<text>", "<_cl_>", "abbr", "<_r_>"]],
  "<acronym_tag>": [["<_l_>", "acronym", "<d>", "<_r_>", "<text>", "<_cl_>", "acronym", "<_r_>"]]
}

You must generate a fully detailed grammar in JSON format, ensuring that:
    •   Every rule is expanded without assumptions or shortcuts.
    •   The grammar is fully explicit and suitable for processing directly as JSON.
    •   The output must be a single JSON object with no additional explanations or comments. Always start with <start>.
    •   Escape characters need to be handled properly.
    •   If certain parts of the grammar are difficult to express using context-free grammar or require complex semantic logic, please use <AI:{Description of demand in details}> as a placeholder.
    for example:
H5 page probable contains javascript code.
you can add rules like:
"<js_code>": [["<script>", "<AI:{need java script code}>", "</script>"]],
    because local AI CANNOT see the context of grammar, so when you want to add these placeholders, please provide all the details, as detailed as possible in the description. so that local AI would know what they should generate.
    So you should not say "other elements" or "other tags" in the grammar. Local AI cannot understand.
    AI is expensive, so please use it wisely. It can only code,others you should manage to generate directly. no more than 5 AI placeholder.
    You don't need to add AI placeholder into non-terminals just taking them as terminals.
"""

program_enhance_prompt = """
You are a grammar detailer and enhancer. Your task is to take an existing grammar written in JSON format and improve it by adding more details, specificity, correct mistakes and explicit rules makes it more adhare to the example. Follow these guidelines when enhancing the grammar:
You will receive a JSON grammar, a despction of what user want and 5 instances. Your task is to modify the grammar according to the problems of the instances.
please make sure that the output must be a single JSON object with no additional explanations or comments. Always start with <start>.
"""

evaluator_prompt = """
You are a prompt evaluator. Your task is to return "yes" or "no" according to the description and the validity of all 5 instances.

It most of instances looks good, can be used for fuzzing, return "yes". Otherwise, return "no".

For example:
Description: C programming language with GNU feature "label as value"
Instance:
int main() {
    void *ptr = &&label;
    goto *ptr;
    label:
        return 0;
}

This is a valid instance. Contribute to "yes".

Another example:
Description: C programming language with GNU feature "label as value"
Instance:
intmain() {
    void *ptr = &&label;
    goto *
    return 0;
}

This is invalid instance. Contribute to "no".
"""

get_example_propmpt = """
You are a code generator. your jpb is to genetrator code based on the user's description. Please strictly follow the user’s requirements.
NO COMMENTS, NO ```, NO anything else. Just the code.
If not requested by the user, please do not add any unnecessary libraries or functions.
You don’t have to make this function meaningful.
for example:
Description: A c function that takes a list of integers and returns the sum of all the integers.
"""

get_task_type_prompt = """
You are a task type classifier. Your task is to classify the task type based on the given description. The task type can be one of the following:
code
input
for example:
Description: A c function that takes a list of integers and returns the sum of all the integers. ---> code
Description: sydney phone number ---> input
"""

def get_task_type(description: str) -> str:
    """
    Get the task type based on the given description.
    """
    result = get_responce(get_task_type_prompt, "phi3:14b", description)
    if "code" in result.lower():
        return "code"
    elif "input" in result.lower():
        return "input"
    return "input" # default to input if not recognized

def create_chat_completion(system_prompt: str, user_prompt: str, model: str = "gpt-4o",temperature=0.0) -> str:
    """
    Create a chat completion given a system prompt and a user prompt.
    """
    try:
        response = openai.ChatCompletion.create(
            model=model,
            messages=[
                {"role": "system", "content": system_prompt.strip()},
                {"role": "user", "content": user_prompt.strip()}
            ],
            temperature=temperature
        )
        return response.choices[0].message.content.strip()
    except Exception as e:
        print(f"Error creating chat completion: {e}")
        return None

# o1-preview model don't support system prompt
def create_chat_completion_o1(system_prompt: str, user_prompt: str) -> str:
    """
    Create a chat completion given a system prompt and a user prompt.
    """
    try:
        response = openai.ChatCompletion.create(
            model="o1-mini",
            messages=[
                {"role": "user", "content": system_prompt.strip()+"\n"+user_prompt.strip()}
            ],
        )
        return response.choices[0].message.content.strip()
    except Exception as e:
        print(f"Error creating chat completion: {e}")
        return None

def get_grammar(description: str,use_o1=False) -> str:
    """
    Generate a grammar JSON using the auto_grammar_prompt and the given description.
    """
    if use_o1:
        result = create_chat_completion_o1(auto_grammar_prompt, description)
    else:
        result = create_chat_completion(auto_grammar_prompt, description, temperature=0.0,model="gpt-4o-2024-11-20")
    return result if result else ""

def grammar_evaluate(description: str, instances: list[str]) -> bool:
    """
    Evaluate if all instances are valid. Returns True if "yes", False otherwise.
    """
    user_input = description + "\n" + "\n".join(instances)
    result = create_chat_completion(evaluator_prompt, user_input)
    if result is not None:
        return "yes" in result.lower()
    return False

def enhance_grammar(grammar: str,description:str,example:str,instances: list[str],use_o1=False) -> str:
    """
    Enhance the given grammar based on provided instances and program_enhance_prompt.
    """
    if use_o1:
        result = create_chat_completion_o1(program_enhance_prompt, grammar + "\n" +"example:\n" + example+ description+"\n".join(instances))
    else:
        result = create_chat_completion(program_enhance_prompt, grammar + "\n" +description+"\n".join(instances))
    return result if result else grammar

def compile_fuzzer():
    """
    Compile the fuzzer from fuzzer.cpp into an executable named 'fuzzer' if available.
    """
    if not os.path.exists("fuzzer.cpp"):
        print("fuzzer.cpp not found, skipping compilation.")
        return
    try:
        subprocess.run(["clang++", "-std=c++20", "fuzzer.cpp", "-o", "fuzzer"], check=True)
        ensure_executable("fuzzer")
    except subprocess.CalledProcessError as e:
        print("Error compiling fuzzer:", e)

def ensure_executable(file_path):
    """
    Ensure the given file has executable permissions.
    """
    try:
        current_permissions = os.stat(file_path).st_mode
        os.chmod(file_path, current_permissions | stat.S_IXUSR | stat.S_IXGRP | stat.S_IXOTH)
    except OSError as e:
        print(f"Error setting executable permissions on {file_path}: {e}")

def get_instance(grammar: str) -> str:
    """
    Generate one instance using the grammar and fuzzer.
    This function assumes you have a binary named 'fuzzer' that accepts '-p' and other arguments.
    The instance is stored in 'output.c'.
    Returns the content of 'output.c' as a string.
    """
    if not grammar.strip():
        return ""

    # Save grammar to a temporary file
    os.makedirs("grammars", exist_ok=True)
    temp_grammar_path = "grammars/temp_grammar.json"
    with open(temp_grammar_path, "w") as f:
        f.write(grammar)

    try:
        subprocess.run(
            ["./fuzzer", "-p", temp_grammar_path, "-d", "10", "-o", "output.c", "-c", "1"],
            check=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )

        # Try to compile the generated output.c to ensure validity (optional step)
        subprocess.run(["clang", "output.c", "-o", "temp_output"], check=True)

        res = subprocess.run(["./temp_output"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

        # delete the temporary grammar file
        os.remove(temp_grammar_path)
        return res.stdout.decode("utf-8")   
    except subprocess.CalledProcessError as e:
        print("Error generating or compiling instance:", e)
        # delete the temporary files
        if os.path.exists(temp_grammar_path):
            os.remove(temp_grammar_path)
        return ""

def save_grammars(grammars: list[str]):
    """
    Save all grammars to the 'grammars' directory.
    """
    os.makedirs("grammars", exist_ok=True)
    for i, grammar in enumerate(grammars):
        with open(f"grammars/grammar_{i}.json", "w") as f:
            f.write(grammar)

def get_example(description: str,tasktp:str) -> str:
    """
    Get an example based on the given description.
    """
    if tasktp == "code":
        result = get_responce(get_example_propmpt, "qwen2.5-coder:14b", description)
    else:
        result = get_responce(get_example_propmpt, "Phi3:14b", description)
    # remove lines ```xxxx in the begining and end of the result
    lines = result.split("\n")
    if len(lines) > 1 and lines[0].startswith("```") and lines[-1].startswith("```"):
        result = "\n".join(lines[1:-1])
    return result

# def get_example(description: str,tasktp:str) -> str:
#     """
#     Get an example based on the given description.
#     """
#     result = get_responce(get_example_propmpt, "Phi3:14b", description)
#     # remove lines ```xxxx in the begining and end of the result
#     lines = result.split("\n")
#     if len(lines) > 1 and lines[0].startswith("```") and lines[-1].startswith("```"):
#         result = "\n".join(lines[1:-1])
#     return result

def fuzz_with_grammar(batch_size=1000, timeout=140):
    """
    Fuzz using the grammar defined in grammar_0.json only.
    """

    os.makedirs("outputs", exist_ok=True)

    # Compile the single grammar-based program
    try:
        subprocess.run(
            ["./fuzzer", "-p", "grammars/grammar_0.json", "-c", "1", "-d", "10", "-o", "output_0.c"],
            check=True
        )
    except subprocess.CalledProcessError as e:
        print(f"Error compiling grammar_0.json: {e}")
        return

    # Compile the generated C file
    try:
        subprocess.run(["clang", "output_0.c", "-o", "output_0"], check=True)
        ensure_executable("output_0")
    except subprocess.CalledProcessError as e:
        print(f"Error compiling output_0.c: {e}")
        return
    
    grammar = open("grammars/grammar_0.json").read()
    placeholders = get_placeholders(grammar)

    # Run the compiled binary batch_size times
    for i in range(batch_size):
        output_file = f"outputs/output_{i}.txt"
        with open(output_file, "w") as f:
            try:
                cmd = ["./output_0"]
                pos = subprocess.run(cmd, stdout=subprocess.PIPE, timeout=timeout)
                text = pos.stdout.decode("utf-8")
                replace_all_placeholders(text, placeholders)
                print(f"Generated output_{i}.txt")
            except subprocess.TimeoutExpired:
                print("Timeout running grammar_0 program")
            except subprocess.CalledProcessError as e:
                print(f"Error running grammar_0 program: {e}")
            except PermissionError as e:
                print(f"Permission error for {cmd}: {e}")
        time.sleep(0.2)

def evaluate_grammar(description: str, instances:list[str]) -> bool:
    user_input = description + "\n" + "\n".join(instances)
    result = get_responce(evaluator_prompt,"Phi3:14b", user_input)
    if "yes" in result.lower():
        return True
    return False

def get_placeholders(grammar: str) -> list[str]:
    """
    Get all placeholders from the given grammar. 
    We'll look for <AI:{...}> patterns.
    """
    import re
    pattern = r"<AI:\{([^}]+)\}>"
    matches = re.findall(pattern, grammar)
    return matches



def replace_all_placeholders(text, placeholders):
    pattern = r"<AI:\{[^}]+\}>"
    while re.search(pattern, text):
        for p in placeholders:
            desc = p.strip()
            ttype = get_task_type(desc)
            example = get_example(desc, ttype)
            placeholder_pattern = f"<AI:{{{desc}}}>"
            text = re.sub(re.escape(placeholder_pattern), example.strip(), text)
    return text


def main():
    # Compile the fuzzer
    compile_fuzzer()

    # if grammars is not empty, read from files and fuzz
    if len(os.listdir("grammars")) > 0:
        fuzz_with_grammar()
    
    # Initial description from CLI
    if len(sys.argv) < 2:
        print("Please provide a description.")
        sys.exit(1)

    description = sys.argv[1]

    initial_grammar = get_grammar(description,use_o1=True)
    save_grammars([initial_grammar])
    # get place holders from initial grammar
    placeholders = get_placeholders(initial_grammar)
    print("Placeholders:", placeholders)

    # Get an instance from the grammar
    text = get_instance(initial_grammar)
    if not text.strip():
        print("No instance generated or instance empty.")
        return

    # If there are placeholders, replace them in the instance
    if placeholders:
        text = replace_all_placeholders(text, placeholders)

    # Print the final instance with placeholders resolved
    print("Final instance:\n", text)

    # fuzz_with_grammar(placeholders)
if __name__ == "__main__":
    main()