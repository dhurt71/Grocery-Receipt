#pragma once

#include <string>

using namespace std;

class PriceListItem {
	friend class GroceryBill;
	friend class PriceList;
public:
	PriceListItem();
	PriceListItem(const string &itemName, const string &code, double price, bool taxable);
	string getItemName();
	string getCode();
	double getPrice();
	bool isTaxable();
private:
	string item_Name;
	string barcode;
	double item_Price;
	bool istaxable;
};