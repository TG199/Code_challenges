import requests
import random

def get_quote():
    response = requests.get("https://zenquotes.io/api/random")
    json_data = response.json()
    quote = json_data[0]['q'] + " -" + json_data[0]['a']
    return (quote)

def get_challenge(challenges):
    if challenges:
        random_challenge = random.choice(challenges)
        return f"{random_challenge['name']}: {random_challenge['url']}"
    else:
        return "No challenge available"

def add_to_list(challenges):
    if challenges:
        pass
    else:
         return "No challenge available"
def get_list(challenges):
    if challenges:
        all_challenges = ""
        for challenge in challenges:
            all_challenges = all_challenges + f"{challenge['name']}: {challenge['url']}" + "\n"
        return all_challenges
    else:
        return "No challenge available"
    
def get_count(challenges):
    if challenges:
        count = 0
        for i in challenges:
            count+= 1
        return count
    else:
        return "No challenge available"