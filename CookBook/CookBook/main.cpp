#include <iostream>

#include "CookBook.h"
#include "Recipe.h"

using namespace std;

int main() {
	CookBook c("ksiazka kucharska 1.0");
	char temp = 0;
	string tempS;
	while (temp != '8') {
		cout << "\n\nWitaj w programie ksiazka kucharska 1.0\nCo chcialbys zrobic?\n"
			<< "1. Wyswietl wszystkie przepisy\n"
			<< "2. Znajdz przepis (szukajac po nazwie przepisu)\n"
			<< "3. Znajdz przepisy (szukajac po nazwie skladnika)\n"
			<< "4. Dodaj nowy przepis\n"
			<< "5. Usun przepis (szukajac po nazwie przepisu)\n"
			<< "6. Zapisz zawartosc ksiazki do pliku txt\n"
			<< "7. Wczytaj zawartosc ksiazki z pliku txt\n"
			<< "8. Zakoncz dzialanie programu\n";
		cin >> temp;
		cin.ignore();
		switch (temp) {
		case '1':
			system("cls");
			c.ListAll();
			break;
		case '2':
			system("cls");
			cout << "Podaj nazwe przepisu, ktory chcesz znalezc\n";
			cin >> tempS;
			c.FindRecipe(tempS);
			break;
		case '3':
			system("cls");
			cout << "Podaj nazwe skladnika aby znalezc przepisy, ktore go zawieraja\n";
			cin >> tempS;
			c.FindIngredient(tempS);
			break;
		case '4':
			system("cls");
			c.AddRecipe();
			break;
		case '5':
			system("cls");
			cout << "Podaj nazwe przepisu do usuniecia\n";
			cin >> tempS;
			c.DeleteRecipe(tempS);
			break;
		case '6':
			system("cls");
			c.SaveBook();
			break;
		case '7':
			system("cls");
			c.LoadBook();
			break;
		case '8':
			system("cls");
			break;
		default:
			system("cls");
			cout << "Nie psuj\n";
			break;
		}
	}
	return 0;
}