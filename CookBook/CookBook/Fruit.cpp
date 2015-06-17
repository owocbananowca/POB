#include <iostream>

#include "Fruit.h"

Fruit::Fruit(string n, double a) {
	this->amount = a;
	this->name = n;
	this->type = "Fruit";
}

void Fruit::ListIngredient() {
	cout << name << endl
		<< amount << endl;
}

string Fruit::GetMyName() {
	return name;
}