# Word Guess Game **(C)**

A simple terminal-based word guessing game written in C.

> **Note:** The game interface and questions are in **Portuguese (Brazil)**.


## About the project

This is an interactive quiz-style game where the player must guess a word based on hints. The game includes a scoring system, time limit, and a local ranking saved to a file.


## Features

**.** Random word selection
**.** Hint system (up to 3 hints per word)
**.** Score system based on hints used
**.** 30-second timer for each round
**.** Accent-insensitive input (handles words with/without accents)
**.** Ranking system saved in a `.txt` file
**.** Replay option after each round


## How to play

**1.** Run the program
**2.** Enter your name
**3.** Read the first hint
**4.** Type your answer or type `dica` to receive another hint
**5.** Try to guess the word before time runs out!


## Scoring system

No hints used → **5 points**
One hint used → **4 points**
Two hints used → **3 points**


## How to compile and run

### Using GCC:

```bash
gcc main.c -o game
./game


### On Windows:

gcc main.c -o game
game


## Files

"main.c" → Main game source code
"ranking.txt" → Stores top player scores (auto-generated)


## Requirements

**.** C compiler (GCC recommended)
**.** Terminal / Command Prompt

## Author

Developed as a learning project in C programming.
