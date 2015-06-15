#include <iostream>

#include "Dairy.h"

Dairy::Dairy(string n, double a, string an) {
	this->amount = a;
	this->animal = an;
	this->name = n;
	this->type = "Dairy";
}

void Dairy::ListIngredient() {
	cout << name << endl
		<< amount << endl
		<< animal << endl;
}