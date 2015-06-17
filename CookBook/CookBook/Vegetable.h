#pragma once

#include <string>

#include "Ingredient.h"

using namespace std;

class Vegetable: public Ingredient {
private:
	string type;
	string name;
	double amount;
	bool vegetable; //true - warzywo, false - jarzyna, warzywo wymaga obróbki cieplnej a jarzyna nie
public:
	Vegetable() {}
	Vegetable(string name, double amount, bool vegetable);
	void ListIngredient();
	string GetMyName();
};