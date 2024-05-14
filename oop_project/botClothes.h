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

	void displayDetails() override {
		ClothingItem::displayDetails();
		cout << "Waist type: " << waistType << endl;
		cout << "Length: " << length << endl;
	}

	string getType() const override {
		return "BotClothes";
	}
};