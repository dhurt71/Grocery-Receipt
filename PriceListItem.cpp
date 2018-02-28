#include "PriceListItem.h"

PriceListItem::PriceListItem(const string &itemName, const string &code, double price, bool taxable) {
	item_Name = itemName;
	barcode = code;
	item_Price = price;
	istaxable = taxable;
}

PriceListItem::PriceListItem() {
	item_Name = "No Name";
	barcode = "None";
	item_Price = 0.0;
	istaxable = false;
}

string PriceListItem::getItemName() {
	return item_Name;
}

string PriceListItem::getCode() {
	return barcode;
}

double PriceListItem::getPrice() {
	return item_Price;
}

bool PriceListItem::isTaxable() {
	return istaxable;
}