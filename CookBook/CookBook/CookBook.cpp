#include <iostream>

#include "CookBook.h"

using namespace std;

CookBook::CookBook(string name) {
	this->name = name;
}

void CookBook::CreateBook(string name){
	int amount = 0;
	CookBook::CookBook(name);
}

void CookBook::AddRecipe() {
	Recipe rec;
	string a, b;
	int m;
	cout << "Podaj nazwe przepisu\n";
	cin >> a; cin.ignore();
	cout << "Podaj opis przygotowania\n";
	cin >> b; cin.ignore();
	cout << "Podaj czas przygotowania\n";
	cin >> m; cin.ignore();
	rec.AddRecipe(a, b, m);
}