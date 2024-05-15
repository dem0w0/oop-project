#pragma once
#include "clothingItems.h"
#include <iostream>
#include <string>

using namespace std;

class Accessories : public ClothingItem {
private:
	string type, seasonality;
public:
	Accessories() : type("Default"), seasonality("Default") {}
	Accessories(string n, string s, double p, int q, string t, string season) : ClothingItem(n, s, p, q), type(t), seasonality(season) {}

	string getDetails() const override {
		return type + " " + seasonality;
	}
	string getType() const override {
		return "Accessories";
	}

	void displayDetails() const override {
		ClothingItem::displayDetails();
		cout << setw(10) << right << type << " |";
		cout << setw(11) << left << seasonality << " |";
	}
};