#include <iostream>
#include <fstream>

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

string Meat::GetMyName() {
	return name;
}

void Meat::SaveToTxt() {
	ofstream file;
	file.open("CookBook.txt", ofstream::in | ofstream::app);
	file << type << endl
		<< name << endl
		<< amount << endl
		<< animal << endl;
	file.close();
}