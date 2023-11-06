#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int DIGITS = 4; 

string generateRandomNumber() {
    string number;
    char digit;
    int randomNumber;

   
    for (int i = 0; i < DIGITS; i++) {
        do {
            randomNumber = rand() % 10; 
            digit = randomNumber + '0'; 
        } while (number.find(digit) != string::npos);

        number += digit;
    }

    return number;
}

int countBulls(const string& secret, const string& guess) {
    int bulls = 0;
    for (int i = 0; i < DIGITS; i++) {
        if (secret[i] == guess[i]) {
            bulls++;
        }
    }
    return bulls;
}

int countCows(const string& secret, const string& guess) {
    int cows = 0;
    for (int i = 0; i < DIGITS; i++) {
        for (int j = 0; j < DIGITS; j++) {
            if (i != j && secret[i] == guess[j]) {
                cows++;
            }
        }
    }
    return cows;
}

void playGame(const string& secret, int attempts) {
    string guess;
    cout << "Enter your guess (" << DIGITS << " digits): ";
    cin >> guess;

    if (guess.length() != DIGITS) {
        cout << "Enter exactly " << DIGITS << " digits." << endl;
        playGame(secret, attempts);
        return;
    }

    int bulls = countBulls(secret, guess);
    int cows = countCows(secret, guess);

    cout << "Bulls: " << bulls << ", Cows: " << cows << endl;

    if (bulls == DIGITS) {
        cout << "Congratulations! You've guessed the secret number: " << secret << endl;
        cout << "Number of attempts: " << attempts << endl;
    }
    else {
        playGame(secret, attempts + 1);
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    string secretNumber = generateRandomNumber();

    cout << "Welcome to the 'Bulls and Cows' game!" << endl;
    cout << "Try to guess the four-digit number. Repeating digits are not allowed." << endl;

    playGame(secretNumber, 1);

    return 0;
}