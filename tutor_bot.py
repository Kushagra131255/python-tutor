from datetime import datetime
from knowledge_base import (
    TOPICS,
    CHEAT_SHEET,
    find_topic,
    find_error_help
)
from quiz_module import QuizRunner


class PythonTutorBot:

    def __init__(self):
        self.history = []
        self.quiz = None
        self.current_q = None

    def chat(self, user_input: str) -> str:

        msg = user_input.lower().strip()

        # ==========================
        # QUIZ MODE
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
        # START QUIZ
        # ==========================
        if "quiz" in msg:
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
        # COMMANDS
        # ==========================
        if msg == "help":
            return """
📋 AVAILABLE COMMANDS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

🧪 quiz         - Start an interactive quiz
📚 topics       - See all available topics
🗺️ roadmap      - Learning path for beginners
📝 cheat sheet  - Quick reference guide
📖 explain [topic] - Learn about a specific topic

💡 Just ask me anything about Python!
   Examples: "what is a list?", "how do loops work?", "explain functions"

🔧 Error Help
   Just type the error name like "NameError" or "syntaxerror"
"""

        if msg == "topics":
            topic_names = "\n".join(f"  • {t.title()}" for t in TOPICS.keys())
            return f"""📚 AVAILABLE TOPICS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

{topic_names}

💡 Just ask me about any topic above!
   Example: "explain lists" or "what is a dictionary?"
"""

        if msg == "roadmap":
            return """
🗺️ PYTHON LEARNING ROADMAP
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
   • Lists (mutable arrays)
   • Tuples (immutable arrays)
   • Dictionaries (key-value pairs)
   • Sets (unique values)

📌 STEP 4: Functions
   • Defining Functions
   • Parameters & Arguments
   • *args & **kwargs
   • Lambda Functions
   • Scope & Closures

📌 STEP 5: OOP
   • Classes & Objects
   • Inheritance
   • Methods & Properties
   • Magic Methods

📌 STEP 6: Advanced
   • Error Handling
   • File I/O
   • Modules & Packages
   • Decorators
   • Generators

💡 Start with Step 1 and work your way up!
   Type 'quiz' anytime to test your knowledge.
"""

        if msg == "cheat sheet" or msg == "cheatsheet":
            return CHEAT_SHEET


        # ==========================
        # ERROR HELP
        # ==========================
        error_help = find_error_help(msg)
        if error_help:
            return f"""🐛 COMMON PYTHON ERRORS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

{error_help}

💡 Need more help? Describe your error and I'll assist you!
"""


        # ==========================
        # TOPIC SEARCH (SMART)
        # ==========================
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
        return """🤖 Welcome to PyTutor - Your Python Learning Assistant!

I can help you learn Python through:

📚 TOPIC EXPLANATIONS
   Just ask me anything like:
   • "what is a list?"
   • "how do loops work?"
   • "explain functions"
   • "what is OOP?"

🧪 INTERACTIVE QUIZ
   Type 'quiz' to test your knowledge!

🔧 ERROR HELP
   Describe any error you're facing

📝 CODE EXAMPLES
   I provide hands-on examples for each topic

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
💬 What would you like to learn today?
"""


    def format_question(self, q):
        return f"""📌 Question {q.get('difficulty', 'beginner').title()}:

{q['question']}

{chr(10).join(q['options'])}

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
💬 Your answer (A/B/C/D):"""


    def get_welcome_message(self):
        return """🐍 Welcome to PyTutor!

I'm your personal Python learning assistant. 

✨ WHAT I CAN DO:
   📚 Explain any Python topic
   🧪 Run interactive quizzes  
   🔧 Help debug errors
   📝 Provide code examples
   💡 Share tips & best practices

🚀 GET STARTED:
   • Type 'help' for all commands
   • Type 'topics' to see what I know
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
