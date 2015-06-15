#include <iostream>
#include <algorithm>

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
	getline(cin, a);
	cout << "Podaj opis przygotowania\n";
	getline(cin, b);
	cout << "Podaj czas przygotowania\n";
	cin >> m; cin.ignore();
	rec.AddRecipe(a, b, m);
	recipes.push_back(rec);
}

void CookBook::ListAll() {
	cout << name << "\n";
	//cout << recipes.size() << endl;
	cout << "Przepisy:\n";
	for (size_t i = 0; i < recipes.size(); i++) {
		//cout << "for recipes\n";
		recipes[i].ListRecipe();
	}
	cout << "Przepisy wypisane\n";
}