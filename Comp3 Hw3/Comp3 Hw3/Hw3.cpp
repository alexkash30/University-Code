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
 Date: 9/21
 Purpose: Use a class to make it easier to set, move, and rotate a point.
 Sources of Help: None
 Time Spent: 45 mins
 ***********************************************/
#include <iostream>

using namespace std;

//class Point definition
class Point {
private:
    double x, y;
public:
    //default constructor
    Point();
    //2 parameter constructor
    Point(double, double);
    //setters
    void setX(double);
    void setY(double);
    //getters
    double getX()const;
    double getY()const;


    void movePoint(double, double);//moves the point
    void rotate90();//rotates point clockwise

};

//default constructor
Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(double X, double Y) {//2 parameter constructor , sets x,y to X,Y
    x = X;
    y = Y;
}

void Point::setX(double X) {
    x = X;
}
void Point::setY(double Y) {
    y = Y;
}

double Point::getX()const {
    return x;
}

double Point::getY()const {
    return y;
}

void Point::movePoint(double dX, double dY) {
    x += dX;
    y += dY;
}

void Point::rotate90() {//rotate 90 clockwise 
    double temp = x; //temp holds value of x while swapping x and y
    x = y;
    y = -temp;

}

int main(int argc, const char* argv[]) {

    Point p1, p2, p3;

    p1.setX(1);
    p1.setX(2);

    cout << "Point P1: (" << p1.getX() << "," << p1.getY() << ")"<< endl;

    for (int i = 0; i < 4; i++)

    {

        p1.rotate90();

        cout << "After rotation number " << (i + 1) << ": (" << p1.getX() << "," << p1.getY() << ")" << endl;

    }

    p2.setX(3);
    p2.setY(4);

    cout << "Point P2: (" << p2.getX() << "," << p2.getY() << ")" << endl;

    p2.movePoint(1, 1);

    cout << "After moving by (1,1) , P2 : (" << p2.getX() << "," << p2.getY() << ")" << endl;

    p3.setX(5);
    p3.setY(-4);

    cout << "Point P3: (" << p3.getX() << "," << p3.getY() << ")" << endl;

    p3.movePoint(-5, 4);

    cout << "After moving by (-5,4) , P3 : (" << p3.getX() << "," << p3.getY() << ")" << endl;

    return 0;
}