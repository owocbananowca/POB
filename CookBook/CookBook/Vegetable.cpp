#include <iostream>
#include <fstream>

#include "Vegetable.h"

Vegetable::Vegetable(string n, double a, bool v) {
	this->amount = a;
	this->name = n;
	this->type = "Vegetable";
	this->vegetable = v;
}

void Vegetable::ListIngredient() {
	cout << name << endl
		<< amount << endl;
	if (vegetable == true) {
		cout << "Warzywo\n";
	}
	else  {
		cout << "Jarzyna\n";
	}
}

string Vegetable::GetMyName() {
	return name;
}

void Vegetable::SaveToTxt() {
	ofstream file;
	file.open("CookBook.txt", ofstream::in | ofstream::app);
	file << type << endl
		<< name << endl
		<< amount << endl
		<< "-" << endl
		<< "-" << endl
		<< "-" << endl
		<< "-" << endl
		<< vegetable << endl;
	file.close();
}