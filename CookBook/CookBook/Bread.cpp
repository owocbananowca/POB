#include <iostream>
#include <fstream>

#include "Bread.h"

Bread::Bread(string n, double a, string m, bool g) {
	this->amount = a;
	this->gluten = g;
	this->madeOf = m;
	this->name = n;
	this->type = "bread";
}

void Bread::ListIngredient() {
	cout << name << endl
		<< amount << endl
		<< madeOf << endl;
	if (gluten == true) {
		cout << "Zawiera gluten\n";
	}
	else {
		cout << "Bezglutenowy\n";
	}
}

string Bread::GetMyName() {
	return name;
}

void Bread::SaveToTxt() {
	fstream file;
	file.open("CookBook.txt", fstream::in);
	file << type << endl
		<< name << endl
		<< amount << endl
		<< madeOf << endl
		<< gluten << endl;
	file.close();
}