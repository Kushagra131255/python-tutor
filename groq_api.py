import os
import requests
import certifi
from typing import Optional
from dotenv import load_dotenv

load_dotenv()

GROQ_API_KEY = os.getenv("GROQ_API_KEY", "")
GROQ_URL = "https://api.groq.com/openai/v1/chat/completions"

SYSTEM_PROMPT = """You are SUSHANT, a friendly and expert Python tutor bot named PyTutor. 
You help beginners learn Python through clear explanations, code examples, and tips.
Always be encouraging and patient. Use emojis sparingly.
Format code blocks with markdown-style backticks.
Keep responses concise but thorough."""


def ask_groq(user_input: str, history: Optional[list] = None) -> Optional[str]:
    if not GROQ_API_KEY:
        return None

    messages = [{"role": "system", "content": SYSTEM_PROMPT}]

    if history:
        for h in history[-10:]:
            messages.append({
                "role": "user" if h["role"] == "user" else "assistant",
                "content": h["content"]
            })

    messages.append({"role": "user", "content": user_input})

    payload = {
        "model": "llama-3.1-8b-instant",
        "messages": messages,
        "temperature": 0.7,
        "max_tokens": 1024
    }

    try:
        headers = {
            "Authorization": f"Bearer {GROQ_API_KEY}",
            "Content-Type": "application/json"
        }
        resp = requests.post(GROQ_URL, json=payload, headers=headers, timeout=30, verify=certifi.where())
        data = resp.json()

        if "choices" in data and data["choices"]:
            return data["choices"][0]["message"]["content"]
        else:
            error_msg = data.get("error", {}).get("message", "Unknown error")
            return f"⚠️ Groq API error: {error_msg}"
    except requests.exceptions.ConnectionError:
        return "⚠️ Cannot connect to AI service. Please check your internet connection and try again."
    except requests.exceptions.Timeout:
        return "⚠️ Request timed out. Please try again."
    except Exception as e:
        return f"⚠️ Error: {str(e)}"
