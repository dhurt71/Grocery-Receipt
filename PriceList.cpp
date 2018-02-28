#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PriceList.h"
#include "PriceListItem.h"

using namespace std;

// Load information from a text file with the given filename.
void PriceList::createPriceListFromDatafile(string filename) {
	ifstream myfile(filename);

	if (myfile.is_open()) {
		cout << "Successfully opened file " << filename << endl;
		string name;
		string code;
		double price;
		bool taxable;
		while (myfile >> name >> code >> price >> taxable) {
			// cout << code << " " << taxable << endl;
			addEntry(name, code, price, taxable);
		}
		myfile.close();
	}
	else
		throw invalid_argument("Could not open file " + filename);
}

// return true only if the code is valid
bool PriceList::isValid(string code) const {
	if (index == 0) return false;
	for (int i = 0; i < index; i++) {
		if (code == aPtr[i].getCode()) {
			return true;
		}
	}
	return false;
}

// return price, item name, taxable? as an ItemPrice object; throw exception if code is not found
PriceListItem PriceList::getItem(string code) const {
	if (!isValid(code)) 
		throw "Item does not exist.";
	for (int i = 0; i < index; i++) {
		if (code == aPtr[i].getCode()) {
			return aPtr[i];
		}
	}
	throw runtime_error("Item not found.");
}


// add to the price list information about a new item
void PriceList::addEntry(string itemName, string code, double price, bool taxable) {
	if (isValid(code)) return;
	if (index == 1000000)
		throw string("Out of bounds: aPtr");
	aPtr[index] = PriceListItem(itemName, code, price, taxable);
	index++;
}

PriceList::PriceList() {
	aPtr = new PriceListItem[size];
	index = 0;
}

PriceList::PriceList(const PriceList& a) {
	if (this != &a) {
		index = a.index;
		aPtr = new PriceListItem[index];
		for (int i = 0; i < index; i++) {
			aPtr[i] = a.aPtr[i];
		}
	}
}

PriceList& PriceList::operator = (const PriceList &a) {
	if (this != &a) {
		delete[] aPtr;
		index = a.index;
		aPtr = new PriceListItem[index];
		for (int i = 0; i < index; i++) {
			aPtr[i] = a.aPtr[i];
		}
	}
	return *this;
}