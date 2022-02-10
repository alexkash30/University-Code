/***********************************************
Author: Alex Kashian
Date: 9/14
Purpose: play a guessing game with the computure after giving a specific range and number of guesses
Sources of Help: NONE
Time Spent: 1.5 hour
***********************************************/

/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: 9/14 
Name: Alex Kashian
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRand(int min, int max);
int getMin(void);
int getMax(int min);
int getGuesses(void);

int main(int argc, const char* argv[]) {
    int minVal;
    int maxVal;
    int numGuesses;
    int randVal;
    int userGuess;
    char playAgain = 'n';
    cout << "First, let's set up the game." << endl;
    
    minVal = getMin();
    maxVal = getMax(minVal);
    numGuesses = getGuesses();

    do {
        //temp holder for the number of guesses 
        int i = numGuesses;
        //Call generateRand
        randVal = generateRand(minVal, maxVal);
        
        while (numGuesses > 0) {
            cin >> userGuess;
            //Guess is to high if
            if (userGuess > randVal) {
                cout << "Too high! Try again" << endl;
                numGuesses--;
            }
            //Guess is to low if
            else if (userGuess < randVal) {
                cout << "Too low! Try again" << endl;
                numGuesses--;
            }
            //They guessed it correctly
            else {
                cout << "Excillent! You guessed the right number" << endl;
                numGuesses = 0;
            }

        }
        //Reset the amount of guesses if the user wants to play again
        numGuesses = i;
        cout << "Would you like to play again(y/n)?";
        cin >> playAgain;
    } while (playAgain == 'y');

    return 0;
}

//Function that generates the random value for the user to guess
int generateRand(int min, int max) {
    cout << "Now, I have a number between " << min << " and " << max << ". Can you guess my number? please type your first guess now." << endl;
    srand(static_cast<unsigned>(time(0)));
    return (min + (rand() % (max - min)));
}

//Function that asks for the min value
int getMin(void) {
    int min;
    cout << "Please enter the minimum number, a positive integer: " << endl;
    cin >> min;
    while (min <= 0) {
        cout << "Please enter the minimum number, a positive integer: " << endl;
        cin >> min;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return min;
}
//Function that asks for the max value
int getMax(int min) {
    int max;
    cout << "Please enter the maximum number, a positive integer: " << endl;
    cin >> max;
    while (max < min || max > 1000) {
        cout << "Please enter the maximum number, a positive integer: " << endl;
        cin >> max;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return max;
}
//Function that asks for the number of guesses
int getGuesses(void) {
    int guesses;
    cout << "Please enter the number of guesses allowed(less then 10):" << endl;
    cin >> guesses;
    while (guesses > 10) {
        cout << "Please enter the number of guesses allowed(less then 10):" << endl;
        cin >> guesses;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return guesses;
}