from datetime import datetime
from knowledge_base import (
    TOPICS,
    CHEAT_SHEET,
    find_topic,
    find_error_help
)
from quiz_module import QuizRunner

# Try to import Groq — works when API key is set
try:
    from groq_api import ask_groq
    GROQ_AVAILABLE = True
except ImportError:
    GROQ_AVAILABLE = False


class PythonTutorBot:

    def __init__(self):
        self.history = []
        self.quiz = None
        self.current_q = None

    def chat(self, user_input: str) -> str:

        msg = user_input.lower().strip()

        # ==========================
        # QUIZ MODE (always handled locally)
        # ==========================
        if self.quiz and self.current_q:

            if msg == "exit":
                self.quiz = None
                self.current_q = None
                return "✅ Quiz exited. Type 'quiz' to start a new one!"

            if msg in ["a", "b", "c", "d"]:
                result = self.quiz.check_answer(self.current_q, msg)
                next_q = self.quiz.get_question()
                if next_q:
                    self.current_q = next_q
                    return result + "\n\n" + self.format_question(next_q)
                else:
                    score = self.quiz.result()
                    self.quiz = None
                    self.current_q = None
                    return result + "\n\n🎉 Quiz Complete!\n" + score + "\n\nGreat job! Keep practicing!"

            return "👉 Please answer with A, B, C, or D (or type 'exit' to quit quiz)"

        # ==========================
        # START QUIZ (always handled locally)
        # ==========================
        if msg == "quiz":
            self.quiz = QuizRunner()
            self.current_q = self.quiz.get_question()
            return (
                "🧪 Python Quiz Started!\n"
                "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n"
                "I'll ask you 10 questions to test your Python knowledge.\n"
                "Type A, B, C, or D for your answer.\n"
                "Type 'exit' to quit anytime.\n\n"
                "Let's begin!\n\n" +
                self.format_question(self.current_q)
            )

        # ==========================
        # CHEAT SHEET (always local)
        # ==========================
        if msg in ["cheat sheet", "cheatsheet"]:
            return CHEAT_SHEET

        # ==========================
        # HELP command
        # ==========================
        if msg == "help":
            return """📋 AVAILABLE COMMANDS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

🧪 quiz         - Start an interactive quiz
📚 topics       - See all available topics
🗺️ roadmap      - Learning path for beginners
📝 cheat sheet  - Quick reference guide
🤖 AI Mode      - Just ask me ANYTHING about Python!

💡 Examples:
   "what is a decorator?"
   "how does async/await work?"
   "write a function to reverse a string"
   "explain OOP with an example"

🔧 Error Help
   Just describe your error and I'll help fix it!
"""

        if msg == "topics":
            topic_names = "\n".join(f"  • {t.title()}" for t in TOPICS.keys())
            return f"""📚 AVAILABLE TOPICS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

{topic_names}

💡 Just ask me about any topic above — or anything else Python related!
"""

        if msg == "roadmap":
            return """🗺️ PYTHON LEARNING ROADMAP
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

📌 STEP 1: Basics
   • Variables & Data Types
   • Strings & String Methods
   • Numbers & Basic Math

📌 STEP 2: Control Flow
   • Conditionals (if/elif/else)
   • Loops (for & while)
   • List Comprehensions

📌 STEP 3: Data Structures
   • Lists, Tuples, Dictionaries, Sets

📌 STEP 4: Functions
   • Defining Functions, *args/**kwargs
   • Lambda, Scope & Closures

📌 STEP 5: OOP
   • Classes, Inheritance, Magic Methods

📌 STEP 6: Advanced
   • Error Handling, File I/O
   • Decorators, Generators, Async

💡 Type 'quiz' anytime to test your knowledge!
"""

        # ==========================
        # LOG user message
        # ==========================
        self._log("user", user_input)

        # ==========================
        # TRY GROQ AI FIRST
        # ==========================
        if GROQ_AVAILABLE:
            ai_response = ask_groq(user_input, self.history)
            if ai_response and not ai_response.startswith("⚠️"):
                self._log("assistant", ai_response)
                return ai_response
            # If Groq returned a warning, fall through to knowledge base

        # ==========================
        # FALLBACK: Knowledge Base
        # ==========================

        # Error help
        error_help = find_error_help(msg)
        if error_help:
            return f"""🐛 COMMON PYTHON ERRORS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

{error_help}

💡 Need more help? Describe your error and I'll assist you!
"""

        # Topic search
        topic = find_topic(msg)
        if topic:
            return f"""📖 {topic['title'].upper()}
{'='*45}

📚 EXPLANATION
{'-'*45}
{topic['explanation']}

💻 CODE EXAMPLE
{'-'*45}
```python
{topic['code_example']}
```

💡 TIPS & BEST PRACTICES
{'-'*45}
{chr(10).join(f"  ✓ {tip}" for tip in topic['tips'])}

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
💬 Ask me more questions or type 'quiz' to test yourself!
"""

        # ==========================
        # DEFAULT RESPONSE
        # ==========================
        return """🤖 I'm PyTutor — Your AI Python Learning Assistant!

Ask me anything about Python:

   • "what is a list?"
   • "how do loops work?"
   • "explain decorators"
   • "help me debug my code"

Or type 'quiz' to test your knowledge!
"""

    def format_question(self, q):
        return f"""📌 Question ({q.get('difficulty', 'beginner').title()}):

{q['question']}

{chr(10).join(q['options'])}

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
💬 Your answer (A/B/C/D):"""

    def get_welcome_message(self):
        mode = "🤖 AI-Powered" if GROQ_AVAILABLE else "📚 Knowledge Base"
        return f"""🐍 Welcome to PyTutor! ({mode} Mode)

I'm your personal Python learning assistant.

✨ WHAT I CAN DO:
   📚 Explain any Python topic
   🧪 Run interactive quizzes
   🔧 Help debug your errors
   📝 Provide code examples
   💡 Answer ANY Python question

🚀 GET STARTED:
   • Type 'help' for all commands
   • Type 'quiz' to test yourself
   • Or just ask me anything!

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
💬 What would you like to learn about Python?"""

    def _log(self, role, content):
        self.history.append({
            "role": role,
            "content": content,
            "time": datetime.now().isoformat()
        })
