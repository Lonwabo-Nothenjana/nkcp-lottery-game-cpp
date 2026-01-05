// Lonwabo Nothenjana
// 56157533

/* NKCP Lottery Game
   Users can play three types of lottery games:
   1. Guess one number
   2. Guess three numbers
   3. Guess five numbers
   Users can win different amounts based on correct guesses.
   Users can also rate the game and save their rating with name and country.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes
void displayMenu();
void playOneNumberGame();
void playThreeNumberGame();
void playFiveNumberGame();
void rateUs();
int getValidatedInput(int min, int max);
bool contains(int arr[], int size, int value);
int countMatches(int userArr[], int userSize, int randomArr[], int randomSize);

int main() {
    srand(time(0)); // Initialize random seed once

    int choice;

    cout << "Welcome to NKCP Lottery!\n" << endl;

    do {
        displayMenu();
        choice = getValidatedInput(1, 5);

        switch (choice) {
            case 1:
                playOneNumberGame();
                break;
            case 2:
                playThreeNumberGame();
                break;
            case 3:
                playFiveNumberGame();
                break;
            case 4:
                rateUs();
                break;
            case 5:
                cout << "\nExiting the game. See you next time!\n" << endl;
                break;
            default:
                cout << "Invalid option! Please try again.\n" << endl;
        }

    } while (choice != 5);

    return 0;
}

// Display main menu
void displayMenu() {
    cout << "**** Pick one option ****" << endl;
    cout << "1. Guess one number" << endl;
    cout << "2. Guess three numbers" << endl;
    cout << "3. Guess five numbers" << endl;
    cout << "4. Rate us" << endl;
    cout << "5. Exit\n" << endl;
    cout << "Enter option: ";
}

// Input validation helper
int getValidatedInput(int min, int max) {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail() || input < min || input > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number between " << min << " and " << max << ": ";
        } else {
            break;
        }
    }
    return input;
}

// Check if value exists in array
bool contains(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return true;
    }
    return false;
}

// Count matching numbers
int countMatches(int userArr[], int userSize, int randomArr[], int randomSize) {
    int count = 0;
    for (int i = 0; i < userSize; i++) {
        if (contains(randomArr, randomSize, userArr[i])) count++;
    }
    return count;
}

// One number game
void playOneNumberGame() {
    const double WIN_AMOUNT = 100000.0;
    int randomNum = rand() % 10; // 0-9
    int guess;

    cout << "\n*** Guess One Number ***" << endl;
    cout << "Cost: R20 | Prize: R100,000" << endl;
    cout << "Enter your guess (0-9): ";

    guess = getValidatedInput(0, 9);

    cout << "Random number: " << randomNum << endl;

    if (guess == randomNum) {
        cout << "Congratulations! You won R" << fixed << setprecision(2) << WIN_AMOUNT << "!" << endl;
    } else {
        cout << "Sorry! Better luck next time." << endl;
    }

    cout << endl;
}

// Three number game
void playThreeNumberGame() {
    const double WIN_AMOUNT = 500000.0;
    int randomNums[3];
    int userNums[3];

    // Generate 3 unique random numbers (0-49)
    for (int i = 0; i < 3; i++) {
        int num;
        do {
            num = rand() % 50;
        } while (contains(randomNums, i, num));
        randomNums[i] = num;
    }

    cout << "\n*** Guess Three Numbers ***" << endl;
    cout << "Cost: R50 | Prize: R500,000" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Enter guess #" << i + 1 << " (0-49): ";
        userNums[i] = getValidatedInput(0, 49);
    }

    int matches = countMatches(userNums, 3, randomNums, 3);

    cout << "Random numbers: ";
    for (int i = 0; i < 3; i++) cout << randomNums[i] << " ";
    cout << endl;

    cout << "You matched " << matches << " number(s)." << endl;
    if (matches == 3) {
        cout << "Congratulations! You won R" << fixed << setprecision(2) << WIN_AMOUNT << "!" << endl;
    } else {
        cout << "Sorry! Better luck next time." << endl;
    }

    cout << endl;
}

// Five number game
void playFiveNumberGame() {
    const double WIN_AMOUNT = 1000000.0;
    int randomNums[5];
    int userNums[5];

    // Generate 5 unique random numbers (0-99)
    for (int i = 0; i < 5; i++) {
        int num;
        do {
            num = rand() % 100;
        } while (contains(randomNums, i, num));
        randomNums[i] = num;
    }

    cout << "\n*** Guess Five Numbers ***" << endl;
    cout << "Cost: R100 | Prize: R1,000,000" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Enter guess #" << i + 1 << " (0-99): ";
        userNums[i] = getValidatedInput(0, 99);
    }

    int matches = countMatches(userNums, 5, randomNums, 5);

    cout << "Random numbers: ";
    for (int i = 0; i < 5; i++) cout << randomNums[i] << " ";
    cout << endl;

    cout << "You matched " << matches << " number(s)." << endl;
    if (matches == 5) {
        cout << "Congratulations! You won R" << fixed << setprecision(2) << WIN_AMOUNT << "!" << endl;
    } else {
        cout << "Sorry! Better luck next time." << endl;
    }

    cout << endl;
}

// Rate us function
void rateUs() {
    string name, country;
    int rating;

    cout << "\n*** Rate NKCP Lottery ***" << endl;
    cin.ignore(); // Clear newline from previous input
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your country: ";
    getline(cin, country);
    cout << "Rate us (1-5 stars): ";
    rating = getValidatedInput(1, 5);

    ofstream outFile("ratings.txt", ios::app); // Append mode
    if (outFile.is_open()) {
        outFile << name << "|" << country << "|" << rating << endl;
        outFile.close();
        cout << "Thank you! Your rating has been saved.\n" << endl;
    } else {
        cout << "Error: Unable to save your rating.\n" << endl;
    }
}
