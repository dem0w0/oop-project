#include <iostream>
#include "clothingItems.h"
#include <iomanip>
#include <limits>
#include <chrono>
#include <thread>

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

void inventoryChoice(int width) {
	displayCentered("\033[1;32mInventory\033[0m", width + 9);
	displayCentered("----", width);
	displayCentered("1. Accessories", width);
	displayCentered("2. Shoes", width);
	displayCentered("3. Top clothes", width);
	displayCentered("4. Bottom clothes", width);
	displayCentered("5. Back to the Main", width);
	displayCentered("----", width);
}
void incorrectChoice() {

}

int main() {
	int width = 30, choice, invChoice;
	bool running = true, inInventoryMenu = false;

	while (running) {
		displayMenu(width);
		cout << "Enter your choice: ";
		if (!(cin >> choice)) {
			system(CLEAR_SCREEN);
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\033[1;31mInvalid input. Please enter a number.\033[0m\n";
			this_thread::sleep_for(chrono::seconds(2));
			system(CLEAR_SCREEN);
			continue;
		}

		switch (choice) {
			case 1:
				system(CLEAR_SCREEN);
				cout << "Addition of product...";
				break;
			case 2 :
				inInventoryMenu = true;
				while (inInventoryMenu) {

					system(CLEAR_SCREEN);
					inventoryChoice(width);
					cout << "Enter your choice: ";

					if (!(cin >> invChoice)) {
						system(CLEAR_SCREEN);
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\033[1;31mInvalid input. Please enter a number.\033[0m\n";
						this_thread::sleep_for(chrono::seconds(2));
						system(CLEAR_SCREEN);
						continue;
					}

					switch (invChoice) {
					case 1:
						system(CLEAR_SCREEN);
						cout << "Viewing Accessories..." << endl;
						break;
					case 2:
						system(CLEAR_SCREEN);
						cout << "Viewing Shoes..." << endl;
						break;
					case 3:
						system(CLEAR_SCREEN);
						cout << "Viewing Top Clothes..." << endl;
						break;
					case 4:
						system(CLEAR_SCREEN);
						cout << "Viewing Bottom Clothes..." << endl;
						break;
					case 5:
						inInventoryMenu = false;
						break;
					default:
						system(CLEAR_SCREEN);
						cout << "\033[1;31mThe choice is incorrect try again\033[0m";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						this_thread::sleep_for(chrono::seconds(2));
						break;
					}

					if (inInventoryMenu) {
						cout << "\nPress Enter to continue...";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin.get();
						system(CLEAR_SCREEN);
					}
				}
				break;
			case 3:
				system(CLEAR_SCREEN);
				cout << "Deleting the product...";
				break;
			case 4:
				running = false;
				system(CLEAR_SCREEN);
				cout << "Exiting...";
				return 0;
				break;
			default:
				system(CLEAR_SCREEN);
				cout << "\033[1;31mThe choice is incorrect try again\033[0m";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				this_thread::sleep_for(chrono::seconds(2));
				break;
		}

		if (running) {
			cout << "\nPress Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
			system(CLEAR_SCREEN);
		}
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