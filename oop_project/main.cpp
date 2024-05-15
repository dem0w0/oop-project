#include "clothings.h"
#include <iostream>
#include <vector>
#include <limits>
#include <chrono>
#include <thread>
#include <fstream>
#include <sstream>
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
	displayCentered("\033[1;32mInventory\033[0m", width + 11);
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
	const vector<string> sizes = { " S ", " M ", " L ", " XL", "XXL" };
	return sizes[rand() % sizes.size()];
}

double generateRandomPrice(double minPrice, double maxPrice) {
	return minPrice + static_cast<double>(rand()) / static_cast<double>(RAND_MAX / (maxPrice - minPrice));
}

int generateRandomQuantity(int minQuantity, int maxQuantity) {
	return rand() % (maxQuantity - minQuantity + 1) + minQuantity;
}

string generateRandomNeckline() {
	const vector<string> necklines = { "Crew Neck", "V-Neck", "Scoop Neck", "Halter Neck" };
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
		int quantity = generateRandomQuantity(10, 100);

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
			items.push_back(new Shoes(name, size, price, quantity, shoeType, material));
		}
	}
	clothingFile.close();
}

void displayWithPagination(vector<ClothingItem*>& items, const string& itemType) {
	const int itemsPerPage = 10;

	vector<ClothingItem*> filteredItems;
	for (ClothingItem* item : items) {
		if (item->getType() == itemType) {
			filteredItems.push_back(item);
		}
	}

	int totalPages = (filteredItems.size() + itemsPerPage - 1) / itemsPerPage;

	string userInput;
	do {
		int page = 1;
		while (true) {
			system(CLEAR_SCREEN);
			cout << "Showing: " << itemType << " Page: (" << page << "/" << totalPages << "):" << endl;

			vector<ClothingItem*> filteredItems;
			for (ClothingItem* item : items) {
				if (item->getType() == itemType) {
					filteredItems.push_back(item);
				}
			}

			int startIdx = (page - 1) * itemsPerPage;
			int endIdx = min(startIdx + itemsPerPage, static_cast<int>(filteredItems.size()));

			cout << "+----------+------+--------+---------+--------------+------------------------+" << endl;
			cout << "|   Name   | Size | Price  | Quantity| Availability |       Additional       |" << endl;
			cout << "+----------+------+--------+---------+--------------+------------------------+" << endl;

			for (int i = startIdx; i < endIdx; ++i) {
				filteredItems[i]->displayDetails();
				cout << endl;
			}

			cout << "+----------+------+--------+---------+--------------+------------------------+" << endl;

			cout << "Enter the command ('next', 'prev', 'exit' or page number which you want to go): ";
			cin >> userInput;

			if (userInput == "exit") {
				return;
			}
			else if (userInput == "next") {
				page = min(page + 1, totalPages);
			}
			else if (userInput == "prev") {
				page = max(page - 1, 1);
			}
			else if (isdigit(userInput[0])) {
				int pageNumber = stoi(userInput);
				if (pageNumber >= 1 && pageNumber <= totalPages) {
					page = pageNumber;
				}
				else {
					cout << "Invalid page number. Please enter a number between 1 and " << totalPages << "." << endl;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin.get();
				}
			}
			else {
				cout << "Invalid input. Please enter 'next', 'prev', a page number, or 'exit'." << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.get();
			}
		}
	} while (userInput != "exit");
}

void addingObjectToTheFile(const string& itemtype) {
	ofstream outFile("objects.txt");
	if (!outFile.is_open()) {
		cout << "Error with opening objects.txt file while adding new object";
	}
	string name, size, neckLine, sleeveLength, shoeType, accType, season, material, waistType, length;
	double price;
	int quantity, choice;
	bool choosing = false;
	cout << endl << "Name (8 characters only): "; cin >> name;
	choosing = true;
	while (choosing) {
		cout << "\nPlease choose size:\n\n1. S\n2. M\n3. L\n4. XL\n5. XXL\n\nEnter your choice: "; cin >> choice;
		switch (choice) {
		case 1:
			size = " S ";
			choosing = false;
			break;
		case 2:
			size = " M ";
			choosing = false;
			break;
		case 3:
			size = " L ";
			choosing = false;
			break;
		case 4:
			size = " XL";
			choosing = false;
			break;
		case 5:
			size = "XXL";
			choosing = false;
			break;
		default:
			cout << "\033[1;31mIncorrect choice please try again!\033[0m";
		}
	}
	cout << "Price: "; cin >> price;
	cout << "Quantity: "; cin >> quantity;
	if (itemtype == "TopClothes") {
		choosing = true;
		while (choosing) {
			cout << "Please choose neck line:\n\n1. Crew Neck\n2. V-Neck\n3. Scoop Neck\n4. Halter Neck\n\nEnter your choice: "; cin >> choice;
			switch (choice) {
			case 1:
				neckLine = "Crew Neck";
				choosing = false;
				break;
			case 2:
				neckLine = "V-Neck";
				choosing = false;
				break;
			case 3:
				neckLine = "Scoop Neck";
				choosing = false;
				break;
			case 4:
				neckLine = "Halter Neck";
				choosing = false;
				break;
			default:
				cout << "\033[1;31mIncorrect choice please try again!\033[0m";
				break;
			}
		}
		choosing = true;
		while (choosing) {
			cout << "Please choose sleeve length:\n\n1. Short Sleeve\n2. Long Sleeve\n3. 3/4 Sleeve\n\nEnter your choice: "; cin >> choice;
			switch (choice) {
			case 1:
				sleeveLength = "Short Sleeve";
				choosing = false;
				break;
			case 2:
				sleeveLength = "Long Sleeve";
				choosing = false;
				break;
			case 3:
				sleeveLength = "3/4 Sleeve";
				choosing = false;
				break;
			default:
				cout << "\033[1;31mIncorrect choice please try again!\033[0m";
				break;
			}
		}
		outFile << "TopClothes" << "," << name << "," << size << "," << price << "," << quantity << "," << neckLine << "," << sleeveLength << endl;
	}
	else if (itemtype == "BotClothes") {
		choosing = true;
		while (choosing) {
			cout << "Please choose waist type:\n\n1. High waist\n2. Mid Waist\n3. Low waist\n\nEnter your choice: "; cin >> choice;
			switch (choice) {
			case 1:
				waistType = "High waist";
				choosing = false;
				break;
			case 2:
				waistType = "Mid Waist";
				choosing = false;
				break;
			case 3:
				waistType = "Low waist";
				choosing = false;
				break;
			default:
				cout << "\033[1;31mIncorrect choice please try again!\033[0m";
				break;
			}
		}
		choosing = true;
		while (choosing) {
			cout << "Please choose length:\n\n1. Ankle length\n2. Full length\n3. Capri Length\n\nEnter your choice: "; cin >> choice;
			switch (choice) {
			case 1:
				length = "Ankle length";
				choosing = false;
				break;
			case 2:
				length = "Full length";
				choosing = false;
				break;
			case 3:
				length = "Capri Length";
				choosing = false;
				break;
			default:
				cout << "\033[1;31mIncorrect choice please try again!\033[0m";
				break;
			}
		}
		outFile << "BotClothes" << "," << name << "," << size << "," << price << "," << quantity << "," << waistType << "," << length << endl;
	}
	else if (itemtype == "Accessories") {
		choosing = true;
		while (choosing) {
			cout << "Please choose accessories type:\n\n1. Bag\n2. Scarf\n3. Hat\n4. Belt\n\nEnter your choice: "; cin >> choice;
			switch (choice) {
			case 1:
				accType = "Bag";
				choosing = false;
				break;
			case 2:
				accType = "Scarf";
				choosing = false;
				break;
			case 3:
				accType = "Hat";
				choosing = false;
				break;
			case 4:
				accType = "Belt";
				choosing = false;
				break;
			default:
				cout << "\033[1;31mIncorrect choice please try again!\033[0m";
				break;
			}
		}
		choosing = true;
		while (choosing) {
			cout << "Please choose seasonality:\n\n1. Summer\n2. Winter\n3. Spring\n4. Fall\n\nEnter your choice: "; cin >> choice;
			switch (choice) {
			case 1:
				season = "Summer";
				choosing = false;
				break;
			case 2:
				season = "Winter";
				choosing = false;
				break;
			case 3:
				season = "Spring";
				choosing = false;
				break;
			case 4:
				season = "Fall";
				choosing = false;
				break;
			default:
				cout << "\033[1;31mIncorrect choice please try again!\033[0m";
				break;
			}
		}
		outFile << "Accessories" << "," << name << "," << size << "," << price << "," << quantity << "," << accType << "," << season << endl;
	}
	else if (itemtype == "Shoes") {
		choosing = true;
		while (choosing) {
			cout << "Please choose shoes type:\n\n1. Sneakers\n2. Boots\n3. Sandals\n4. Flats\n\nEnter your choice: "; cin >> choice;
			switch (choice) {
			case 1:
				shoeType = "Sneakers";
				choosing = false;
				break;
			case 2:
				shoeType = "Boots";
				choosing = false;
				break;
			case 3:
				shoeType = "Sandals";
				choosing = false;
				break;
			case 4:
				shoeType = "Flats";
				choosing = false;
				break;
			default:
				cout << "\033[1;31mIncorrect choice please try again!\033[0m";
				break;
			}
		}
		choosing = true;
		while (choosing) {
			cout << "Please choose material:\n\n1. Leather\n2. Canvas\n3. Synthetic\n4. Rubber\n\nEnter your choice: "; cin >> choice;
			switch (choice) {
			case 1:
				material = "Leather";
				choosing = false;
				break;
			case 2:
				material = "Canvas";
				choosing = false;
				break;
			case 3:
				material = "Synthetic";
				choosing = false;
				break;
			case 4:
				material = "Rubber";
				choosing = false;
				break;
			default:
				cout << "\033[1;31mIncorrect choice please try again!\033[0m";
				break;
			}
		}
		outFile << "Shoes" << "," << name << "," << size << "," << price << "," << quantity << "," << shoeType << "," << material << endl;
	}
	outFile.close();
}

void deleteLineByName(const string& targetName) {
	ifstream infile("objects.txt");
	if (!infile) {
		cerr << "Unable to open file" << endl;
		return;
	}

	vector<string> lines;
	string line;
	bool found = false;

	while (getline(infile, line)) {
		istringstream iss(line);
		string item, name;
		getline(iss, item, ',');
		getline(iss, name, ',');
		if (name == targetName) {
			cout << "Object is successfully deleted!" << endl;
			found = true;
		}
		else {
			lines.push_back(line);
		}
	}
	infile.close();

	if (!found) {
		cerr << "\033[1;31mName is not found\033[0m" << endl;
		return;
	}

	ofstream outfile("objects.txt");
	for (const auto& l : lines) {
		outfile << l << endl;
	}
	outfile.close();
}

void deleteClothingItems(vector<ClothingItem*>& items) {
	for (auto item : items) {
		delete item;
	}
	items.clear();
	items.shrink_to_fit();
}

int main() {
	vector<ClothingItem*> items;
	//generateRandomObjectsToFile("objects.txt", 500);

	int width = 30, choice, invChoice, addChoice;
	bool running = true, inInventoryMenu = false, inAddingMenu = false;
	string targetName;

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
			inAddingMenu = true;
			while (inAddingMenu) {
				system(CLEAR_SCREEN);
				cout << "Which type of product you want to add?\n\n1. Accessory\n2. Shoes\n3. Top Clothes\n4. Bottom Clothes\n5. Exit\n\nEnter your choice: ";
				if (!(cin >> addChoice)) {
					system(CLEAR_SCREEN);
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\033[1;31mInvalid input. Please enter a number.\033[0m\nPress Enter to continue...";
					cin.get();
					system(CLEAR_SCREEN);
					continue;
				}
				switch (addChoice) {
				case 1:
					system(CLEAR_SCREEN);
					addingObjectToTheFile("Accessories");
					inAddingMenu = false;
					break;
				case 2:
					system(CLEAR_SCREEN);
					addingObjectToTheFile("Shoes");
					inAddingMenu = false;
					break;
				case 3:
					system(CLEAR_SCREEN);
					addingObjectToTheFile("TopClothes");
					inAddingMenu = false;
					break;
				case 4:
					system(CLEAR_SCREEN);
					addingObjectToTheFile("BotClothes");
					inAddingMenu = false;
					break;
				case 5:
					inAddingMenu = false;
					break;
				default:
					system(CLEAR_SCREEN);
					cout << "\033[1;31mThe choice is incorrect try again\033[0m\nPress Enter to continue...";
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin.get();
					break;
				}
			}
			
			break;
		case 2:
			deleteClothingItems(items);
			autoCreatingObjects(items);
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
					displayWithPagination(items, "Accessories");
					break;
				case 2:
					system(CLEAR_SCREEN);
					cout << "Viewing Shoes..." << endl;
					displayWithPagination(items, "Shoes");
					break;
				case 3:
					system(CLEAR_SCREEN);
					cout << "Viewing Top Clothes..." << endl;
					displayWithPagination(items, "TopClothes");
					break;
				case 4:
					system(CLEAR_SCREEN);
					cout << "Viewing Bottom Clothes..." << endl;
					displayWithPagination(items, "BotClothes");
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
			cout << "Enter the name of object that you want to delete or 'exit' if you want to exit: "; cin >> targetName;
			if (targetName == "exit") {
				break;
			}
			else {
				deleteLineByName(targetName);
			}
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