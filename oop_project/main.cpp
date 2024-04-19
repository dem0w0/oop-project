#include <iostream>
#include "clothingItems.h"
#include <iomanip>

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

using namespace std;

void displayCentered(const string& text, int width) {
	int textLength = text.length();
	int padding = (width - textLength) / 2;
	cout << setw(padding + textLength) << setfill(' ') << text << endl;
}

void displayMenu(int width) {
	displayCentered("Storage", width);
	displayCentered("----", width);
	displayCentered("1. Add the product", width);
	displayCentered("2. Check inventory", width);
	displayCentered("3. Delete the product", width);
	displayCentered("4. Exit", width);
	displayCentered("----", width);
}

int main() {
	int width = 30, choice;
	bool isValidChoice = false;

	while (true) {
		displayMenu(width);
		cout << "Enter your choice: "; cin >> choice;

		switch (choice) {
		case 1:
			isValidChoice = true;
			system(CLEAR_SCREEN);
			cout << "addition of product";
			break;
		case 2:
			isValidChoice = true;
			system(CLEAR_SCREEN);
			cout << "\033[1;32mInventory\033[0m";	
			break;
		case 3:
			isValidChoice = true;
			system(CLEAR_SCREEN);
			cout << "deleting the product";
			break;
		case 4:
			isValidChoice = true;
			system(CLEAR_SCREEN);
			cout << "Exiting...";
			return 0;
			break;
		default:
			system(CLEAR_SCREEN);
			cout << "\t\t\t\t\033[1;31mThe choice is incorrect try again\033[0m\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}

		if (isValidChoice)
			break;
	}
	system("pause");
	return 0;
}

//Color codes

//cout << "\033[1;31mThis text is red!\033[0m" << endl; // Red
//cout << "\033[1;32mThis text is green!\033[0m" << endl; // Green
//cout << "\033[1;33mThis text is yellow!\033[0m" << endl; // Yellow
//cout << "\033[1;34mThis text is blue!\033[0m" << endl; // Blue
//cout << "\033[1;35mThis text is magenta!\033[0m" << endl; // Magenta
//cout << "\033[1;36mThis text is cyan!\033[0m" << endl; // Cyan
//cout << "\033[1;37mThis text is white!\033[0m" << endl; // White