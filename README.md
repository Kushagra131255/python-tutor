# PyTutor — Python Learning Assistant

PyTutor is a web-based Python tutoring app built with Flask. It helps learners explore Python topics, get explanations and error guidance, and practise with multiple-choice quizzes. An optional Groq-powered chat response is available when an API key is configured.

## Features

- **Tutor chat:** Ask questions about Python and receive beginner-friendly explanations.
- **Learning resources:** Uses a built-in knowledge base with topic explanations, a cheat sheet, and common-error help.
- **Quiz mode:** Practise with multiple-choice questions and receive feedback.
- **Accounts and sessions:** Sign up, log in, and keep chat sessions and messages.
- **Optional face login:** Register or remove a face descriptor for face-based login.
- **Web interface:** Flask serves the login, face setup, and tutor pages.

## Tech stack

- Python
- Flask
- SQLite
- HTML, CSS, and JavaScript
- Groq API (optional)
- Gunicorn for deployment

## Getting started

### 1. Clone the repository

```bash
git clone https://github.com/Kushagra131255/python-tutor.git
cd python-tutor
```

### 2. Create and activate a virtual environment

```bash
python -m venv .venv
```

Windows:

```bash
.venv\\Scripts\\activate
```

macOS/Linux:

```bash
source .venv/bin/activate
```

### 3. Install dependencies

```bash
pip install -r requirements.txt
```

### 4. Configure environment variables

Create a local `.env` file if you want to use Groq-powered responses:

```env
GROQ_API_KEY=your_groq_api_key
SECRET_KEY=replace_with_a_long_random_secret
```

The built-in tutor features can work without a Groq key; AI-powered responses may be unavailable. Keep real API keys and secrets private and never commit them to GitHub.

### 5. Run the app locally

```bash
flask --app app_web run --debug
```

Open the local URL printed by Flask in your browser. The SQLite database (`users.db`) is initialized automatically when the app starts.

## Deployment

The repository includes a `Procfile` for running the Flask app with Gunicorn and a `railway.toml` configuration file. Configure `SECRET_KEY` and, if needed, `GROQ_API_KEY` as environment variables in your hosting provider.

## Main files

| File | Purpose |
| --- | --- |
| `app_web.py` | Flask routes, authentication, chat, and face-login endpoints |
| `tutor_bot.py` | Tutor conversation flow and quiz-mode integration |
| `knowledge_base.py` | Python learning topics, cheat sheet, and error help |
| `quiz_module.py` | Multiple-choice quiz logic |
| `groq_api.py` | Optional Groq API integration |
| `database.py` | SQLite user, session, message, and face-descriptor storage |
| `templates/` | Login, tutor, and face-setup pages |
| `static/` | Static web assets |
| `requirements.txt` | Python dependencies |

## Security notes

- Set a strong, unique `SECRET_KEY` in the deployment environment; do not rely on a development fallback.
- Before production use, replace the current plain SHA-256 password hashing with a password-hashing scheme designed for passwords, such as Werkzeug's password hash utilities or Argon2.
- Treat face descriptors and account data as sensitive information. Use HTTPS and review authentication and data-retention practices before exposing the app publicly.

## License

No license file is currently included. Add a license if you want to specify how others may use, modify, or distribute this project.
