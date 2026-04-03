"""
knowledge_base.py
─────────────────
Stores Python topics, explanations, code examples, and tips.
"""

TOPICS = {
    "variables": {
        "title": "Variables & Data Types",
        "explanation": (
            "Variables are containers for storing data values.\n"
            "Python has no command for declaring a variable — "
            "a variable is created the moment you first assign a value to it.\n\n"
            "Common data types:\n"
            "  • int    → whole numbers (e.g. 42)\n"
            "  • float  → decimal numbers (e.g. 3.14)\n"
            "  • str    → text strings (e.g. 'hello')\n"
            "  • bool   → True / False\n"
            "  • None   → represents 'nothing'"
        ),
        "code_example": (
            "# Creating variables\n"
            "name = 'Alice'          # str\n"
            "age = 30                # int\n"
            "height = 5.6            # float\n"
            "is_student = True       # bool\n"
            "middle_name = None      # NoneType\n\n"
            "# Check the type\n"
            "print(type(name))       # <class 'str'>\n"
            "print(type(age))        # <class 'int'>"
        ),
        "tips": [
            "Variable names are case-sensitive: 'Age' and 'age' are different.",
            "Use snake_case for variable names (PEP 8 convention).",
            "You can assign multiple variables in one line: a, b, c = 1, 2, 3",
        ],
        "keywords": ["variable", "variables", "data type", "data types",
                      "int", "float", "str", "bool", "type", "assign"],
    },

    "strings": {
        "title": "Strings",
        "explanation": (
            "Strings are sequences of characters enclosed in quotes.\n"
            "You can use single ('...'), double (\"...\"), or triple quotes "
            "('''...''' or \"\"\"...\"\"\") for multi-line strings.\n\n"
            "Key operations:\n"
            "  • Concatenation: 'Hello' + ' World'\n"
            "  • Repetition:    'Ha' * 3  → 'HaHaHa'\n"
            "  • Indexing:      s[0], s[-1]\n"
            "  • Slicing:       s[1:4], s[:3], s[::2]\n"
            "  • f-strings:     f'My name is {name}'"
        ),
        "code_example": (
            "greeting = 'Hello, World!'\n\n"
            "# Indexing & Slicing\n"
            "print(greeting[0])      # 'H'\n"
            "print(greeting[-1])     # '!'\n"
            "print(greeting[0:5])    # 'Hello'\n\n"
            "# Useful methods\n"
            "print(greeting.upper())          # 'HELLO, WORLD!'\n"
            "print(greeting.lower())          # 'hello, world!'\n"
            "print(greeting.replace('World', 'Python'))  # 'Hello, Python!'\n"
            "print(greeting.split(', '))      # ['Hello', 'World!']\n\n"
            "# f-string formatting\n"
            "name = 'Alice'\n"
            "age = 30\n"
            "print(f'{name} is {age} years old.')  # 'Alice is 30 years old.'"
        ),
        "tips": [
            "Strings are immutable — you cannot change a character in place.",
            "Use .strip() to remove leading/trailing whitespace.",
            "Use 'in' to check substrings: 'Hell' in 'Hello' → True",
        ],
        "keywords": ["string", "strings", "text", "concatenat", "slice",
                      "slicing", "f-string", "format", "split", "join",
                      "upper", "lower", "strip", "replace"],
    },

    "lists": {
        "title": "Lists",
        "explanation": (
            "Lists are ordered, mutable collections that can hold items "
            "of any type.\n\n"
            "Key characteristics:\n"
            "  • Ordered (items have a defined order)\n"
            "  • Mutable (can be changed after creation)\n"
            "  • Allow duplicates\n"
            "  • Indexed starting at 0"
        ),
        "code_example": (
            "fruits = ['apple', 'banana', 'cherry']\n\n"
            "# Accessing elements\n"
            "print(fruits[0])         # 'apple'\n"
            "print(fruits[-1])        # 'cherry'\n\n"
            "# Modifying\n"
            "fruits.append('date')    # Add to end\n"
            "fruits.insert(1, 'avocado')  # Insert at index\n"
            "fruits.remove('banana')  # Remove by value\n"
            "popped = fruits.pop()    # Remove & return last item\n\n"
            "# List comprehension\n"
            "squares = [x**2 for x in range(10)]\n"
            "print(squares)  # [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]\n\n"
            "# Useful methods\n"
            "nums = [3, 1, 4, 1, 5]\n"
            "nums.sort()              # Sort in place\n"
            "print(len(nums))         # 5"
        ),
        "tips": [
            "Use list comprehensions for concise list creation.",
            "To copy a list, use nums.copy() or nums[:] — not new = nums.",
            "sorted(list) returns a NEW sorted list; list.sort() sorts in place.",
        ],
        "keywords": ["list", "lists", "append", "remove", "pop", "sort",
                      "sorted", "list comprehension", "index", "array"],
    },

    "dictionaries": {
        "title": "Dictionaries",
        "explanation": (
            "Dictionaries store data in key:value pairs.\n\n"
            "Key characteristics:\n"
            "  • Keys must be unique and immutable (str, int, tuple)\n"
            "  • Values can be any type\n"
            "  • Ordered (Python 3.7+)\n"
            "  • Mutable"
        ),
        "code_example": (
            "person = {\n"
            "    'name': 'Alice',\n"
            "    'age': 30,\n"
            "    'hobbies': ['reading', 'coding']\n"
            "}\n\n"
            "# Accessing values\n"
            "print(person['name'])          # 'Alice'\n"
            "print(person.get('email', 'N/A'))  # 'N/A' (default)\n\n"
            "# Modifying\n"
            "person['age'] = 31             # Update\n"
            "person['email'] = 'a@b.com'    # Add new key\n"
            "del person['hobbies']          # Delete key\n\n"
            "# Iterating\n"
            "for key, value in person.items():\n"
            "    print(f'{key}: {value}')\n\n"
            "# Dictionary comprehension\n"
            "squares = {x: x**2 for x in range(6)}\n"
            "print(squares)  # {0: 0, 1: 1, 2: 4, 3: 9, 4: 16, 5: 25}"
        ),
        "tips": [
            "Use .get(key, default) to avoid KeyError.",
            "Use .keys(), .values(), .items() for iteration.",
            "Merge dicts (Python 3.9+): merged = dict1 | dict2",
        ],
        "keywords": ["dict", "dictionary", "dictionaries", "key", "value",
                      "key-value", "hash", "mapping", "items", "keys", "values"],
    },

    "loops": {
        "title": "Loops (for & while)",
        "explanation": (
            "Loops let you execute a block of code repeatedly.\n\n"
            "Python has two main loop types:\n"
            "  • for loop  — iterates over a sequence\n"
            "  • while loop — runs as long as a condition is True\n\n"
            "Control statements:\n"
            "  • break    — exit the loop entirely\n"
            "  • continue — skip to the next iteration\n"
            "  • else     — runs when loop finishes normally (no break)"
        ),
        "code_example": (
            "# for loop\n"
            "for i in range(5):\n"
            "    print(i)  # 0, 1, 2, 3, 4\n\n"
            "# for loop over a list\n"
            "fruits = ['apple', 'banana', 'cherry']\n"
            "for fruit in fruits:\n"
            "    print(fruit)\n\n"
            "# enumerate for index + value\n"
            "for idx, fruit in enumerate(fruits):\n"
            "    print(f'{idx}: {fruit}')\n\n"
            "# while loop\n"
            "count = 0\n"
            "while count < 5:\n"
            "    print(count)\n"
            "    count += 1\n\n"
            "# break and continue\n"
            "for n in range(10):\n"
            "    if n == 3:\n"
            "        continue   # skip 3\n"
            "    if n == 7:\n"
            "        break      # stop at 7\n"
            "    print(n)       # 0, 1, 2, 4, 5, 6"
        ),
        "tips": [
            "Prefer 'for' loops when the number of iterations is known.",
            "Use enumerate() instead of range(len(...)).",
            "Be careful with while loops — ensure the condition eventually becomes False!",
        ],
        "keywords": ["loop", "loops", "for", "while", "iterate", "iteration",
                      "range", "break", "continue", "enumerate", "repeat"],
    },

    "functions": {
        "title": "Functions",
        "explanation": (
            "Functions are reusable blocks of code that perform a specific task.\n\n"
            "Key concepts:\n"
            "  • def keyword to define\n"
            "  • Parameters vs Arguments\n"
            "  • return statement\n"
            "  • Default parameter values\n"
            "  • *args and **kwargs\n"
            "  • Lambda (anonymous) functions\n"
            "  • Docstrings for documentation"
        ),
        "code_example": (
            "# Basic function\n"
            "def greet(name):\n"
            "    \"\"\"Return a greeting string.\"\"\"\n"
            "    return f'Hello, {name}!'\n\n"
            "print(greet('Alice'))  # 'Hello, Alice!'\n\n"
            "# Default parameters\n"
            "def power(base, exp=2):\n"
            "    return base ** exp\n\n"
            "print(power(3))      # 9\n"
            "print(power(3, 3))   # 27\n\n"
            "# *args and **kwargs\n"
            "def summarize(*args, **kwargs):\n"
            "    print(f'Args: {args}')\n"
            "    print(f'Kwargs: {kwargs}')\n\n"
            "summarize(1, 2, 3, name='Alice', age=30)\n\n"
            "# Lambda function\n"
            "square = lambda x: x ** 2\n"
            "print(square(5))  # 25\n\n"
            "# Using lambda with sorted\n"
            "pairs = [(1, 'b'), (3, 'a'), (2, 'c')]\n"
            "sorted_pairs = sorted(pairs, key=lambda p: p[1])\n"
            "print(sorted_pairs)  # [(3, 'a'), (1, 'b'), (2, 'c')]"
        ),
        "tips": [
            "Keep functions small and focused on one task.",
            "Always add docstrings to describe what a function does.",
            "Use type hints: def greet(name: str) -> str:",
        ],
        "keywords": ["function", "functions", "def", "return", "parameter",
                      "argument", "args", "kwargs", "lambda", "callable",
                      "docstring", "scope"],
    },

    "conditionals": {
        "title": "Conditionals (if / elif / else)",
        "explanation": (
            "Conditional statements let your program make decisions.\n\n"
            "Structure:\n"
            "  if condition:\n"
            "      ...\n"
            "  elif another_condition:\n"
            "      ...\n"
            "  else:\n"
            "      ...\n\n"
            "Comparison operators: ==, !=, <, >, <=, >=\n"
            "Logical operators:    and, or, not\n"
            "Identity operators:   is, is not\n"
            "Membership operators: in, not in"
        ),
        "code_example": (
            "age = 18\n\n"
            "if age >= 21:\n"
            "    print('Full access')\n"
            "elif age >= 18:\n"
            "    print('Partial access')\n"
            "else:\n"
            "    print('No access')\n\n"
            "# Ternary (conditional expression)\n"
            "status = 'adult' if age >= 18 else 'minor'\n"
            "print(status)  # 'adult'\n\n"
            "# Logical operators\n"
            "x = 10\n"
            "if x > 0 and x < 100:\n"
            "    print('x is between 0 and 100')\n\n"
            "# Membership test\n"
            "fruits = ['apple', 'banana']\n"
            "if 'apple' in fruits:\n"
            "    print('Found apple!')"
        ),
        "tips": [
            "Use 'is' for None checks: if x is None:",
            "Avoid deep nesting — consider early returns or guard clauses.",
            "Truthy/Falsy: 0, '', [], {}, None, False are all Falsy.",
        ],
        "keywords": ["if", "elif", "else", "conditional", "condition",
                      "comparison", "ternary", "boolean", "and", "or", "not"],
    },

    "classes": {
        "title": "Classes & Object-Oriented Programming",
        "explanation": (
            "Classes are blueprints for creating objects.\n\n"
            "Key OOP concepts:\n"
            "  • Class       — the blueprint\n"
            "  • Object      — an instance of a class\n"
            "  • __init__    — constructor method\n"
            "  • self        — reference to the current instance\n"
            "  • Attributes  — data stored in an object\n"
            "  • Methods     — functions defined inside a class\n"
            "  • Inheritance — creating child classes\n"
            "  • Encapsulation, Polymorphism, Abstraction"
        ),
        "code_example": (
            "class Dog:\n"
            "    # Class attribute\n"
            "    species = 'Canis familiaris'\n\n"
            "    def __init__(self, name, age):\n"
            "        # Instance attributes\n"
            "        self.name = name\n"
            "        self.age = age\n\n"
            "    def bark(self):\n"
            "        return f'{self.name} says Woof!'\n\n"
            "    def __str__(self):\n"
            "        return f'{self.name} ({self.age} years old)'\n\n"
            "# Create instances\n"
            "rex = Dog('Rex', 5)\n"
            "print(rex.bark())   # 'Rex says Woof!'\n"
            "print(rex)          # 'Rex (5 years old)'\n\n"
            "# Inheritance\n"
            "class GuideDog(Dog):\n"
            "    def __init__(self, name, age, handler):\n"
            "        super().__init__(name, age)\n"
            "        self.handler = handler\n\n"
            "    def guide(self):\n"
            "        return f'{self.name} is guiding {self.handler}'\n\n"
            "buddy = GuideDog('Buddy', 3, 'John')\n"
            "print(buddy.guide())  # 'Buddy is guiding John'\n"
            "print(buddy.bark())   # 'Buddy says Woof!' (inherited)"
        ),
        "tips": [
            "Use __str__ for human-readable representation, __repr__ for debugging.",
            "Prefer composition over inheritance when possible.",
            "Use @property for computed attributes with getter/setter logic.",
        ],
        "keywords": ["class", "classes", "object", "oop", "init", "self",
                      "inheritance", "method", "attribute", "constructor",
                      "encapsulation", "polymorphism", "instance"],
    },

    "file_handling": {
        "title": "File Handling",
        "explanation": (
            "Python can read, write, and manipulate files using built-in functions.\n\n"
            "Modes:\n"
            "  • 'r'  — Read (default)\n"
            "  • 'w'  — Write (overwrites)\n"
            "  • 'a'  — Append\n"
            "  • 'x'  — Create (fails if exists)\n"
            "  • 'b'  — Binary mode (e.g., 'rb')\n\n"
            "Always use 'with' statement for automatic file closing."
        ),
        "code_example": (
            "# Writing to a file\n"
            "with open('example.txt', 'w') as f:\n"
            "    f.write('Hello, World!\\n')\n"
            "    f.write('Second line.\\n')\n\n"
            "# Reading entire file\n"
            "with open('example.txt', 'r') as f:\n"
            "    content = f.read()\n"
            "    print(content)\n\n"
            "# Reading line by line\n"
            "with open('example.txt', 'r') as f:\n"
            "    for line in f:\n"
            "        print(line.strip())\n\n"
            "# Appending to a file\n"
            "with open('example.txt', 'a') as f:\n"
            "    f.write('Appended line.\\n')\n\n"
            "# Working with JSON\n"
            "import json\n\n"
            "data = {'name': 'Alice', 'age': 30}\n"
            "with open('data.json', 'w') as f:\n"
            "    json.dump(data, f, indent=2)\n\n"
            "with open('data.json', 'r') as f:\n"
            "    loaded = json.load(f)\n"
            "    print(loaded)"
        ),
        "tips": [
            "Always use 'with' to handle files — it auto-closes them.",
            "Use pathlib for cross-platform path handling.",
            "For large files, read line by line instead of f.read().",
        ],
        "keywords": ["file", "files", "read", "write", "open", "close",
                      "with", "append", "json", "csv", "io", "path"],
    },

    "error_handling": {
        "title": "Error Handling (try / except)",
        "explanation": (
            "Error handling prevents your program from crashing unexpectedly.\n\n"
            "Structure:\n"
            "  try:\n"
            "      # risky code\n"
            "  except SomeError as e:\n"
            "      # handle the error\n"
            "  else:\n"
            "      # runs if NO error occurred\n"
            "  finally:\n"
            "      # ALWAYS runs (cleanup)\n\n"
            "Common exceptions: ValueError, TypeError, KeyError,\n"
            "IndexError, FileNotFoundError, ZeroDivisionError"
        ),
        "code_example": (
            "# Basic try/except\n"
            "try:\n"
            "    num = int(input('Enter a number: '))\n"
            "    result = 10 / num\n"
            "except ValueError:\n"
            "    print('That is not a valid number!')\n"
            "except ZeroDivisionError:\n"
            "    print('Cannot divide by zero!')\n"
            "else:\n"
            "    print(f'Result: {result}')\n"
            "finally:\n"
            "    print('Done.')\n\n"
            "# Raising exceptions\n"
            "def set_age(age):\n"
            "    if age < 0:\n"
            "        raise ValueError('Age cannot be negative')\n"
            "    return age\n\n"
            "# Custom exceptions\n"
            "class InsufficientFundsError(Exception):\n"
            "    def __init__(self, balance, amount):\n"
            "        self.balance = balance\n"
            "        self.amount = amount\n"
            "        super().__init__(\n"
            "            f'Cannot withdraw {amount}. Balance: {balance}'\n"
            "        )"
        ),
        "tips": [
            "Catch specific exceptions, not bare 'except:'.",
            "Use 'raise' to re-raise or throw custom exceptions.",
            "Use 'finally' for cleanup (closing connections, etc.).",
        ],
        "keywords": ["error", "exception", "try", "except", "finally",
                      "raise", "catch", "handle", "traceback", "bug",
                      "debug", "crash", "valueerror", "typeerror"],
    },

    "modules": {
        "title": "Modules & Imports",
        "explanation": (
            "Modules let you organize code into separate files and reuse it.\n\n"
            "Types of imports:\n"
            "  • import module\n"
            "  • from module import something\n"
            "  • from module import *  (not recommended)\n"
            "  • import module as alias\n\n"
            "Popular standard library modules:\n"
            "  os, sys, math, random, datetime, json, re, pathlib, collections"
        ),
        "code_example": (
            "# Standard imports\n"
            "import math\n"
            "print(math.sqrt(16))   # 4.0\n"
            "print(math.pi)         # 3.14159...\n\n"
            "from random import randint, choice\n"
            "print(randint(1, 10))  # Random int 1-10\n\n"
            "from datetime import datetime\n"
            "now = datetime.now()\n"
            "print(now.strftime('%Y-%m-%d %H:%M:%S'))\n\n"
            "import os\n"
            "print(os.getcwd())     # Current directory\n\n"
            "# Creating your own module:\n"
            "# mymodule.py\n"
            "#   def add(a, b): return a + b\n"
            "#\n"
            "# main.py\n"
            "#   from mymodule import add\n"
            "#   print(add(2, 3))"
        ),
        "tips": [
            "Use 'if __name__ == \"__main__\":' to guard executable code.",
            "Install third-party packages with: pip install package_name",
            "Use virtual environments to isolate project dependencies.",
        ],
        "keywords": ["module", "modules", "import", "from", "package",
                      "library", "pip", "install", "standard library"],
    },

    "list_comprehension": {
        "title": "Comprehensions (List, Dict, Set)",
        "explanation": (
            "Comprehensions provide a concise way to create collections.\n\n"
            "Syntax:\n"
            "  List:  [expr for item in iterable if condition]\n"
            "  Dict:  {key: val for item in iterable if condition}\n"
            "  Set:   {expr for item in iterable if condition}\n"
            "  Generator: (expr for item in iterable if condition)"
        ),
        "code_example": (
            "# List comprehension\n"
            "squares = [x**2 for x in range(10)]\n"
            "evens = [x for x in range(20) if x % 2 == 0]\n\n"
            "# With transformation\n"
            "words = ['hello', 'world']\n"
            "upper_words = [w.upper() for w in words]\n\n"
            "# Nested comprehension (flatten)\n"
            "matrix = [[1, 2], [3, 4], [5, 6]]\n"
            "flat = [num for row in matrix for num in row]\n"
            "# [1, 2, 3, 4, 5, 6]\n\n"
            "# Dict comprehension\n"
            "word_lengths = {w: len(w) for w in words}\n"
            "# {'hello': 5, 'world': 5}\n\n"
            "# Set comprehension\n"
            "unique_lengths = {len(w) for w in ['hi', 'hey', 'yo']}\n"
            "# {2, 3}\n\n"
            "# Generator expression (lazy evaluation)\n"
            "total = sum(x**2 for x in range(1000000))  # memory efficient"
        ),
        "tips": [
            "Don't over-use comprehensions — readability matters!",
            "Use generator expressions for large data to save memory.",
            "You can nest comprehensions, but keep it to 2 levels max.",
        ],
        "keywords": ["comprehension", "list comprehension",
                      "dict comprehension", "set comprehension",
                      "generator", "generator expression"],
    },

    "decorators": {
        "title": "Decorators",
        "explanation": (
            "Decorators modify or extend the behavior of functions/methods "
            "without changing their source code.\n\n"
            "A decorator is a function that takes a function as input and "
            "returns a new function.\n\n"
            "Common built-in decorators:\n"
            "  • @staticmethod\n"
            "  • @classmethod\n"
            "  • @property\n"
            "  • @functools.lru_cache"
        ),
        "code_example": (
            "import functools\n"
            "import time\n\n"
            "# Basic decorator\n"
            "def timer(func):\n"
            "    @functools.wraps(func)\n"
            "    def wrapper(*args, **kwargs):\n"
            "        start = time.time()\n"
            "        result = func(*args, **kwargs)\n"
            "        end = time.time()\n"
            "        print(f'{func.__name__} ran in {end-start:.4f}s')\n"
            "        return result\n"
            "    return wrapper\n\n"
            "@timer\n"
            "def slow_function():\n"
            "    time.sleep(1)\n"
            "    return 'Done'\n\n"
            "slow_function()  # 'slow_function ran in 1.00xxs'\n\n"
            "# Decorator with arguments\n"
            "def repeat(n):\n"
            "    def decorator(func):\n"
            "        @functools.wraps(func)\n"
            "        def wrapper(*args, **kwargs):\n"
            "            for _ in range(n):\n"
            "                result = func(*args, **kwargs)\n"
            "            return result\n"
            "        return wrapper\n"
            "    return decorator\n\n"
            "@repeat(3)\n"
            "def say_hello():\n"
            "    print('Hello!')\n\n"
            "say_hello()  # Prints 'Hello!' three times"
        ),
        "tips": [
            "Always use @functools.wraps to preserve the original function metadata.",
            "Decorators are applied bottom-up when stacked.",
            "Use decorators for logging, timing, authentication, caching.",
        ],
        "keywords": ["decorator", "decorators", "wrapper", "wraps",
                      "functools", "@", "closure", "higher-order"],
    },
}

# ── Quick Reference Helpers ─────────────────────────────────────────

BEGINNER_ROADMAP = [
    "1. Variables & Data Types",
    "2. Strings",
    "3. Conditionals (if/elif/else)",
    "4. Loops (for & while)",
    "5. Lists",
    "6. Dictionaries",
    "7. Functions",
    "8. Error Handling",
    "9. File Handling",
    "10. Modules & Imports",
    "11. Comprehensions",
    "12. Classes & OOP",
    "13. Decorators",
]

COMMON_ERRORS = {
    "syntaxerror": (
        "SyntaxError means Python can't understand your code.\n"
        "Common causes: missing colons, unmatched parentheses, "
        "incorrect indentation, misspelled keywords."
    ),
    "indentationerror": (
        "IndentationError means your code has inconsistent indentation.\n"
        "Fix: use 4 spaces per indentation level (no tabs)."
    ),
    "nameerror": (
        "NameError means you're using a variable that hasn't been defined.\n"
        "Check for typos or make sure you defined it before using it."
    ),
    "typeerror": (
        "TypeError means you're using the wrong type for an operation.\n"
        "Example: '2' + 2  (can't add string and int).\n"
        "Fix: convert types with int(), str(), float()."
    ),
    "indexerror": (
        "IndexError means you're accessing a list index that doesn't exist.\n"
        "Remember: a list of length n has indices 0 to n-1."
    ),
    "keyerror": (
        "KeyError means you're accessing a dictionary key that doesn't exist.\n"
        "Fix: use dict.get(key, default) or check with 'if key in dict:'."
    ),
    "valueerror": (
        "ValueError means a function received an argument of the right type "
        "but an inappropriate value.\n"
        "Example: int('hello') raises ValueError."
    ),
    "attributeerror": (
        "AttributeError means you're trying to use a method/attribute that "
        "doesn't exist on that object.\n"
        "Check spelling and the object's type with type(obj)."
    ),
    "importerror": (
        "ImportError/ModuleNotFoundError means Python can't find the module.\n"
        "Fix: install it with pip install module_name or check the name."
    ),
}

CHEAT_SHEET = """
╔══════════════════════════════════════════════════════════════╗
║                  🐍 PYTHON QUICK CHEAT SHEET                ║
╠══════════════════════════════════════════════════════════════╣
║ VARIABLES         x = 10;  name = "Alice"                   ║
║ PRINT             print(f"Hello {name}")                     ║
║ INPUT             x = input("Enter: ")                       ║
║ TYPE CHECK        type(x), isinstance(x, int)                ║
║ LIST              [1,2,3];  .append() .pop() .sort()         ║
║ DICT              {"a":1};  .get() .items() .keys()          ║
║ TUPLE             (1,2,3)   — immutable                      ║
║ SET               {1,2,3};  .add() .union() .intersection()  ║
║ IF                if x > 0: ... elif: ... else: ...          ║
║ FOR               for i in range(10):                        ║
║ WHILE             while x > 0:                               ║
║ FUNCTION          def func(a, b=1): return a + b             ║
║ LAMBDA            f = lambda x: x * 2                        ║
║ CLASS             class Dog: def __init__(self):              ║
║ TRY/EXCEPT        try: ... except Error as e: ...            ║
║ FILE              with open("f.txt") as f: f.read()          ║
║ IMPORT            import os;  from math import sqrt          ║
║ COMPREHENSION     [x**2 for x in range(10) if x%2==0]       ║
╚══════════════════════════════════════════════════════════════╝
"""


def find_topic(query: str) -> dict | None:
    """Search knowledge base for a matching topic."""
    query_lower = query.lower()
    best_match = None
    best_score = 0

    for key, topic in TOPICS.items():
        score = 0
        # Check direct key match
        if key in query_lower:
            score += 10
        # Check keyword matches
        for keyword in topic["keywords"]:
            if keyword in query_lower:
                score += 3
        # Check title match
        if topic["title"].lower() in query_lower:
            score += 8

        if score > best_score:
            best_score = score
            best_match = topic

    return best_match if best_score >= 3 else None


def find_error_help(query: str) -> str | None:
    """Check if user is asking about a common error."""
    query_lower = query.lower().replace(" ", "")
    for error_key, explanation in COMMON_ERRORS.items():
        if error_key in query_lower:
            return explanation
    return None


def get_all_topic_names() -> list[str]:
    """Return a list of all available topic names."""
    return [topic["title"] for topic in TOPICS.values()]