#pragma once

#include <string>

#include "Ingredient.h"

using namespace std;

class Bread : public Ingredient {
private:
	string type;
	string name;
	double amount;
	string madeOf; //zbo¿e
	bool  gluten;
public:
	Bread() {}
	Bread(string n, double a, string m, bool g);
};