//COMMENTS REPRESENT THE CODE IN C 
//THE CODE REPRESENTS THE CODE IN C++

//#include <stdio.h>
#include <iostream>
//#include <stdlib.h>
#include <cstdlib>
//#include <time.h>
#include <ctime>

//Defining Constants
//In C its #define (varialbe name)
const int MAX_NUM_DICE = 5;

//This allows you to change your output lines from std::cout to just cout
using namespace std;

int main(int argc, const char* argv[]) {
    //Declaring varialbes is the same
    int numDice;
    int* diceVals;
    int sum = 0;
    double avg;
    //printf("Please enter the total number of dice you would like to role(2-5 dice): ");
    std::cout << "Please enter the total number of dice you would like to role(2 - 5 dice):";

    //scanf("%d", &numDice);
    std::cin >> numDice;

    diceVals = (int*)malloc(numDice * sizeof(int));

    //srand((unsigned int)time(0));
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < numDice; i++) {
        diceVals[i] = (rand() % 6 )+ 1;

        //printf("Dice Value %d is: %d\n", i+1 ,diceVals[i]);
        std::cout << "Dice Value" << i + 1 << "is :" << diceVals[i] << std::endl;

    }    
    for (int j = 0; j < numDice; j++) {
        sum += diceVals[j];
    }
    
    //avg = (double)sum / numDice;
    avg = static_cast<double>(sum) / numDice;

    printf("The sum of the dice values is: %d\n", sum);
    printf("The Average of the dice values is %lf\n", avg);

    return 0;
}