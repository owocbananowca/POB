#include <conio.h>

#include "CookBook.h"

#include "Recipe.h"

int main() {
	//Menu
	CookBook c = CookBook("ksiazka");
	c.AddRecipe();
	c.ListIngredient();

	_getch();
	return 0;
}