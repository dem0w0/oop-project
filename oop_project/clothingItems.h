#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

#ifdef _WIN32
	#define CLEAR_SCREEN "cls"
#else
	#define CLEAR_SCREEN "clear"
#endif

using namespace std;

class ClothingItem {
protected:
	string name, size;
	double price;
	int quantity;
	bool availability;
public:
	ClothingItem() : name("Default"), size("Default"), price(0.0), quantity(0), availability(quantity > 0) {}
	ClothingItem(string n, string s, double p, int q) : name(n), size(s), price(p), quantity(q), availability(quantity > 0) {}
	
	virtual void display() {
		cout << "Name: " << name << endl;
		cout << "Size: " << size << endl;
		cout << "Price: " << price << endl;
		cout << "Quantity: " << quantity << endl;
		cout << "Availability: " << availability << endl;
	}
};