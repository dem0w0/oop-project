#include "clothingItems.h"
#include <iostream>
#include <string>

using namespace std;

class TopClothes : public ClothingItem {
private:
	string neckline, sleeveLength;
public:
	TopClothes() : neckline("Default"), sleeveLength("Default") {}
	TopClothes(string n, string s, double p, int q, string neck, string length) : ClothingItem(n, s, p, q), neckline(neck), sleeveLength(length) {}
};