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
Date:11/17
Name:Alex Kashian
*/
/***********************************************
Author: Alex Kashian
Date: 11/17
Purpose: Use virtucal classes
Sources of Help: none
Time Spent: 3 hrs
***********************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
using namespace std;

//Player Class
class Player {
public:

    //constuctor
    Player(string name) : name(name), wins(0) {}
    //Get Guess Func
    virtual int getGuess(int max, int min) { return 0; }
    //getters and setters
    int getWins() { return wins; }
    string getName() { return name; }
    void setName(string newName) { name = newName; }
    void setWins(int newWin) { wins = newWin; }
    //update vals
    virtual void updateValues(int guess, int winVal) {}
private:
    string name;
    int wins;
};

class HumanPlayer : public Player {
public:
    //constuctor
    HumanPlayer(string name) : Player(name) {}

    //Get Guess Function 
    int getGuess(int max, int min)override {
        int input;
        cout << "Enter your guess [0 - 99]: ";
        cin >> input;
        return input;
    }
};

class ComputerPlayer : public Player {
public:
    //constuctor
    ComputerPlayer(string name) : Player(name), lowVal(0), highVal(100) {}

    int getGuess(void) {    
        return ((rand() % (highVal - lowVal + 1)) + lowVal);
    }
    void updateValues(int guess, int winVal) {
        if (winVal == 1) {
            highVal = guess - 1;
        }
        else if (winVal == -1) {
            lowVal = guess + 1;
        }
        else {
            return;
        }
    }
private:
    int lowVal;
    int highVal;
};

bool checkForWin(int guess, int answer, int guessNumber) {
    cout << "Guess no. " << guessNumber << ", you guessed " << guess << ". ";
    if (answer == guess) {
        cout << "You're right! You win!" << endl;
        return true;
    }
    else if (answer < guess) {
        cout << "Your guess is too high." << endl;
    }
    else {
        cout << "Your guess is too low." << endl;
    }
    return false;
}

void play(Player& player1, Player& player2) {
    srand(time(nullptr));
    int answer = 0, guess = 0, guessNumber = 0;
    answer = rand() % 100;
    bool win = false;
    int max = 100;
    int min = 0;
    while (!win) {
        cout << "Player 1's turn to guess." << endl;
        guess = player1.getGuess(max, min);
        guessNumber++;
        win = checkForWin(guess, answer, guessNumber);

        if (win) {
            player1.setWins(player1.getWins() + 1);
            return;
        }
        cout << "Player 2's turn to guess." << endl;
        guess = player2.getGuess(max, min);
        guessNumber++;
        win = checkForWin(guess, answer, guessNumber);
        if (win) {
            player2.setWins(player2.getWins() + 1);
        }
    }
    player1.updateValues(guess, win);
    player2.updateValues(guess, win);
}

int main() {
    HumanPlayer human1("Human player 1"), human2("Human player 2");
    ComputerPlayer computer1("Computer player 1"), computer2("Computer player 2");

    cout << "Select the game type (1-3) from the menu" << endl
        << "1. Human vs. Human" << endl
        << "2. Human vs. Computer" << endl
        << "3. Computer vs. Computer" << endl
        << "Anything else will end the game." << endl;

    int input = 0;
    cin >> input;
    while (input < 4 && input > 0)
    {
        if (input == 1)
        {
            play(human1, human2);
        }
        else if (input == 2)
        {
            play(human1, computer1);
        }
        else
        {
            play(computer1, computer2);
        }
        cout << "\nSelect the game type (1-3) from the menu, any other number to quit" << endl
            << "1. Human vs. Human" << endl
            << "2. Human vs. Computer" << endl
            << "3. Computer vs. Computer" << endl;
        cin >> input;

    }

    cout << "\nTHANKS FOR PLAYING!!!" << endl;

    return 0;

}