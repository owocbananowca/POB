#pragma once

#include <string>

#include "Ingredient.h"

using namespace std;

class Dairy : public Ingredient {
private:
	string type;
	string name;
	double amount;
	string animal;
public:
	Dairy() {}
	Dairy(string n, double a, string an);
	void ListIngredient();
	string GetMyName();
};