/*
 Computing I -- COMP.1010 Honor Statement

 The practice of good ethical behavior is essential for maintaining
 good order in the classroom, providing an enriching learning
 experience for students, and as training as a practicing computing
 professional upon graduation.  This practice is manifested in the
 University’s Academic Integrity policy. Students are expected to
 strictly avoid academic dishonesty and adhere to the Academic
 Integrity policy as outlined in the course catalog.  Violations
 will be dealt with as outlined therein.

 All programming assignments in this class are to be done by the
 student alone.  No outside help is permitted except the instructor
 and approved tutors.

 I certify that the work submitted with this assignment is mine and
 was generated in a manner consistent with this document, the
 course academic policy on the course website on Blackboard, and
 the UMass Lowell academic code.
 Date:10/5
 Name:Alex Kashian
 */

 /***********************************************
 Author: Alex Kashian
 Date: 10/5
 Purpose: using oporator overloading with rations
 Sources of Help: None
 Time Spent: 1.5 hours
 ***********************************************/

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int greatestCommonDenominator(int x, int y);

class Rational{
public:

    int num, den;

    //Set the deafault to zero 
    Rational() :num(0), den(1) {}

    Rational(int x, int y) {

        //Below sees if the Num and den are same if not changes the num to negative.
        if ((x > 0 && y < 0) || (x < 0 && y>0)) {

            x = -abs(x);

            y = abs(y);
        }

        int a = greatestCommonDenominator(abs(x), abs(y));

        num = x / a;
        den = y / a;

    }

    //Makes the x/1
    Rational(int x): num(x), den(1){}
        

    //Addition Operator
    Rational operator +(Rational const& x) {

        Rational rep;

        rep.num = num * x.den + x.num * den;
        rep.den = den * x.den;

        int denom = greatestCommonDenominator(abs(rep.num), abs(rep.den));

        rep.num = rep.num / denom;
        rep.den = rep.den / denom;

        return rep;

    }

    //Subtraction Operator
    Rational operator - (Rational const& x) {

        Rational rep;

        rep.num = num * x.den - x.num * den;
        rep.den = den * x.den;

        int denom = greatestCommonDenominator(abs(rep.num), abs(rep.den));

        rep.num = rep.num / denom;
        rep.den = rep.den / denom;

        return rep;
    }

    //Boolean Operator checks less
    bool operator < (Rational const& x) {
        return num * x.den < x.num* den;
    }

    //Boolean Operator checks less or equal
    bool operator <= (Rational const& x) {
        return num * x.den <= x.num * den;
    }

    //Boolean Operator checks greater
    bool operator > (Rational const& x) {
        bool answer = num * x.den > x.num * den;

        return answer;
    }

    //Boolean Operator checks greater or equal
    bool operator >= (Rational const& x) {
        return num * x.den >= x.num * den;
    }

    //Boolean Operator checks if they are equal
    bool operator == (Rational const& x) {
        return num * x.den == x.num * den;
    }

    Rational operator * (Rational const& x) {

        Rational rep;

        rep.num = num * x.num;
        rep.den = den * x.den;

        int denom = greatestCommonDenominator(abs(rep.num), abs(rep.den));

        rep.num = rep.num / denom;
        rep.den = rep.den / denom;

        return rep;

    }

    Rational operator / (Rational const& x) {

        Rational rep;

        rep.num = num * x.den;
        rep.den = den * x.num;

        if ((rep.num < 0 && rep.den>0) || (rep.num > 0 && rep.den < 0)) {

            rep.num = -abs(rep.num);
            rep.den = abs(rep.den);

        }

        int denom = greatestCommonDenominator(abs(rep.num), abs(rep.den));

        rep.num = rep.num / denom;
        rep.den = rep.den / denom;

        return rep;

    }
};

//This function returns the out put after change
ostream& operator << (ostream& out, const Rational& r)
{
    out << r.num << "/" << r.den;
    return out;
}

istream& operator >> (istream& inStream, Rational& rep) {

    string temp, num = "", den = "";
    int denom;
    cin >> temp;
    bool first = true;

    for (char const& c : temp) {

        //This seperates the first numerator and second numerator cause of the "/"
        if (first && c != '/') {

            num += c;

        }

        else if (first && c == '/') {

            first = false;

        }

        else {

            den += c;

        }
    }

    rep.num = stoi(num);
    rep.den = stoi(den);

    denom = greatestCommonDenominator(abs(rep.num), abs(rep.den));

    if ((num.at(0) == '-' && den.at(0) == '-') || (num.at(0) != '-' && den.at(0) != '-')) {
        rep.num = abs(rep.num) / denom;
        rep.den = abs(rep.den) / denom;
    }
    else
    {
        rep.num = -abs(rep.num) / denom;
        rep.den = abs(rep.den) / denom;
    }
    return inStream;
}

int main() {

    Rational Test1 = Rational();
    Rational Test2 = Rational(1, 2);
    Rational Test3 = Rational(3, 6);

    cout << "Rational Number Value(numerator/denominator): " << endl;
    cin >> Test1;

    cout << "Rational number one: " << endl << Test1 << endl;
    cout << "Rational number two: " << endl << Test2 << endl;
    cout << "Rational number three: " << endl << Test3 << endl;

    cout << "Rational one and two sum: " << endl;
    cout << (Test1 + Test2) << endl;

    cout << "Subracting first and second rational numbers" << endl;
    cout << Test1 - Test2 << endl;

    cout << "Rational one and three multiplied: " << endl;
    cout << (Test1 * Test3) << endl;

    cout << "Rational one and three divided: " << endl;
    cout << (Test1 / Test3) << endl;

    cout << "0 = False and 1 = True." << endl;

    cout << "Checks if Rational one is < two: " << endl;
    cout << (Test1 < Test2) << endl;

    cout << "Checks if Rational one is <= two:" << endl;
    cout << (Test1 <= Test2) << endl;

    cout << "Checks if Rational one is > two:" << endl;
    cout << (Test1 > Test2) << endl;

    cout << "Checks if Rational one is >= two:" << endl;
    cout << (Test1 >= Test2) << endl;

    cout << "Checks if Rational one is == three:" << endl;
    cout << (Test1 == Test3) << endl;

    return 0;
}

//Calculates the GCD
int greatestCommonDenominator(int x, int y)
{
    if (y == 0)
        return x;
    return greatestCommonDenominator(y, x % y);

}
