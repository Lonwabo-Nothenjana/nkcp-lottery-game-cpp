# nkcp-lottery-game-cpp

📌 Project Title

NKCP Lottery Game (C++)

🧠 Project Overview

The NKCP Lottery Game is a console-based C++ application that simulates a simplified lottery system.
Users can choose between different lottery modes, guess numbers, and win virtual prizes based on how many correct matches they achieve. The program also allows users to submit ratings, which are persisted to a file.

This project focuses on core C++ programming concepts, user input validation, file handling, and clean modular design.

✨ Features

🎲 Three Lottery Game Modes

Guess 1 number (0–9)

Guess 3 unique numbers (0–49)

Guess 5 unique numbers (0–99)

🧮 Random Number Generation

Ensures uniqueness where required

Uses time-based random seed

✅ Robust Input Validation

Prevents invalid or out-of-range inputs

Handles incorrect user entries gracefully

⭐ User Rating System

Collects name, country, and star rating (1–5)

Saves data persistently to a file (ratings.txt)

🧩 Modular Design

Clear separation of concerns using functions

Readable and maintainable code structure

🛠️ Technologies Used

Language: C++

Concepts Applied:

Functions & modular programming

Arrays and loops

Input validation

File I/O (fstream)

Random number generation

Control flow (switch, do-while)

▶️ How to Run

Clone the repository:

git clone https://github.com/Lonwabo-Nothenjana/NKCP-Lottery-Game.git


Compile the program:

g++ main.cpp -o lottery


Run:

./lottery

📂 File Structure
📁 NKCP-Lottery-Game
 ├── main.cpp
 ├── ratings.txt   (generated after user ratings)
 └── README.md

🚀 Learning Outcomes

Through this project, I strengthened my understanding of:

C++ fundamentals and best practices

Writing defensive code with validation

Designing small but complete real-world programs

Handling user interaction in console applications

Persisting data using files

🔮 Possible Improvements (Future Work)

Add partial rewards for matching some numbers

Store game history per user

Use object-oriented design (classes)

Improve UI with better formatting

Add probability statistics for each game mode

👤 Author

Lonwabo Nothenjana
Aspiring AI Engineer & Software Developer
📧 Email: liodenothenjana@gmail.com

🔗 GitHub: Lonwabo-Nothenjana
