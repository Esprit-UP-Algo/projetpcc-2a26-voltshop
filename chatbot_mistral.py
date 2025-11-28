from mistralai import Mistral
import os

API_KEY = os.getenv("MISTRAL_API_KEY")  # Make sure key is set
model = "mistral-small-latest"

client = Mistral(api_key=API_KEY)

while True:
    user = input("You: ")

    response = client.chat.complete(
        model=model,
        messages=[{"role": "user", "content": user}]
    )

    # << FIXED LINE >>
    print("Bot:", response.choices[0].message.content)
