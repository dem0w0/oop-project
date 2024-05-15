#pragma once
#include "clothingItems.h"
#include <iostream>
#include <string>

using namespace std;

class Shoes : public ClothingItem {
private:
	string type, material;
public:
	Shoes() : type("Default"), material("Default") {}
	Shoes(string n, string s, double p, int q, string t, string m) : ClothingItem(n, s, p, q), type(t), material(m) {}

	string getDetails() const override {
		return type + " " + material;
	}
	string getType() const override {
		return "Shoes";
	}
	void displayDetails() const override {
		ClothingItem::displayDetails();
		cout << setw(10) << right << type << " |";
		cout << setw(11) << left << material << " |";
		cout.unsetf(ios_base::floatfield);
		cout.precision(6);
		cout.fill(' ');
		cout.setf(ios_base::fmtflags(0), ios_base::adjustfield);
	}
};