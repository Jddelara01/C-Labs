//John Darren De Lara - x00072126   LAB1
#pragma once
#include <iostream>
#include <string>
#include "Product.h"

using namespace std;

class Book : public Product {

public:
	Book(double price) : Product(price) {};

	double getGrossPrice() {
		return netPrice;
	}
};
