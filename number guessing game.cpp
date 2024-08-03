#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    int targetNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    bool guessedCorrectly = false;
    
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;
    
    while (!guessedCorrectly) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        
        if (guess < targetNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > targetNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the number in " << attempts << " attempts." << endl;
            guessedCorrectly = true;
        }
    }

    return 0;
}
