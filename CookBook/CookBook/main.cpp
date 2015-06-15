#include <conio.h>

#include "CookBook.h"

#include "Recipe.h"

int main() {
	//Menu
	CookBook c("ksiazka kucharska 1.0");
	c.AddRecipe();
	c.ListAll();

	_getch();
	return 0;
}