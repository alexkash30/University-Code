
/***********************************************
Author: Alex Kashian
Date:12/6
Purpose: reads strings from the standard input (keyboard),
generates all permutations of the strings, and then display the results to the standard output
Sources of Help:
Time Spent: 2hrs


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
Date:12/6
Name:Alex Kashian

***********************************************/

#include<iostream>
#include<list>
#include<sstream>
#include <algorithm>
using namespace std;

list<string> generate_permutations(list<string> inputList) {

    list<string> firstPremutation;
    string temp;

    //.sort sorts the list
    inputList.sort();
    //Gets the unique elements in the strings
    inputList.unique();

    do {
        temp = "";
        list<string>::iterator iterator;

        for (iterator = inputList.begin(); iterator != inputList.end(); ++iterator) {

            temp += iterator->c_str();
            temp += " ";

        }

        firstPremutation.push_back(temp);

    } while (next_permutation(inputList.begin(), inputList.end()));

    return firstPremutation;
}

void print_permutations(list<string> inputList) {

    cout << "Permutations are : " << endl;
    list<string>::iterator iterator2;
    int c = 1;
    for (iterator2 = inputList.begin(); iterator2 != inputList.end(); ++iterator2) {
        cout << c << ". " << iterator2->c_str() << endl;
        c++;
    }
}

int main(int argc, char* argv[])
{
    list<string> inputList;
    string aLine, aString;
    // read in strings from stdin
    cout << "Enter strings, separated by a space:";
    getline(cin, aLine); //read a line from keyboard
    istringstream iss(aLine); //convert aLine to an istringstream obj
    //parse each string
    while (iss >> aString)
    {
        inputList.push_back(aString);
    }

    auto permutations = generate_permutations(inputList);

    // print permutations to stdout
    print_permutations(permutations);

    return 0;
}