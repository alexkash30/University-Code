/***********************************************
Author: Alex Kashian
Date: 11/28
Purpose: working with Exceptions 
Sources of Help: 
Time Spent: 3 hrs 
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
Date: 11/28
Name: Alex Kashian
*/
#include<iostream>

using namespace std;

class OutOfRange{

public:
    string str;
    int x;
    OutOfRange(){
        str = "";
        x = 0;
    }

    OutOfRange(string s, int e){
        str = s;
        x = e;
    }

public:

    void err(){
        cout << endl << str << "Index value = " << x << endl;
    }

};

void testPFArrayD(void);

void testException(void);

//Objects of this class are partially filled arrays of doubles.

class PFArrayD{

public:

    PFArrayD(){
        capacity = 50;
        used = 0;
        arr = new double[50];
    }

    PFArrayD(int capacityValue){
        capacity = capacityValue;
        used = 0;
        arr = new double[capacityValue];
    }

    PFArrayD(const PFArrayD& pfaObject){
        capacity = pfaObject.capacity;
        arr = new double[capacity];
        double* p = arr + capacity;
        double* q = q + pfaObject.capacity;
        while (p > arr) {
            *--p = *--q;
        }
    }

    void addElement(double element){

        if (capacity == used) {
            throw OutOfRange("array is ful!!", capacity + 1);
        }
        *(arr + used) = element;
        used++;
    }

    bool full() const { return (capacity == used); }

    //Returns true if the array is full, false otherwise.

    int getCapacity() const { return capacity; }

    int getNumberUsed() const { return used; }

    void emptyArray() { used = 0; }

    //Empties the array.

    double& operator[](int index){

        if (index < 0 || index > used) {
            throw OutOfRange("Out of Range", index);
        }

        return arr[index];
    }

    PFArrayD& operator =(const PFArrayD& rightSide){

        if (arr != rightSide.arr){
            delete[] arr;
            capacity = rightSide.capacity;
            arr = new double[capacity];
            used = rightSide.used;
            double* p = arr + capacity;
            double* q = q + rightSide.capacity;
            while (p > arr) {
                *--p = *--q;
            }
        }
        return *this;
    }
    ~PFArrayD(){
    delete[] arr;
    }
private:
    double* arr; //for an array of doubles.
    int capacity; //for the size of the array.
    int used; //for the number of array positions currently in use.
};

int main(int argc, char* argv[]){
    cout << "This program tests the class PFArrayD.\n";
    char ans;
    do{
        testPFArrayD();
        testException();
        cout << "Test again? (y/n) ";
        cin >> ans;
    } while ((ans == 'y') || (ans == 'Y'));

    return 0;
}

void testPFArrayD()
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);

    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";

    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full()))
    {
        temp.addElement(next);
        cin >> next;
    }

    cout << "You entered the following "
    << temp.getNumberUsed() << " numbers:\n";
    int index;
    int count = temp.getNumberUsed();
    for (index = 0; index < count; index++) {
        cout << temp[index] << " ";
    }
    cout << endl;
    cout << "(plus a sentinel value.)\n";
}

void testException(){
    cout << "\nTesting Exception....\n";
    int cap, ele;
    cout << "Enter capacity: ";
    cin >> cap;
    PFArrayD temp(cap);
    try {
        cout << "Enter elements or -1 to stop: \n";
        cin >> ele;
        while (ele != -1) {
            temp.addElement(ele);
            cin >> ele;
        }
    }
    catch (OutOfRange e) {
        e.err();
    }

    cout << "You entered the following "

    << temp.getNumberUsed() << " numbers:\n";
    int index;
    int count = temp.getNumberUsed();
    for (index = 0; index < count; index++) {
        cout << temp[index] << " ";
    }
    cout << endl;
}
