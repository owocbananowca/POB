#include <iostream>
#include <algorithm>
#include <fstream>

#include "CookBook.h"
#include "Recipe.h"
#include "AllIngredients.h"

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
	if (recipes.size() != 0) {
		cout << "Przepisy:\n";
		for (size_t i = 0; i < recipes.size(); i++) {
			recipes[i].ListRecipe();
		}
		cout << "Przepisy wypisane\n";
	}
	else {
		cout << "Brak przepisow w ksiazce\n";
	}
}

void CookBook::FindRecipe(string rName) {
	if (recipes.size() != 0) {
		for (size_t i = 0; i < recipes.size(); i++) {
			if (recipes[i].GetName() == rName) {
				cout << "Znaleziono przepis:\n";
				recipes[i].ListRecipe();
				break; //Zakladam ze nazwy si� nie powtarzaja
			}
			else {
				cout << "Brak przepisu o nazwie: " << rName << endl;
			}
		}
	}
	else  {
		cout << "Brak przepisow w ksiazce\n";
	}
}

void CookBook::FindIngredient(string iName) {
	bool found = false;
	if (recipes.size() != 0) {
		for (size_t i = 0; i < recipes.size(); i++) {
			for (size_t j = 0; j < recipes[i].GetIngredientsSize(); j++) {
				if (recipes[i].GetIngredientName(j) == iName) {
					cout << "Znaleziono:\n";
					recipes[i].ListRecipe();
					cout << "\n\n";
					found = true;
				}
			}
		}
		if (found == false){
			cout << "Brak przepisu ze skladnikiem: " << iName << endl;
		}
	}
	else {
		cout << "Brak przepisow w ksiazce\n";
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
				recipes.erase(recipes.begin() + i);
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
	ofstream file;
	file.open("CookBook.txt", ofstream::trunc | ofstream::in); //in - zapis,  truc - wyczyszczenie, out - odczyt
	if (file.good() == true) {
		//file << name << endl;		mia�em zapamietywac nazwe ale skoro to jest jedna ksiazka kucharska to nie ma sensu
		file.close();			//	dlatego tylko sprawdzam czy da sie zapisac i czyszcze poprzednia zawartosc
		for (size_t i = 0; i < recipes.size(); i++) {
			recipes[i].SaveRecipe();
		}
		cout << "Zapisano\n";
	}
	else {
		cout << "Error, brak dostepu do pliku\n";
	}
}

/*
void CookBook::LoadBook() {
	// Jakby wszystkie sk�adniki mia�y tyle samo argument�w(takich samych)  by�oby �atwo ale raczej nie o to chodzi :v
	ifstream file;
	file.open("CookBook.txt", ifstream::in);
	if (file.is_open() == true) {
		vector<string> temp;// = new string[];
		string temp2;
		int i = 0;
		while (file.eof() != true) {
			getline(file, temp2);//Caly txt do tablicy string
			temp.push_back(temp2);
			i++;
		}
		file.close();  //Wczytany plik to zamykamy
		//Prawdopodobnie tworzone obiekty
		Recipe rec;
		Bread br;
		Dairy dr;
		Fruit fr;
		Meat me;
		Seasoning se;
		Vegetable ve;
		Ingredient* in = nullptr;
		//Potrzebne zmienne do tworzenia obiektow
		string s1, s2, s3;
		double d1;
		bool b1, tempB = false;
		bool recStart = true;
		//Tablica z danymi...
		//Brzydkie, niebezpieczne, brak lepszego pomyslu
		for (auto j = 0; j <= temp.size(); j++) {
			if (temp[j] == ";") { //trafiamy na ";" - koniec przepisu
				recipes.push_back(rec); //push przepis do vectora
				tempB = true;
			}
			if (tempB == false && recStart == true) { //false - trafilismy na srednik
				s1 = temp[j]; //nazwa przep
				s2 = temp[j + 1]; //opis przep
				d1 = stoi(temp[j + 2]); //czas przyg
				j += 3; //a fuj
				rec = Recipe(s1, s2, d1);
				recStart = false;
			}
			if (tempB == false && recStart == false) { //jestesmy po sredniku ale wczytalismy dane przepisu
				//6x if() aby rozpoznac skladnik i utworzyc odp obiekt, 7. jesli nie zgadzaja nam sie dane
				if (temp[j] == "Bread") {
					s1 = temp[j + 1];
					d1 = stoi(temp[j + 2]);
					s2 = temp[j + 3];
					if (temp[j+4] == "0") {
						b1 = false;
					}
					else {
						b1 = true;
					}
					in = new Bread(s1,d1,s2,b1);
					rec.pushIngredient(in);
					j += 4; //a fuj, +4 bo for sam zwi�kszy o 1 zaraz :v
				}
				else if (temp[j] == "Dairy") {
					s1 = temp[j + 1];
					d1 = stoi(temp[j + 2]);
					s2 = temp[j + 3];
					in = new Dairy(s1,d1,s2);
					rec.pushIngredient(in);
					j += 3;
				}
				else if (temp[j] == "Fruit") {
					s1 = temp[j + 1];
					d1 = stoi(temp[j + 2]);
					in = new Fruit(s1, d1);
					rec.pushIngredient(in);
					j += 2;
				}
				else if (temp[j] == "Meat") {
					s1 = temp[j + 1];
					d1 = stoi(temp[j + 2]);
					s2 = temp[j + 3];
					in = new Meat(s1,d1,s2);
					rec.pushIngredient(in);
					j += 3;
				}
				else if (temp[j] == "Seasoning") {
					s1 = temp[j + 1];
					d1 = stoi(temp[j + 2]);
					s2 = temp[j + 3];
					in = new Seasoning(s1, d1, s2);
					rec.pushIngredient(in);
					j += 3;
				}
				else  if (temp[j] == "Vegetable") {
					s1 = temp[j + 1];
					d1 = stoi(temp[j + 2]);
					if (temp[j + 3] == "0") {
						b1 = false;
					}
					else {
						b1 = true;
					}
					in = new Vegetable(s1, d1, b1);
					rec.pushIngredient(in);
					j += 3;
				}
				else {
					cout << "Cos poszlo nie tak\n";
					//in = nullptr;
				}
			}
			tempB = false;
		}
		delete in;
		//delete[] temp;
	}
	else {
		cout << "Error, brak dostepu\n";
	}
}
*/

void CookBook::LoadBook() {
	ifstream file;
	file.open("CookBook.txt", ifstream::in);
	if (file.is_open() == true) {
		vector<string> temp;			//Vector na zawartosc pliku
		string temp2;
		while (file.eof() != true) {
			getline(file, temp2);		//Caly txt do tablicy string
			temp.push_back(temp2);
		}
		file.close();
		cout << "Wczytano do vectora\n";
		//Prawdopodobnie tworzone obiekty
		Recipe rec;			Bread br;
		Dairy dr;			Fruit fr;
		Meat me;			Seasoning se;
		Vegetable ve;		Ingredient* in = nullptr;
		//Potrzebne zmienne do tworzenia obiektow
		string s1, s2, s3;	double d1;
		bool b1;
		bool readRecipe = true;
		int tempI = 0;
		for (size_t i = 0; i < temp.size(); /*sam musze o to dbac*/ ) {
			cout << "Przebiegi petli: " << i << endl;
			if (readRecipe == true) {
				cout << "Dane przepisu\n";
				s1 = temp[i];
				s2 = temp[i + 1];
				d1 = stoi(temp[i + 2]);
				readRecipe = false;
				i += 3;
				rec = Recipe(s1, s2, d1);	//dane przepisu
			}
			else if (temp[i] == ";") {		//�rednik ko�czy ka�dy przepis
				cout << "Koniec przepisu, natrafiono na ;\n";
				readRecipe = true;
				recipes.push_back(rec);		//wpychamy przepis do vectora
				if (temp[i + 1] == "") {	//Pusta linia = ostatnia linia w pliku txt
					break;
				}
				else {
					i++;
				}
			}
			else { //else tylko dla czytelno�ci 0o
				cout << "Rozpoznanie skladnika\n";
				if (temp[i] == "Bread") {
					s1 = temp[i + 1];
					d1 = stoi(temp[i + 2]);
					s2 = temp[i + 3];
					if (temp[i + 4] == "0") {
						b1 = false;
					}
					else {
						b1 = true;
					}
					in = new Bread(s1,d1,s2,b1);
					rec.pushIngredient(in);
					i += 8; //8 parametrow, wchodzimy na kolejny
							//kt�rym b�dzie ; albo cos z tych if
				}
				else if (temp[i] == "Dairy") {
					s1 = temp[i + 1];
					d1 = stoi(temp[i + 2]);
					s2 = temp[i + 5];
					in = new Dairy(s1, d1, s2);
					rec.pushIngredient(in);
					i += 8;
				}
				else if (temp[i] == "Fruit") {
					s1 = temp[i + 1];
					d1 = stoi(temp[i + 2]);
					in = new Fruit(s1, d1);
					rec.pushIngredient(in);
					i += 8;
				}
				else if (temp[i] == "Meat") {
					s1 = temp[i + 1];
					d1 = stoi(temp[i + 2]);
					s2 = temp[i + 5];
					in = new Meat(s1, d1, s2);
					rec.pushIngredient(in);
					i += 8;
				}
				else if (temp[i] == "Seasoning") {
					s1 = temp[i + 1];
					d1 = stoi(temp[i + 2]);
					s2 = temp[i + 6];
					in = new Seasoning(s1, d1, s2);
					rec.pushIngredient(in);
					i += 8;
				}
				else if (temp[i] == "Vegetable") {
					s1 = temp[i + 1];
					d1 = stoi(temp[i + 2]);
					if (temp[i + 4] == "0") {
						b1 = false;
					}
					else {
						b1 = true;
					}
					in = new Vegetable(s1, d1, b1);
					rec.pushIngredient(in);
					i += 8;
				}
			}
		}
	}
	else {
		cout << "Error, brak dostepu do pliku\n";
	}
}