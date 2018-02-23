//John Darren De Lara - x00072126   LAB1
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Product {
public:
	Product(double price) {
		netPrice = price;
	}

	virtual double getGrossPrice() {
		return netPrice + (netPrice * .21);
	}

	double Display() {
		return netPrice;
	}

protected:				//so that I can access it in the book class
	double netPrice;
};
