//John Darren De Lara - x00072126   LAB1
#pragma once
#include <iostream>
#include <string>
#include "Product.h"

using namespace std;

class Software : public Product {

public:
	Software(double price) : Product(price) {};
};
