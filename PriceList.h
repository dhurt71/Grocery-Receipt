#pragma once
#include <string>
#include <stdexcept>
#include "PriceListItem.h"

using namespace std;

class PriceList {
public:
	friend class GroceryBill;
	void createPriceListFromDatafile(string filename); // Load information from a text file with the given filename (Completed)
	void addEntry(string itemName, string code, double price, bool taxable); // add to the price list information about a new item. A max of 1,000,000 entries can be added
	bool isValid(string code) const; // return true only if the code is valid
	PriceListItem getItem(string code) const; // return price, item name, taxable? as an PriceListItem object; throw exception if code is not found
	PriceList();
	PriceList(const PriceList& a);
	PriceList& operator = (const PriceList& a);
private:
	const int size = 1000000;
	PriceListItem* aPtr;
	int index;
};