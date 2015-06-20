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
	ofstream file;
	file.open("CookBook.txt", ofstream::in | ofstream::app);
	file << type << endl
		<< name << endl
		<< amount << endl
		<< animal << endl;
	file.close();
}