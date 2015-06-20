#include <iostream>
#include <algorithm>
#include <fstream>

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

void CookBook::FindRecipe(string rName) {
	for (size_t i = 0; i < recipes.size(); i++) {
		if (recipes[i].GetName() == rName) {
			cout << "Znaleziono przepis:\n";
			recipes[i].ListRecipe();
			break; //Zakladam ze nazwy siê nie powtarzaja
		}
		else {
			cout << "Brak przepisu o nazwie: " << rName << endl;
		}
	}
}

void CookBook::FindIngredient(string iName) {
	bool found = false;
	for (size_t i = 0; i < recipes.size(); i++) {
		for (size_t j = 0; j < recipes[i].GetIngredientsSize(); j++) {
			if (recipes[i].GetIngredientName(j) == iName) {
				cout << "Znaleziono:\n";
				recipes[i].ListRecipe();
				cout << "\n\n";
				found == true;
			}
		}
	}
	if (found == false){
		cout << "Brak przepisu ze skladnikiem: " << iName << endl;
	}
}

void CookBook::DeleteRecipe(string rName) {
	bool temp2 = false;
	for (size_t i = 0; i < recipes.size(); i++) {
		if (recipes[i].GetName() == rName) {
			cout << "Znaleziono przepis:\n";
			temp2 = true;
			recipes[i].ListRecipe();
			cout << "Napewno chcesz usunac?\n1. Tak\n2. Nie\n";
			char temp;
			cin >> temp;
			switch (temp) {
			case '1':
				recipes.erase(recipes.begin() + i - 1);
				cout << "Usunieto\n";
				break;
			case '2':
				break;
			}
			break;
		}
	}
	if (temp2 == false) {
		cout << "Nie znaleziono takiego przepisu\n";
	}
}

void CookBook::SaveBook() {
	fstream file;
	file.open("CookBook.txt", fstream::in | fstream::trunc); //in - zapis,  truc - wyczyszczenie, out - odczyt
	if (file.good() == true) {
		file << name << endl;
		for (size_t i = 0; i < recipes.size(); i++) {
			recipes[i].SaveRecipe();
		}
	}
	else {
		cout << "Error, brak dostêpu do pliku\n";
	}
}