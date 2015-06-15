#include <iostream>

#include "Recipe.h"
#include "AllIngredients.h"

using namespace std;

Recipe::Recipe(string n, string d,   int m) {
	this->name = n;
	this->descripction = d;
	this->minutes = m;
}

string Recipe::GetName() {
	return name;
}

void Recipe::AddRecipe(string n, string d, int m) {
	Recipe(n, d, m);
	char temp = 0;
	while (temp != '7') {
		cout << "Podaj kategorie skladniku?\n"
			<< "1. Pieczywo\n"
			<< "2. Nabial\n"
			<< "3. Owoc\n"
			<< "4. Warzywo\n"
			<< "5. Mieso\n"
			<< "6. Przyprawa\n"
			<< "7. Koniec\n";
		cin >> temp;
		cin.ignore();
		string a, b;
		double  c;
		bool d;
		switch (temp) {
		case '1':
			system("cls");
			cout << "Podaj nazwe pieczywa\n";
			cin >> a; cin.ignore();
			cout << "Podaj ilosc skladnika(g)\n";
			cin >> c; cin.ignore();
			cout << "Podaj rodzaj zboza\n";
			cin >> b; cin.ignore();
			cout << "Czy zawiera gluten?\n1. Tak\n2. Nie\n";
			cin >> temp; cin.ignore();
			switch (temp) {
			case '1':
				d = true;
				break;
			case '2':
				d = false;
				break;
			}
			ingredients.push_back(new Bread(a, c, b, d));
			break;
		case '2':
			system("cls");
			cout << "Podaj nazwe przetworu\n";
			cin >> a; cin.ignore();
			cout << "Podaj ilosc skladnika(g)\n";
			cin >> c; cin.ignore();
			cout << "Od jakiego zwierzecia pobrano produkt?\n";
			cin >> b; cin.ignore();
			ingredients.push_back(new Dairy(a,c,b));
			break;
		case '3':
			system("cls");
			cout << "Podaj nazwe owocu\n";
			cin >> a; cin.ignore();
			cout << "Podaj ilosc skladnika(g)\n";
			cin >> c; cin.ignore();
			ingredients.push_back(new Fruit(a,c));
			break;
		case '4':
			system("cls");
			cout << "Podaj nazwe warzywa\n";
			cin >> a;  cin.ignore();
			cout << "Podaj ilosc skladnika(g)\n";
			cin >> c; cin.ignore();
			cout << "Czy wa¿ywo wymaga obrobki cieplnej(jest jarzyna)\n1. Tak\n2. Nie\n";
			cin >> temp; cin.ignore();
			switch (temp) {
			case '1':
				d = true;
				break;
			case '2':
				d = false;
				break;
			}
			ingredients.push_back(new Vegetable(a,c,d));
			break;
		case '5':
			system("cls");
			cout << "Podaj nazwe miesa\n";
			cin >> a; cin.ignore();
			cout << "Podaj ilosc skladnika(g)\n";
			cin >> c; cin.ignore();
			cout << "Podaj pochodzenie miesa(drob,wolowina, itd)\n";
			cin >> b; cin.ignore();
			ingredients.push_back(new Meat(a, c, b));
			break;
		case '6':
			system("cls");
			cout << "Podaj nazwe przyprawy\n";
			cin >> a; cin.ignore();
			cout << "Podaj ilosc skladnika(g)\n";
			cin >> c; cin.ignore();
			d = true;
			while (d == true) {
				cout << "Podaj typ przyprawy (korzenna, warzywna, ziolowa, inna)\n";
				cin >> b; cin.ignore();
				cout << b << "\n";
				if ((b == "inna") || (b == "korzenna") || (b == "warzywna") || (b == "ziolowa")) {
					d = false;
					ingredients.push_back(new Seasoning(a, d, b));
				}
				else {
					cout << "Niepoprawny typ, chcesz sprobowac ponownie?\n"
						<< "1. Tak\n"
						<< "2. Nie\n";
					cin >> temp;
					switch (temp) {
					case '1':
						system("cls");
						d = true;
						break;
					case '2':
						d = false;
						break;
					}
				}
			}
			break;
		case '7':
			system("cls");
			break;
		}
	}
}

void Recipe::ListIngredient() {
	cout << name << "\n";
	for (Ingredient* i : ingredients) {
		i->ListIngredient();
	}
}

