#pragma once
#include "clothingItems.h"
#include <iostream>
#include <string>

using namespace std;

class TopClothes : public ClothingItem {
private:
	string neckline, sleeveLength;
public:
	TopClothes() : neckline("Default"), sleeveLength("Default") {}
	TopClothes(string n, string s, double p, int q, string neck, string length) : ClothingItem(n, s, p, q), neckline(neck), sleeveLength(length) {}

	string getDetails() const override {
		return neckline + " " + sleeveLength;
	}

	string getType() const override {
		return "TopClothes";
	}

	void displayDetails() const override {
		ClothingItem::displayDetails();
		cout << setw(11) << right << neckline << "|";
		cout << setw(12) << left << sleeveLength << "|";
		cout.unsetf(ios_base::floatfield);
		cout.precision(6);
		cout.fill(' ');
		cout.setf(ios_base::fmtflags(0), ios_base::adjustfield);
	}
};
