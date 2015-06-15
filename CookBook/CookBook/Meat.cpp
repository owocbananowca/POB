#include <iostream>

#include "Meat.h"

Meat::Meat(string n, double a, string an) {
	this->type = "Meat";
	this->name = n;
	this->amount = a;
	this->animal = an;
}

void Meat::ListIngredient() {
	cout << name << endl
		<< amount << endl
		<< animal << endl;
}