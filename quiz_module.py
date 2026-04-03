import random

QUIZZES = [

# -------- REAL QUESTIONS --------
{
"question": "Who developed Python?",
"options": ["A) James Gosling", "B) Guido van Rossum", "C) Dennis Ritchie", "D) Bjarne Stroustrup"],
"answer": "B",
"explanation": "Python was developed by Guido van Rossum.",
"difficulty": "beginner"
},
{
"question": "Which extension is used for Python files?",
"options": ["A) .py", "B) .java", "C) .txt", "D) .cpp"],
"answer": "A",
"explanation": ".py is Python file extension.",
"difficulty": "beginner"
},
{
"question": "Is Python case sensitive?",
"options": ["A) Yes", "B) No", "C) Sometimes", "D) Depends"],
"answer": "A",
"explanation": "Python is case sensitive.",
"difficulty": "beginner"
},
{
"question": "What is output: print(2+3*5)?",
"options": ["A) 25", "B) 17", "C) 10", "D) 15"],
"answer": "B",
"explanation": "3*5=15 +2 =17",
"difficulty": "beginner"
},
{
"question": "Which is mutable?",
"options": ["A) tuple", "B) string", "C) list", "D) int"],
"answer": "C",
"explanation": "List is mutable.",
"difficulty": "beginner"
}

]

# 🔥 ADD MORE QUESTIONS (TOTAL ~50)
for i in range(1, 46):
    correct = i * 2
    wrong1 = correct + 1
    wrong2 = correct - 1
    wrong3 = correct + 2
    
    QUIZZES.append({
        "question": f"What is output: print({i} * 2)?",
        "options": [
            f"A) {i}",
            f"B) {correct}",
            f"C) {wrong1}",
            f"D) {wrong2}"
        ],
        "answer": "B",
        "explanation": f"{i} * 2 = {correct}",
        "difficulty": "beginner"
    })


# ==========================
# QUIZ RUNNER
# ==========================
class QuizRunner:

    def __init__(self):
        shuffled = QUIZZES.copy()
        random.shuffle(shuffled)

        self.questions = shuffled[:10]  # 🔥 only 10 questions
        self.index = 0
        self.score = 0

    def get_question(self):
        if self.index >= len(self.questions):
            return None
        q = self.questions[self.index]
        self.index += 1
        return q

    def check_answer(self, q, user):
        if user.upper() == q["answer"]:
            self.score += 1
            return f"✅ Correct!\n{q['explanation']}"
        else:
            return f"❌ Wrong! Answer: {q['answer']}\n{q['explanation']}"

    def result(self):
        return f"🎯 Final Score: {self.score}/10"