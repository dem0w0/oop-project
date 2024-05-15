#pragma once
#include "clothingItems.h"
#include <iostream>
#include <string>

using namespace std;

class BotClothes : public ClothingItem {
private:
	string waistType, length;
public:
	BotClothes() : waistType("Default"), length("Default") {}
	BotClothes(string n, string s, double p, int q, string waist, string length) : ClothingItem(n, s, p, q), waistType(waist), length(length) {}

	string getDetails() const override {
		return waistType + " " + length;
	}

	string getType() const override {
		return "BotClothes";
	}

	void displayDetails() const override {
		ClothingItem::displayDetails();
		cout << setw(10) << right << waistType << " |";
		cout << setw(12) << left << length << "|";
		cout.unsetf(ios_base::floatfield);
		cout.precision(6);
		cout.fill(' ');
		cout.setf(ios_base::fmtflags(0), ios_base::adjustfield);
	}
};