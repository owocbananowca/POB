#include "Bread.h"

Bread::Bread(string n, double a, string m, bool g) {
	this->amount = a;
	this->gluten = g;
	this->madeOf = m;
	this->name = n;
	this->type = "bread";
}