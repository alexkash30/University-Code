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
Date:11/1
Name:Alex Kashian
*/

 /***********************************************
 Author: Alex Kashian
 Date:10/19
 Purpose: use a class to manage a dynamic string array 
 Sources of Help: NONE
 Time Spent: 2 hours
 ***********************************************/
#include <iostream>
#include <string>
using namespace std;


class DynamicStringArray {
public:
	DynamicStringArray() :dynamicArray(nullptr), size(0) {}
	int getSize(void) const { return size; }
	void addEntry(string input);
	bool deleteEntry(string input);
	string getEntry(const int index) const;
	DynamicStringArray(const DynamicStringArray& org);
	~DynamicStringArray();

private:
	std::string *dynamicArray;
	int size;

};

int main(int argc, const char* argv[]) {

}


void DynamicStringArray::addEntry(string input) {
	string* tempPtr = dynamicArray;

	//create a new array
	dynamicArray = new string[size + 1];
	dynamicArray[size].assign(input);
	//Copy the elements  
	for (int i = 0; i < size; i++) {
		dynamicArray[i] = tempPtr[i];
	}

	if (size > 0) {
		delete[] tempPtr;
	}
	size++;
}
bool DynamicStringArray::deleteEntry(string input) {
	bool found = false;
	//see if the string is in the array
	int i;
	for (i = 0; i < size; i++) {
		if (input == dynamicArray[i]) {
			found = true;
			break;
		}
	}
	if (found == true) {
		//need to copy all entries other than the 'i'th entry
		std::string* temp = dynamicArray;
		dynamicArray = new std::string[size - 1];
		for (int j = 0; j < size; j++) {
			if (j < i) {
				dynamicArray[j] = temp[j];
			}
			else if (j > i) {
				dynamicArray[j - 1] = temp[j];
			}
		}
		size--;
	}

	return found;
}

std::string DynamicStringArray::getEntry(const int index) const {
	if (index >= size) {
		return NULL;
	}
	else {
		return dynamicArray[index];
	}
}

//THE BIG THREE

//A copy constructor that makes a copy of the input object’s dynamic array.
DynamicStringArray::DynamicStringArray(const DynamicStringArray& org) {
	size = org.getSize();
	dynamicArray = new std::string[size];
	for (int i = 0; i < size; i++) {
		dynamicArray[i] = org.getEntry(i);
	}
}
//Destructor
DynamicStringArray::~DynamicStringArray() {
	if (dynamicArray != NULL) {
		delete[] dynamicArray;
	}

}