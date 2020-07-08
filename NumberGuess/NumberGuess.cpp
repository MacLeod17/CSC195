// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));
    int maxIntValue = 10;
    cout << "Enter Max Integer Value: ";
    cin >> maxIntValue;
    int answer = (rand() % maxIntValue) + 1;
    //cout << "Answer: " << answer << endl;

    int guess = 0;
    bool exitRequested = false;
    int maxGuesses = 5;
    int guessCount = 0;
    while (!exitRequested) {
        guess = 0;
        cout << "Enter guess: ";

        while (!(cin >> guess)) {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Error, try again\n";
        }
        while (guess < 1 || guess > maxIntValue) {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Error, try again\n";
            cin >> guess;
        }

        if (guess == answer) {
            cout << "Correct! " << answer << endl;
            cout << "Guesses taken: " << guessCount + 1 << endl;
            exitRequested = true;
        }
        else if (guess > answer) {
            cout << "Too high.\n";
            guessCount++;
        }
        else if (guess < answer) {
            cout << "Too low.\n";
            guessCount++;
        }
        if (guessCount >= maxGuesses) {
            exitRequested = true;
            cout << "You lost.\n";
            cout << "Answer: " << answer << endl;
        }
    }
    cout << "Would you like to play again?(Y/N)\n";
    string playAgain;
    cin >> playAgain;
    if (playAgain.compare("y") == 0 || playAgain.compare("Y") == 0) {
        main();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
