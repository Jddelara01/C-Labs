//John Darren De Lara - x00072126 LAB1B
/*Reference: https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm 
Reference: http://en.cppreference.com/w/cpp/language/abstract_class*/

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person {			

public:
	/*Person(string pName) {						// initialise the name
		name = pName;
	};	

	virtual void printname() = 0;			//made Person class abstract
	
	Since, this class is abstract I cant initialize the Person anymore
	I commented it out and return the class to normal so that I can initialize person in my main class
	*/

	Person(string pName) {						// initialise the name
	name = pName;
	};

	virtual void printname() {
		cout << "My name is " << name << " and I want to make a complain" << endl;;			//made Person class abstract
	}
	

	bool operator< (const Person& p) {
		return name < p.name;
	}

	string getName() {
		return name;
	}

protected:
	string name;
};
