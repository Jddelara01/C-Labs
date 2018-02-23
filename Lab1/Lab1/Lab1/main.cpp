//John Darren De Lara - x00072126   LAB1

/*Reference: http://www.cplusplus.com/articles/NhA0RXSz/ */

#include <iostream>
#include <string>
#include <algorithm>
#include "Product.h"
#include "Software.h"
#include "Book.h"

using namespace std;

bool compare(Product *first, Product *second) {
	return first->getGrossPrice() < second->getGrossPrice();
}

int main()
{

	/*Product p1(50);
	cout << p1.Display() << endl;

	cout << p1.getGrossPrice() << endl;

	Software s1(50);
	cout << p1.getGrossPrice() << endl;

	Book b1(50);
	cout << b1.getGrossPrice() << endl;*/

	Product *p[8];		//Declare an array of 8 pointers to Product

	Software *s;		//Declare a pointer to Software

	Book *b;			//Declare a pointer to Book

	double softwarePrice, bookPrice;

	cout << "Please enter the software price: " << endl;
	cin >> softwarePrice;
	cout << "The software price is : " << softwarePrice << endl;

	cout << "Please enter the book price: " << endl;
	cin >> bookPrice;
	cout << "The book price is : " << bookPrice << endl;

	Software s1(softwarePrice);			//create the dynamic software price item
	Book b1(bookPrice);					//create the dynamic book price item

	s = &s1;		//store s1 addresses to my s pointer
	b = &b1;		//store b1 addresses to my b pointer

	cout << "*********************************************************" << endl;
	cout << "The software gross price:" << s->getGrossPrice() << endl;
	cout << "The book gross price:" << b->getGrossPrice() << endl;

	p[0] = s;		//adding the s to the 1st pointer of the array
	p[1] = b;		//adding the b to the 2nd pointer of the array

	cout << "*********************************************************" << endl;
	cout << "The price of p[0]" << p[0]->Display() << endl;
	cout << "The price of p[1]" << p[1]->Display() << endl;

	cout << "*********************************************************" << endl;
	string choice;

	for (int i = 2; i < 8; i++) {
		cout << "Please enter your product type (book or software): " << endl;
		cin >> choice;
		if (choice == "software") {
			cout << "Type: " << choice << endl;
			cout << "Please enter the price" << endl;
			cin >> softwarePrice;
			p[i] = new Software(softwarePrice);
		}
		else if (choice == "book") {
			cout << "Type: " << choice << endl;
			cout << "Please enter the price" << endl;
			cin >> bookPrice;
			p[i] = new Book(bookPrice);
		}
		else {
			cout << "Entered wrong product type, please enter a new product type again." << endl;
		}
	}
	cout << "*********************************************************" << endl;
	cout << "The gross price for each products" << endl;
	
	for (int i = 0; i < 8; i++) {
		cout << p[i]->getGrossPrice() << endl;
	}

	sort(p, p + 8, compare);			//to sort

	cout << "*********************************************************" << endl;
	cout << "SORTED:" << endl;
	for (int i = 0; i < 8; i++) {
		cout << p[i]->getGrossPrice() << endl;
	}

	system("pause");
}

