#include "clothings.h"
#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
#include <thread>
#include <fstream>
#include <cstdlib>
#include <ctime>

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

string generateRandomName(int length) {
	const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	string randomName;
	for (int i = 0; i < length; ++i) {
		randomName += characters[rand() % characters.length()];
	}
	return randomName;
}

string generateRandomType() {
	const vector<string> types = { "TopClothes", "BotClothes", "Accessories", "Shoes" };
	return types[rand() % types.size()];
}

string generateRandomSize() {
	const vector<string> sizes = { "S", "M", "L", "XL", "XXL" };
	return sizes[rand() % sizes.size()];
}

double generateRandomPrice(double minPrice, double maxPrice) {
	return minPrice + static_cast<double>(rand()) / static_cast<double>(RAND_MAX / (maxPrice - minPrice));
}

int generateRandomQuantity(int minQuantity, int maxQuantity) {
	return rand() % (maxQuantity - minQuantity + 1) + minQuantity;
}

string generateRandomNeckline() {
	const vector<string> necklines = { "Crew Neck", "V-Neck", "Scoop Neck", "Halter Neck", "Off-the-Shoulder" };
	return necklines[rand() % necklines.size()];
}

string generateRandomSleeveLength() {
	const vector<string> sleeveLengths = { "Short Sleeve", "Long Sleeve", "3/4 Sleeve" };
	return sleeveLengths[rand() % sleeveLengths.size()];
}

string generateRandomWaistType() {
	const vector<string> waistTypes = { "High Waist", "Mid Waist", "Low Waist" };
	return waistTypes[rand() % waistTypes.size()];
}

string generateRandomLength() {
	const vector<string> lengths = { "Ankle Length", "Full Length", "Capri Length" };
	return lengths[rand() % lengths.size()];
}

string generateRandomAccessType() {
	const vector<string> accessTypes = { "Bag", "Scarf", "Hat", "Belt" };
	return accessTypes[rand() % accessTypes.size()];
}

string generateRandomSeasonality() {
	const vector<string> seasonalityTypes = { "Summer", "Winter", "Spring", "Fall" };
	return seasonalityTypes[rand() % seasonalityTypes.size()];
}

string generateRandomShoeType() {
	const vector<string> shoeTypes = { "Sneakers", "Boots", "Sandals", "Flats" };
	return shoeTypes[rand() % shoeTypes.size()];
}

string generateRandomMaterial() {
	const vector<string> materials = { "Leather", "Canvas", "Synthetic", "Rubber" };
	return materials[rand() % materials.size()];
}

void generateRandomObjectsToFile(const string& filename, int numObjects) {
	ofstream outFile(filename);
	if (!outFile.is_open()) {
		cout << "Error with opening the file for writing";
		return;
	}
	srand(time(0));

	for (int i = 0; i < numObjects; ++i) {
		string type = generateRandomType();
		string name = generateRandomName(8);
		string size = generateRandomSize();
		double price = generateRandomPrice(10.0, 100.0);
		int quantity = generateRandomQuantity(1, 100);

		outFile << type << "," << name << "," << size << "," << price << "," << quantity;

		if (type == "TopClothes") {
			outFile << "," << generateRandomNeckline() << "," << generateRandomSleeveLength();
		}
		else if (type == "BotClothes") {
			outFile << "," << generateRandomWaistType() << "," << generateRandomLength();
		}
		else if (type == "Accessories") {
			outFile << "," << generateRandomAccessType() << "," << generateRandomSeasonality();
		}
		else if (type == "Shoes") {
			outFile << "," << generateRandomShoeType() << "," << generateRandomMaterial();
		}
		outFile << endl;
	}

	outFile.close();
}

void autoCreatingObjects(vector<ClothingItem*>& items) {
	ifstream clothingFile("objects.txt");
	if (!clothingFile.is_open()) {
		cout << "Error with opening objects.txt file while reading";
		return;
	}
	string line;
	while (getline(clothingFile, line)) {
		size_t start = 0;
		size_t end = line.find(',');
		string tag = line.substr(start, end - start);
		if (tag == "TopClothes") {
			start = end + 1;
			end = line.find(',', start);
			string name = line.substr(start, end - start);
			start = end + 1;
			end = line.find(',', start);
			string size = line.substr(start, end - start);
			start = end + 1;
			end = line.find(',', start);
			double price = stod(line.substr(start, end - start));
			start = end + 1;
			end = line.find(',', start);
			int quantity = stoi(line.substr(start, end - start));
			start = end + 1;
			end = line.find(',', start);
			string neckline = line.substr(start, end - start);
			start = end + 1;
			string sleeveLength = line.substr(start);
			items.push_back(new TopClothes(name, size, price, quantity, neckline, sleeveLength));
		}
		else if (tag == "BotClothes") {
			start = end + 1;
			end = line.find(',', start);
			string name = line.substr(start, end - start);
			start = end + 1;
			end = line.find(',', start);
			string size = line.substr(start, end - start);
			start = end + 1;
			end = line.find(',', start);
			double price = stod(line.substr(start, end - start));
			start = end + 1;
			end = line.find(',', start);
			int quantity = stoi(line.substr(start, end - start));
			start = end + 1;
			end = line.find(',', start);
			string waist = line.substr(start, end - start);
			start = end + 1;
			string length = line.substr(start);
			items.push_back(new BotClothes(name, size, price, quantity, waist, length));
		}
		else if (tag == "Accessories") {
			start = end + 1;
			end = line.find(',', start);
			string name = line.substr(start, end - start);
			start = end + 1;
			end = line.find(',', start);
			string size = line.substr(start, end - start);
			start = end + 1;
			end = line.find(',', start);
			double price = stod(line.substr(start, end - start));
			start = end + 1;
			end = line.find(',', start);
			int quantity = stoi(line.substr(start, end - start));
			start = end + 1;
			end = line.find(',', start);
			string accType = line.substr(start, end - start);
			start = end + 1;
			string season = line.substr(start);
			items.push_back(new Accessories(name, size, price, quantity, accType, season));
		}
		else if (tag == "Shoes") {
			start = end + 1;
			end = line.find(',', start);
			string name = line.substr(start, end - start);
			start = end + 1;
			end = line.find(',', start);
			string size = line.substr(start, end - start);
			start = end + 1;
			end = line.find(',', start);
			double price = stod(line.substr(start, end - start));
			start = end + 1;
			end = line.find(',', start);
			int quantity = stoi(line.substr(start, end - start));
			start = end + 1;
			end = line.find(',', start);
			string shoeType = line.substr(start, end - start);
			start = end + 1;
			string material = line.substr(start);
			items.push_back(new Accessories(name, size, price, quantity, shoeType, material));
		}
	}
	clothingFile.close();
}
void displayWithPagination(vector<ClothingItem*>& items, const string& itemType) {
	const int itemsPerPage = 10;
	int page, totalPages = (items.size() + itemsPerPage - 1) / itemsPerPage;
	do {
		cout << "Enter page number (1-" << totalPages << "): ";
		cin >> page;
	} while (page < 1 || page > totalPages);
	int startIdx = (page - 1) * itemsPerPage;
	int endIdx = min(startIdx + itemsPerPage, static_cast<int>(items.size()));
	cout << "Showing: " << itemType << "Page: " << page << "/" << totalPages << "):" << endl;
	for (int i = startIdx; i < endIdx; ++i) {
		if (items[i]->getType() == itemType) {
			cout << "Item " << i + 1 << ":" << endl;
			items[i]->displayDetails();
			cout << endl;
		}
	}
}

/*void autoCreatingObjects() {
	ifstream clothingFile("objects.txt");
	if (!clothingFile.is_open()) {
		cout << "Problem with opening the objects.txt while reading";
	}
	string line;
	vector<ClothingItem> obj;

	while (getline(clothingFile, line)) {
		size_t start = 0;
		size_t end = line.find(',');

		string name = line.substr(start, end - start);

		start = end + 1;
		end = line.find(',', start);

		string size = line.substr(start, end - start);

		start = end + 1;
		end = line.find(',', start);

		double price = stod(line.substr(start, end - start));

		start = end + 1;

		int quantity = stoi(line.substr(start, end - start));

		obj.emplace_back(name, size, price, quantity);
	}

	for (const auto& obj : obj) {
		obj.display();
	}

	clothingFile.close();
}
*/
int main() {
	vector<ClothingItem*> items;
	generateRandomObjectsToFile("objects.txt", 100);
	autoCreatingObjects(items);

	/*int width = 30, choice, invChoice;
	bool running = true, inInventoryMenu = false;

	while (running) {
		displayMenu(width);
		cout << "Enter your choice: ";
		if (!(cin >> choice)) {
			system(CLEAR_SCREEN);
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\033[1;31mInvalid input. Please enter a number.\033[0m\nPress Enter to continue...";
			cin.get();
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
						cout << "\033[1;31mInvalid input. Please enter a number.\033[0m\nPress Enter to continue...";
						cin.get();
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
						cout << "\033[1;31mThe choice is incorrect try again\033[0m\nPress Enter to continue...";
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin.get();
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
				break;
		}

		if (running) {
			cout << "\nPress Enter to continue...";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
			system(CLEAR_SCREEN);
		}
	}*/
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