#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

string centerText(const string& text, int width) {
	int padding = width - text.length();
	if (padding <= 0) {
		return text;
	}
	int leftPadding = padding / 2;
	int rightPadding = padding - leftPadding;
	return string(leftPadding, ' ') + text + string(rightPadding, ' ');
}

class ClothingItem {
protected:
	string name, size;
	double price;
	int quantity;
	bool availability;
public:
	ClothingItem() : name("Default"), size("Default"), price(0.0), quantity(0), availability(quantity > 0) {}
	ClothingItem(string n, string s, double p, int q) : name(n), size(s), price(p), quantity(q), availability(quantity > 0) {}

	virtual void displayDetails() const {
		cout << "| " << setw(8) << left << name << " |";
		cout << setw(5) << left << size << " |";
		cout << setw(7) << right << fixed << setprecision(2) << price << " |";
		cout << setw(8) << right << quantity << " |";
		cout << setw(13) << (availability ? "Available" : "Not available") << " |";
	}
	virtual string getType() const = 0;
	virtual string getDetails() const = 0;
	string getName() const {
		return name;
	}
	string getSize() const {
		return size;
	}
	double getPrice() const {
		return price;
	}
	int getQuantity() const {
		return quantity;
	}
	bool isAvailable() const {
		return availability;
	}
};