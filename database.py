import sqlite3
import hashlib
import json
import math
from datetime import datetime

def hash_password(password: str) -> str:
    return hashlib.sha256(password.encode()).hexdigest()

def verify_password(password: str, hashed: str) -> bool:
    return hash_password(password) == hashed

def init_db():
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()

    cursor.execute("""
    CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT,
        email TEXT UNIQUE,
        password TEXT,
        face_descriptor TEXT DEFAULT NULL,
        face_enabled INTEGER DEFAULT 0,
        created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
    )
    """)

    # Migrate existing DB: add face columns if they don't exist yet
    try:
        cursor.execute("ALTER TABLE users ADD COLUMN face_descriptor TEXT DEFAULT NULL")
    except:
        pass
    try:
        cursor.execute("ALTER TABLE users ADD COLUMN face_enabled INTEGER DEFAULT 0")
    except:
        pass

    cursor.execute("""
    CREATE TABLE IF NOT EXISTS chat_sessions (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        user_id INTEGER,
        title TEXT,
        created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        FOREIGN KEY (user_id) REFERENCES users(id)
    )
    """)

    cursor.execute("""
    CREATE TABLE IF NOT EXISTS chat_messages (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        session_id INTEGER,
        role TEXT,
        content TEXT,
        created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
        FOREIGN KEY (session_id) REFERENCES chat_sessions(id)
    )
    """)

    conn.commit()
    conn.close()


def add_user(name: str, email: str, password: str):
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    try:
        hashed = hash_password(password)
        cursor.execute("INSERT INTO users (name, email, password) VALUES (?, ?, ?)", (name, email, hashed))
        conn.commit()
        return True
    except:
        return False
    finally:
        conn.close()


def check_user(email: str, password: str):
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute("SELECT id, name FROM users WHERE email=? AND password=?",
                   (email, hash_password(password)))
    row = cursor.fetchone()
    conn.close()
    if row:
        return {"id": row[0], "name": row[1], "email": email}
    return None


def get_user(email: str):
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute("SELECT id, name, email FROM users WHERE email=?", (email,))
    row = cursor.fetchone()
    conn.close()
    return {"id": row[0], "name": row[1], "email": row[2]} if row else None


# ══════════════════════════════════════════════
# FACE RECOGNITION FUNCTIONS
# ══════════════════════════════════════════════

def save_face_descriptor(user_id: int, descriptor: list):
    """Save face descriptor (128-float array) for a user."""
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute(
        "UPDATE users SET face_descriptor=?, face_enabled=1 WHERE id=?",
        (json.dumps(descriptor), user_id)
    )
    conn.commit()
    conn.close()


def remove_face_descriptor(user_id: int):
    """Remove face recognition data for a user."""
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute(
        "UPDATE users SET face_descriptor=NULL, face_enabled=0 WHERE id=?",
        (user_id,)
    )
    conn.commit()
    conn.close()


def get_face_status(user_id: int):
    """Check whether a user has face recognition enabled."""
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute("SELECT face_enabled FROM users WHERE id=?", (user_id,))
    row = cursor.fetchone()
    conn.close()
    return bool(row and row[0])


def get_all_face_users():
    """Return all users who have face recognition enabled."""
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute(
        "SELECT id, name, email, face_descriptor FROM users WHERE face_enabled=1 AND face_descriptor IS NOT NULL"
    )
    rows = cursor.fetchall()
    conn.close()
    return [{"id": r[0], "name": r[1], "email": r[2], "descriptor": json.loads(r[3])} for r in rows]


def euclidean_distance(d1: list, d2: list) -> float:
    """Calculate Euclidean distance between two face descriptors."""
    return math.sqrt(sum((a - b) ** 2 for a, b in zip(d1, d2)))


def match_face(descriptor: list, threshold: float = 0.5):
    """
    Compare incoming descriptor against all stored faces.
    Returns user dict if match found, None otherwise.
    Threshold 0.5 = strict, 0.6 = lenient. Default 0.5 is recommended.
    """
    users = get_all_face_users()
    best_match = None
    best_distance = float('inf')

    for user in users:
        dist = euclidean_distance(descriptor, user["descriptor"])
        if dist < best_distance:
            best_distance = dist
            best_match = user

    if best_match and best_distance < threshold:
        return best_match
    return None


# ══════════════════════════════════════════════
# SESSION / MESSAGE FUNCTIONS (unchanged)
# ══════════════════════════════════════════════

def create_session(user_id: int, title: str = "New Chat"):
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute("INSERT INTO chat_sessions (user_id, title) VALUES (?, ?)", (user_id, title))
    session_id = cursor.lastrowid
    conn.commit()
    conn.close()
    return session_id


def get_sessions(user_id: int):
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute("""
        SELECT id, title, created_at
        FROM chat_sessions
        WHERE user_id = ?
        ORDER BY created_at DESC
    """, (user_id,))
    rows = cursor.fetchall()
    conn.close()
    return [{"id": r[0], "title": r[1], "created_at": r[2]} for r in rows]


def get_session(session_id: int):
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute("SELECT id, user_id, title, created_at FROM chat_sessions WHERE id=?", (session_id,))
    row = cursor.fetchone()
    conn.close()
    return {"id": row[0], "user_id": row[1], "title": row[2], "created_at": row[3]} if row else None


def delete_session(session_id: int):
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute("DELETE FROM chat_messages WHERE session_id=?", (session_id,))
    cursor.execute("DELETE FROM chat_sessions WHERE id=?", (session_id,))
    conn.commit()
    conn.close()


def update_session_title(session_id: int, title: str):
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute("UPDATE chat_sessions SET title=? WHERE id=?", (title, session_id))
    conn.commit()
    conn.close()


def add_message(session_id: int, role: str, content: str):
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute("INSERT INTO chat_messages (session_id, role, content) VALUES (?, ?, ?)",
                   (session_id, role, content))
    conn.commit()
    conn.close()


def get_messages(session_id: int):
    conn = sqlite3.connect("users.db")
    cursor = conn.cursor()
    cursor.execute("""
        SELECT role, content, created_at
        FROM chat_messages
        WHERE session_id = ?
        ORDER BY created_at ASC
    """, (session_id,))
    rows = cursor.fetchall()
    conn.close()
    return [{"role": r[0], "content": r[1], "created_at": r[2]} for r in rows]
