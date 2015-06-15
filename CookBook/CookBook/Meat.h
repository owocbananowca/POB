#pragma once

#include <string>

#include "Ingredient.h"

using namespace std;

class Meat : public Ingredient {
private:
	string type;
	string name;
	double amount;
	string animal;
public:
	Meat() {}
	Meat(string n, double a, string an);
	void ListIngredient();
};