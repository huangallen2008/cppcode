def chat_bot():
    translations = {
    "hello": {"French": "bonjour", "Korean": "안녕하세요", "Chinese": "你好"},
    "goodbye": {"French": "au revoir", "Korean": "안녕히 가세요", "Chinese": "再見"},
    "thank you": {"French": "merci", "Korean": "감사합니다", "Chinese": "謝謝"},
    }
    target_language = input("")
    if target_language not in ["French", "Korean", "Chinese"]:
        print("Sorry, that language is not supported.")
        return
    user_input = input("").lower()
    if user_input in translations and target_language in translations[user_input]:
        print(f"Translation to {target_language}: {translations[user_input][target_language]}")
    else:
        print("Sorry, translation not found.")  
      
