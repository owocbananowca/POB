#include <iostream>
#include <fstream>

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

string Seasoning::GetMyName() {
	return name;
}

void Seasoning::SaveToTxt() {
	fstream file;
	file.open("CookBook.txt", fstream::in);
	file << type << endl
		<< name << endl
		<< amount << endl
		<< infoType << endl;
	file.close();
}