//John Darren De Lara - x00072126 LAB1B
#pragma once
#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Customer : public Person {
public:
	Customer(string name) : Person(name) {};

	void printname() {
		cout << "My name is " << name << " and I want to make a complain" << endl;
	}
};

