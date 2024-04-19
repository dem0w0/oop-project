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
private:

protected:
	string name, brand, size, color, material;
	double price;
	int quantity;
	bool availability;
public:
	ClothingItem() {
		name = "Default";
		brand = "None";
		size = "Default";
		color = "None";
		material = "Default";
		price = 0.0;
		quantity = 0;
		availability = (quantity > 0);
	}
	ClothingItem(string n, string b, string s, string c, string m, double p, int q) {
		name = n;
		brand = b;
		size = s;
		color = c;
		material = m;
		price = p;
		quantity = q;
		availability = (quantity > 0);
	}
	
	void display() {
		cout << "Name: " << name << endl;
		cout << "Brand: " << brand << endl;
		cout << "Size: " << size << endl;
		cout << "Color: " << color << endl;
		cout << "Material: " << material << endl;
		cout << "Price: " << price << endl;
		cout << "Quantity: " << quantity << endl;
		cout << "Availability: " << availability << endl;
	}
};