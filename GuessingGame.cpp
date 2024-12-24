#include<iostream>
#include<cstdlib>
#include "time.h"
using namespace std;

int main(){

    cout << "Welcome to the guessing game!\n" << endl;
    cout << "Here, you will try to guess a number between 0 and 100." << endl;
    cout << "The program will tell you if your guess is too small or too big." << endl;
    cout << "Good luck!\n" << endl;
	/* Providing a seed value (needs to be different
    every time for different numbers each time you run the program).
    This is why we use time as the seed value, because time is
    always changing.*/
	srand((unsigned) time(NULL));

    // Retrieve a random number between 100 and 200
    int secretNum = 0 + (rand() % 101); // Starting point = 0, Ending point = 101
    int guess;
    int guessCount = 0;
    int guessLimit = 10;
    bool outOfGuesses;

    while (secretNum != guess && !outOfGuesses){
        if (guessCount < guessLimit){
            cout << "Enter guess: ";
            cin >> guess;
            if (secretNum > guess){
                cout << "Your guess was too small." << endl;
            } else if (secretNum < guess){
                cout << "Your guess was too big." << endl;
            }
            cout << "You have " << guessLimit - guessCount - 1 << " guesses left." << endl;
            guessCount++;
        } else {
            outOfGuesses = true;
        }
    }

    if (outOfGuesses){
        cout << "You lose... " << endl;
        cout << "The secret number was " << secretNum << "." << endl;
    } else {
        cout << "You win!" << endl;
    }


	return 1;
}
