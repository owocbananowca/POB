#include <iostream>
#include <fstream>

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

string Dairy::GetMyName() {
	return name;
}

void Dairy::SaveToTxt() {
	fstream file;
	file.open("CookBook.txt", fstream::in);
	file << type << endl
		<< name << endl
		<< amount << endl
		<< animal << endl;
	file.close();
}