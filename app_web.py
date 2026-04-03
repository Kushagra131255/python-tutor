import os
from flask import Flask, render_template, request, jsonify, session, redirect
from tutor_bot import PythonTutorBot
from database import (
    init_db, add_user, check_user, get_user,
    create_session, get_sessions, get_session, delete_session, update_session_title,
    add_message, get_messages
)

app = Flask(__name__)
app.secret_key = os.environ.get("SECRET_KEY", "supersecretkey")

init_db()

bots = {}

def get_bot(session_id):
    if session_id not in bots:
        bots[session_id] = PythonTutorBot()
    return bots[session_id]

@app.route("/api/user", methods=["GET"])
def api_get_user():
    if "user" not in session:
        return jsonify({"error": "Not logged in"}), 401
    
    return jsonify({
        "name": session.get("name", ""),
        "email": session.get("user", "")
    })

@app.route("/login")
def login_page():
    return render_template("login.html")

@app.route("/")
def index():
    if "user" not in session:
        return redirect("/login")
    
    return render_template("index.html")

@app.route("/api/login", methods=["POST"])
def login():
    data = request.get_json()
    
    if not data or "email" not in data or "password" not in data:
        return jsonify({"error": "Email and password required"}), 400
    
    email = data.get("email", "").strip()
    password = data.get("password", "")
    
    if not email or not password:
        return jsonify({"error": "Email and password required"}), 400
    
    user = check_user(email, password)
    if user:
        session["user"] = user["email"]
        session["user_id"] = user["id"]
        session["name"] = user["name"]
        return jsonify({"redirect": "/", "name": user["name"]})

    return jsonify({"error": "Invalid credentials"}), 401

@app.route("/api/signup", methods=["POST"])
def signup():
    data = request.get_json()
    
    if not data or "email" not in data or "password" not in data:
        return jsonify({"error": "Email and password required"}), 400
    
    name = data.get("name", "").strip()
    email = data.get("email", "").strip()
    password = data.get("password", "")
    
    if not name:
        return jsonify({"error": "Name is required"}), 400
    if not email:
        return jsonify({"error": "Email is required"}), 400
    if not password or len(password) < 8:
        return jsonify({"error": "Password must be at least 8 characters"}), 400
    
    success = add_user(name, email, password)
    
    if not success:
        return jsonify({"error": "Email already exists"}), 409
    
    user = check_user(email, password)
    if user:
        session["user"] = user["email"]
        session["user_id"] = user["id"]
        session["name"] = user["name"]
    
    return jsonify({"redirect": "/"})

@app.route("/logout")
def logout():
    session.clear()
    return redirect("/login")

@app.route("/api/sessions", methods=["GET"])
def api_get_sessions():
    if "user_id" not in session:
        return jsonify({"error": "Unauthorized"}), 401
    
    sessions = get_sessions(session["user_id"])
    return jsonify({"sessions": sessions})

@app.route("/api/sessions", methods=["POST"])
def api_create_session():
    if "user_id" not in session:
        return jsonify({"error": "Unauthorized"}), 401
    
    session_id = create_session(session["user_id"], "New Chat")
    return jsonify({"session_id": session_id})

@app.route("/api/sessions/<int:session_id>", methods=["DELETE"])
def api_delete_session(session_id):
    if "user_id" not in session:
        return jsonify({"error": "Unauthorized"}), 401
    
    s = get_session(session_id)
    if s and s["user_id"] == session["user_id"]:
        delete_session(session_id)
        return jsonify({"status": "ok"})
    
    return jsonify({"error": "Not found"}), 404

@app.route("/api/sessions/<int:session_id>", methods=["PUT"])
def api_update_session(session_id):
    if "user_id" not in session:
        return jsonify({"error": "Unauthorized"}), 401
    
    data = request.get_json()
    title = data.get("title", "New Chat")
    
    s = get_session(session_id)
    if s and s["user_id"] == session["user_id"]:
        update_session_title(session_id, title)
        return jsonify({"status": "ok"})
    
    return jsonify({"error": "Not found"}), 404

@app.route("/api/sessions/<int:session_id>/messages", methods=["GET"])
def api_get_messages(session_id):
    if "user_id" not in session:
        return jsonify({"error": "Unauthorized"}), 401
    
    s = get_session(session_id)
    if s and s["user_id"] == session["user_id"]:
        messages = get_messages(session_id)
        return jsonify({"messages": messages, "title": s["title"]})
    
    return jsonify({"error": "Not found"}), 404

@app.route("/chat", methods=["POST"])
def chat():
    data = request.get_json()
    msg = data.get("message", "")
    session_id = data.get("session_id")
    
    if not session_id:
        return jsonify({"error": "No session"}), 400
    
    bot = get_bot(session_id)
    response = bot.chat(msg)
    
    if session_id and "user_id" in session:
        s = get_session(session_id)
        if s and s["user_id"] == session["user_id"]:
            add_message(session_id, "user", msg)
            add_message(session_id, "bot", response)
            
            if s["title"] == "New Chat" and msg:
                title = msg[:50] + ("..." if len(msg) > 50 else "")
                update_session_title(session_id, title)
    
    return jsonify({"response": response})

@app.route("/welcome")
def welcome():
    bot = PythonTutorBot()
    return jsonify({"response": bot.get_welcome_message()})

@app.route("/new_chat")
def new_chat():
    session["sid"] = os.urandom(16).hex()
    return jsonify({"status": "ok"})

if __name__ == "__main__":
    port = int(os.environ.get("PORT", 5000))
    app.run(host="0.0.0.0", port=port, debug=False)
