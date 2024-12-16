from langchain.llms import Ollama

def get_responce(prompt: str, model: str, text: str):
    target_model = Ollama(model = model)
    message = [
        {
            "role": "system",
            "content": prompt
        },
        {
            "role": "user",
            "content": text
        }
    ]
    response = target_model.invoke(message)
    return response

