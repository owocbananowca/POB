#pragma once

#include "Ingredient.h"

#include <string>

using namespace std;

class Seasoning : public Ingredient {
private:
	string type;
	string name;
	double amount;
	string infoType; //inna, korzenna, warzywna, zio³owa
public:
	Seasoning() {}
	Seasoning(string n, double a, string i);
	void ListIngredient();
};