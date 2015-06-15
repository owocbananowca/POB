#include <iostream>

#include  "Seasoning.h"

Seasoning::Seasoning(string n, double a, string i) {
	this->amount = a;
	this->infoType = i;
	this->type = "Seasoning";
	this->name = n;
}

void Seasoning::ListIngredient() {
	cout << name << endl
		<< amount << endl
		<< type << endl;
}