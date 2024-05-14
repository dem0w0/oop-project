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
		cout << "| " << setw(8) << left << getName() << " |";
		cout << setw(5) << left << getSize() << " |";
		cout << setw(7) << right << fixed << setprecision(2) << getPrice() << " |";
		cout << setw(8) << right << getQuantity() << " |";
		cout << setw(13) << (isAvailable() ? "Available" : "Not available") << " |";
		cout << setw(20) << left << "Type: " << type << " |";
		cout << setw(20) << left << "Material: " << material << " |" << endl;
	}
};