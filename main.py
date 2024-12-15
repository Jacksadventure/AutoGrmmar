import sys
import openai
import random
import subprocess
import os
import stat
import time
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
    •   Every rule is expanded without assumptions or shortcuts.AI
    •   The grammar is fully explicit and suitable for processing directly as JSON.
    •   The output must be a single JSON object with no additional explanations or comments. Always start with <start>.
    •   Escape characters need to be handled properly.
    •   If certain parts of the grammar are difficult to express using context-free grammar or require complex semantic logic, please use <AI:{Description of demand in details}> as a placeholder.
    for example:
H5 page probable contains javascript code.
you can add rules like:
"<js_code>": [["<script>", "<AI:{need java script code}>", "</script>"]],
    •   If the grammar is too complex, you can also add sub-grammar like <SUBGRAMMAR:{Description of demand in details}> as a placeholder.
    for example:
H5 page probable contains javascript code.
you can add rules like:
"<js_code>": [["<script>", "<SUBGRAMMAR:{need java script code}>", "</script>"]],
    •   If some items in the grammar are need to be calculated, you can use <SCRIPT:{Description of demand in details}> as a placeholder.
    for example:
    "<random_string>": [["\"","<SCRIPT:{need a random string}>"],"\""]
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
NO COMMENTS, NO ‘’‘, NO anything else. Just the code.
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
            model="o1-preview",
            messages=[
                {"role": "user", "content": system_prompt.strip()+"\n"+user_prompt.strip()}
            ],
        )
        return response.choices[0].message.content.strip()
    except Exception as e:
        print(f"Error creating chat completion: {e}")
        return None

def get_grammar(description: str,example: str,use_o1=False) -> str:
    """
    Generate a grammar JSON using the auto_grammar_prompt and the given description.
    """
    if use_o1:
        result = create_chat_completion_o1(auto_grammar_prompt, description+"example:\n"+example)
    else:
        result = create_chat_completion(auto_grammar_prompt, description+"example:\n"+example, temperature=0.0,model="gpt-4o-2024-11-20")
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
        current_permissions = stat.S_IMODE(os.lstat(file_path).st_mode)
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

        # delete the temporary files
        os.remove(temp_grammar_path)
        return res.stdout.decode("utf-8")   
    except subprocess.CalledProcessError as e:
        print("Error generating or compiling instance:", e)
        # delete the temporary files
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
    return result

def ensure_executable(file_path):
    """
    Ensure the given file has executable permissions.
    """
    try:
        current_permissions = os.stat(file_path).st_mode
        os.chmod(file_path, current_permissions | stat.S_IXUSR | stat.S_IXGRP | stat.S_IXOTH)
    except OSError as e:
        print(f"Error setting executable permissions on {file_path}: {e}")

def fuzz_with_grammar(batch_size=1000, timeout=140):
    """
    Fuzz using a previously compiled grammar-based program.
    """

    os.makedirs("outputs", exist_ok=True)
    num_grammars = len([name for name in os.listdir("grammars") if name.endswith(".json")])
    for i in range(num_grammars):
        try:
            subprocess.run(
                ["./fuzzer", "-p", f"grammars/grammar_{i}.json", "-c", "1", "-d", "10", "-o", f"output_{i}.c"],
                check=True
            )
        except subprocess.CalledProcessError as e:
            print(f"Error compiling grammar_{i}: {e}")

    # compile the generated output C files
    for i in range(num_grammars):
        try:
            subprocess.run(["clang", f"output_{i}.c", "-o", f"output_{i}"], check=True)
            ensure_executable(f"output_{i}")
        except subprocess.CalledProcessError as e:
            print(f"Error compiling output_{i}.c: {e}")

    for i in range(batch_size):
        grammar_index = random.randint(0, num_grammars - 1)
        output_file = f"outputs/output_{i}.txt"
        with open(output_file, "w") as f:
            try:
                cmd = [f"./output_{grammar_index}"]
                subprocess.run(cmd, stdout=f, timeout=timeout)
                print(f"Generated output_{i}.txt")
            except subprocess.TimeoutExpired:
                print(f"Timeout running grammar_{grammar_index}")
            except subprocess.CalledProcessError as e:
                print(f"Error running grammar_{grammar_index}: {e}")
            except PermissionError as e:
                print(f"Permission error for {cmd}: {e}")
        time.sleep(0.2)

def evaluate_grammar(description: str, instances:list[str]) -> bool:
    user_input = description + "\n" + "\n".join(instances)
    result = get_responce(evaluator_prompt,"Phi3:14b", user_input)
    if "yes" in result.lower():
        return True
    return False

def main():

    # Compile the fuzzer
    compile_fuzzer()

    # Initial description from CLI
    description = sys.argv[1]

    # Get task type
    task_type = get_task_type(description)
    print("Task type:", task_type)
    template = get_example(description,task_type)
    print("+++++++++++++++++++++++++++++++++++++++++++++++++++")
    print(template)
    print("+++++++++++++++++++++++++++++++++++++++++++++++++++")
    # Generate initial grammar


    initial_grammar = get_grammar(description,template)
    if not initial_grammar:
        print("Failed to generate initial grammar.")
        return

    grammars = [initial_grammar]

    for index, gram in enumerate(grammars):
        attempts = 0
        print(f"Enhancing grammar {index}...")
        while attempts < MAX_ENHENCEMENT_ATTEMPTS:
            print(f"Attempt {attempts + 1}")
            # Generate instances
            instances = []
            for _ in range(5):
                instance = get_instance(gram)
                print("Instance:\n", instance)
                if instance.strip():
                    instances.append(instance)
                else:
                    # If instance generation failed, try again or break
                    instances.append("")  # mark empty if failed
            # Evaluate grammar
            if grammar_evaluate(description, instances):
                print("Grammar is good enough.")
                # Grammar is good enough, break out of enhancement attempts
                break
            else:
                # Enhance grammar
                print("Not good enough, Enhancing grammar...")
                if attempts == MAX_ENHENCEMENT_ATTEMPTS - 1:
                    print("task is too complex, enable o1-preview model.")
                    gram = get_grammar(description,template,use_o1=True)
                else:
                    gram = enhance_grammar(gram,description,template,instances)
                grammars[index] = gram
            attempts += 1
            sleep_time = random.randint(5,10)
            time.sleep(sleep_time)
    # Save final grammars
    save_grammars(grammars)

    # Example fuzzing loop with the final grammar (optional)
    # This would require that you have compiled grammar-based executables.
    # Here we just print a message.
    print("Grammars saved and ready for fuzzing.")
    print("Run fuzz_with_grammar to start fuzzing.")
    fuzz_with_grammar()


if __name__ == "__main__":
    main()