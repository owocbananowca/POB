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
		<< infoType << endl;
}

string Seasoning::GetMyName() {
	return name;
}

void Seasoning::SaveToTxt() {
	ofstream file;
	file.open("CookBook.txt", ofstream::in | ofstream::app);
	file << type << endl
		<< name << endl
		<< amount << endl
		<< infoType << endl;
	file.close();
}