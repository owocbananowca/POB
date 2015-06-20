#include <iostream>
#include <fstream>

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

void Fruit::SaveToTxt() {
	fstream file;
	file.open("CookBook.txt", fstream::in);
	file << type << endl
		<< name << endl
		<< amount << endl;
	file.close();
}