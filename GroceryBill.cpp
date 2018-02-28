#include "GroceryBill.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

GroceryBill::GroceryBill(const PriceList *priceList, double taxRate) {
	pList = priceList;
	index2 = 0;
	taxRate = taxRate/100 + 1;
	total = 0.0;
}


void GroceryBill::scanItem(string scanCode, double quantity) {
	if(pList->isValid(scanCode) == false)
		throw ("Item does not exist.");
	PriceListItem j = pList->getItem(scanCode);
	Bill[index2] = j;
	Bill[index2].item_Price *= quantity;
	if (j.isTaxable() == true) {
		total += Bill[index2].getPrice()*taxRate;
	}
	index2++;
}

// Scan multiple codes and quantities from the given text file
// Each line contains two numbers separated by space: the first is the code (an integer), the second the quantity (a float/double)
// Example line from text file:
// 15000000 1.5
void GroceryBill::scanItemsFromFile(string filename) {
	ifstream myfile(filename);

	if (myfile.is_open()) {
		string barcode;
		double quantity;

		cout << "Successfully opened file " << filename << endl;

		while (myfile >> barcode >> quantity) {
			// cout << code << " " << taxable << endl;
			scanItem(barcode, quantity);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return the total cost of all items scanned
double GroceryBill::getTotal() {
	return total;
}

// Print the bill to cout. Each line contains the name of an item, total price, and the letter "T" if tax was addded. 
// The last line shows the total.
// An example:
//Plastic_Wrap	1.60547 T
//Sugar_white	5.475
//Waffles_frozen	5.16
//Oil_Canola_100%_pure	2.69
//Potatoes_red	13.446
//TOTAL 	28.3765
void GroceryBill::printBill() {
	for (int i = 0; i < index2; i++) {
	if (Bill[i].isTaxable() == true) {
		cout << Bill[i].getItemName() << " " << Bill[i].getPrice() * taxRate << " " << "T" << endl;
	}
	else {
		cout << Bill[i].getItemName() << " " << Bill[i].getPrice();
	}
	}
	cout << "TOTAL   " << getTotal();
	
}