/***********************************************
Author:Alex Kashian
Date: 11/10
Purpose: use inheritance for trucks and vechiles 
Sources of Help: None
Time Spent:2.5 hrs 
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
Date: 11/17
Name: Alex Kashian
*/
#include <iostream>
#include <string>
using namespace std;

class Person{
public:
	Person() : name("Unknown Owner") {}
	Person(string theName) : name(theName) {}
	Person(const Person& theObject) : name(theObject.name) {}
	string getName() const { return name; }
	Person& operator=(const Person& rtSide) {
		this->name = rtSide.name;
		return *this;
	}
	friend istream& operator >>(istream& inStream, Person& personObject) {
		inStream >> personObject.name;
		return inStream;
	}
	friend ostream& operator <<(ostream& outStream, const Person& pObject) {
		outStream << pObject.name;
		return outStream;
	}
private:
	string name;
};

class Vehicle{
public:
	Vehicle() : manufacturerName("Unknown Manufactory"), numCylinders(0), owner(Person()) {}

	Vehicle(const string& ManufacturerName, int NumCylinders, const Person& Owner) : 
	manufacturerName(ManufacturerName), numCylinders(NumCylinders), owner(Owner) {}

	Vehicle(const Vehicle& vObject) :
	manufacturerName(vObject.manufacturerName), numCylinders(vObject.numCylinders), owner(vObject.owner) {}
	Vehicle& operator=(const Vehicle& otherObject) {
		manufacturerName = otherObject.manufacturerName;
		numCylinders = otherObject.numCylinders;
		owner = otherObject.owner;

		return *this;
	}
	string getManufacturerName() { return manufacturerName; }
	int getNumCylinders() { return numCylinders; }
	Person getOwner() { return owner; }
	void setManufacturerName(const string& newManufacturerName) {manufacturerName = newManufacturerName; }
	void setNumCylinders(int newNumberOfCylinders) { numCylinders = newNumberOfCylinders; }
	void setOwner(const Person& newOwner) { owner = newOwner; }

	friend ostream& operator <<(ostream& outStream, const Vehicle& vObject) {
		outStream << vObject.manufacturerName;
		outStream << vObject.numCylinders;
		outStream << vObject.owner;
		return outStream;
	}
	void print() {
		cout << "Owner: " << owner << endl;
		cout << "Manufacturer's name: " << manufacturerName << endl;
		cout << "Number of cylinders in the engine: " << numCylinders << endl;
	}

private:
	string manufacturerName;
	int numCylinders;
	Person owner;
};

class Truck : public Vehicle{
public:
	Truck() : Vehicle(), loadCapacity(0), towingCapacity(0) {}

	Truck(string ManufacturerName, int newNumberOfCylinders, const Person& nOwner, double LoadCapacity, int TowingCapacity) :
	Vehicle(ManufacturerName, newNumberOfCylinders, nOwner), loadCapacity(LoadCapacity), towingCapacity(TowingCapacity) {}

	Truck(const Truck& otherObject) :
	Vehicle(otherObject), loadCapacity(otherObject.loadCapacity), towingCapacity(otherObject.towingCapacity) {}

	Truck& operator=(const Truck& otherObject) {
		Vehicle:: operator =(otherObject);
		loadCapacity = otherObject.loadCapacity;
		towingCapacity = otherObject.towingCapacity;
	return *this;
	}
	double getLoadCapacity() { return loadCapacity;}

	int getTowingCapacity() { return towingCapacity;}

	void setLoadCapacity(double newLoadCapacity) {loadCapacity = newLoadCapacity;}

	void setTowingCapacity(int newTowingCapacity) { towingCapacity = newTowingCapacity; }

	friend ostream& operator <<(ostream& outStream, const Truck& tObject) {
		outStream << tObject.loadCapacity;
		outStream << tObject.towingCapacity;
		return outStream;
	}

	void print() {
		Vehicle::print();
		cout << "Load capacity in tons: " << loadCapacity << endl;
		cout << "Towing capacity in pounds: " << towingCapacity << endl;
	}

private:
	double loadCapacity;
	int towingCapacity;
};

int main()
{
	cout << "///////////////// Testing Person Class ////////////////" << endl;
	Person person1, person2, person3;
	cout << "TESTING PERSON CLASS" << endl;
	cout << "Testing default const: the person is " << person1 << endl;
	Person kash("Alex Kashian");
	cout << "Testing const.(string): I am: " << kash << endl;
	Person copy(kash);
	cout << "Testing copy constructor: another me is: " << copy << endl;
	cout << "Testing >> overloading: Enter your name: ";
	cin >> person2;
	cout << "You're: " << person2 << endl;
	person3 = person2;
	cout << "Testing = overloading: Another you is: " << person3 << endl;

	cout << "\n///////////////// Testing Vehicle Class ////////////////" << endl;
	Vehicle vehicleDefault;
	cout << "Testing default constructor: the Vehicle is:" << endl;
	vehicleDefault.print();

	Person p1("Alex Kashian");

	Vehicle vehicle1("Honda", 3, p1);
	Vehicle vehicle2(vehicle1);
	Vehicle vehicle3 = vehicle2;

	cout << "\nTesting constructor(args): for my car:" << endl;
	vehicle1.print();

	cout << "\nTesting copy constructor: my second same car:" << endl;
	vehicle2.print();

	cout << "\nTesting = overloading:" << endl;
	vehicle3.print();
	
	
	cout << "\n///////////////// Testing Truck Class ////////////////" << endl;
	Truck truckDefault;
	cout << "Testing default constructor: the Truck is :" << endl;
	truckDefault.print();

	Truck truck1("Chevy Silverado ", 6, p1, 30, 5500);
	Truck truck2(truck1);
	Truck truck3 = truck2;

	cout << "\nTesting constructor(args): for a truck" << endl;
	truck1.print();

	cout << "\nTesting copy constructor: copied truck:" << endl;
	truck2.print();

	cout << "\nTesting = overloading:" << endl;
	truck3.print();

	return 0;
}