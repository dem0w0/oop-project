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

	void display() {
		cout << endl << "Name: " << name << endl;
		cout << "Size: " << size << endl;
		cout << "Price: " << price << endl;
		cout << "Quantity: " << quantity << endl;
		if (availability == true) {
			cout << "Available" << endl;
		}
		else {
			cout << "Not available" << endl;
		}
		cout << "Neck Line: " << neckline << endl;
		cout << "Sleeve Length: " << sleeveLength << endl;
	}
};