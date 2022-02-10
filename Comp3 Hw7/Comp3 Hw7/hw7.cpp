/***********************************************
Author: Alex Kashian
Date: 11/2
Purpose:use maps to read ratings and store them by name and rating
Sources of Help: googled somethings to help me convert stings to ints and the standard libraies involved 
Also asked a classmate for advice on how to fix it.
Time Spent: 4 hours
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
Date:11/2
Name:Alex Kashian
*/
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <iomanip>
#include <cstdlib>



using namespace std;

int main(int argc, char* argv[]) {
    map<string, map<string, int> > ratings;
    ifstream input;
    string inputString, num, movie;

    input.open("movies.txt"); //open file
    string first;
    //check if file open
    if (input.fail()) {
        exit(1);

    }

        getline(input, num); 
        int numReviews = stoi(num.c_str()); 
        for (int i = 0; i < numReviews; ++i) {
            getline(input, movie); 
            getline(input, num);
            int rating = stoi(num.c_str()); 
            //check to see if the movie already exists
            if (ratings.find(movie) != ratings.end()) { 
                ratings[movie]["numReviews"]++; 
                ratings[movie]["totalRatings"] += rating; 
            }
            else {
                ratings[movie]["numReviews"] = 1; 
                ratings[movie]["totalRatings"] = rating; 
            }
        }

        map<string,int>::iterator p; 
    for (auto p = ratings.begin(); p != ratings.end(); ++p) { 
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(1); 
        double avg = p->second["totalRatings"] / (double)p->second["numReviews"]; 
        cout << p->first << ": " << p->second["numReviews"] << " review(s), Average of " << avg << " / 5" << endl; 
    }

    return 0;
}