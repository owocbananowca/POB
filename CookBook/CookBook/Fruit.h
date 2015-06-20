#pragma once

#include <string>

#include "Ingredient.h"

using namespace std;

class Fruit : public Ingredient {
private:
	string type;
	string name;
	double amount;
public:
	Fruit() {}
	Fruit(string n, double a);
	void ListIngredient();
	string GetMyName();
	void SaveToTxt();
};