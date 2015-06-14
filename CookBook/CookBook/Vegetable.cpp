#include "Vegetable.h"

Vegetable::Vegetable(string n, double a, bool v) {
	this->amount = a;
	this->name = n;
	this->type = "Vegetable";
	this->vegetable = v;
}