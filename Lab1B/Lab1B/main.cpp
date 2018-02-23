//John Darren De Lara - x00072126 LAB1B

/*Reference: https://gist.github.com/sachin-handiekar/2017449 */

#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Customer.h"
#include "Employee.h"
#include <algorithm>
#include <vector>

using namespace std;


int main() {

	Person *personPtr;			//declare a pointer to Persion

	Person p("John");			//create and initialise person object
	personPtr = &p;				
	personPtr->printname();		//call printname method via the pointer

	Employee e("Tom", 34000);
	personPtr = &e;
	personPtr->printname();

	Customer c("Ed");
	personPtr = &c;
	personPtr->printname();

	cout << "*********************************************************" << endl;
	//Testing if my overloaded operator< works
	cout << "Check if overloaded operator works" << endl;
	if (p < c) {
		cout << p.getName() << ", " << c.getName() << endl;
	}
	else {
		cout << p.getName() << ", " << c.getName() << endl;
	}

	//initialize vector object
	vector<Person*> personVector;

	personVector.push_back(new Employee("John", 20000));
	personVector.push_back(new Customer("Alan"));
	personVector.push_back(new Employee("Bret", 20000));
	personVector.push_back(new Person("Aj"));

	//cout << personVector.size() << endl;

	cout << "*********************************************************" << endl;
	cout << "UNSORTED:" << endl;
	for (int i = 0; i < personVector.size(); i++) {
		cout << personVector[i]->getName() << endl;
	}


	cout << "*********************************************************" << endl;
	cout << "SORTED:" << endl;

	for (int i = 0; i < personVector.size(); i++) {
		for (int j = 0;  j < personVector.size() - 1; j++) {
			if (personVector[j + 1]->operator<(personVector[j]->getName()))
			{
				Person *temporary = personVector[j];
				personVector[j] = personVector[j + 1];
				personVector[j + 1] = temporary;
			}
		}
	}

	for (int i = 0; i < personVector.size(); i++) {
		cout << personVector[i]->getName() << endl;
	}


	system("pause");

}