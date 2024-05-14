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

	void displayDetails() override {
		ClothingItem::displayDetails();
		cout << "Type of shoes: " << type << endl;
		cout << "Material: " << material << endl;
	}
	string getType() const override {
		return "Shoes";
	}
};