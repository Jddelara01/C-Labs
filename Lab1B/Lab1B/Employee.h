//John Darren De Lara - x00072126 LAB1B
#pragma once
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Employee : public Person {
public:
	Employee(string name, double val) : Person(name) {		//initialise salary
		salary = val;
	};

	void printname() {
		cout << "My name is " << name << " and my salary is " << salary << endl;
	}

protected:
	double salary;
};

