#pragma once

#include <string>
#include <vector>

#include "Recipe.h"

using namespace std;

class CookBook : Recipe {
private:
	string name;
	int amount;
	vector<Recipe> recipes;
public:
	CookBook() {}
	CookBook(string name);

	void CreateBook(string name);
	//ListBook
	void ListIngredient();
	void SaveBook();
	void LoadBook();

	void AddRecipe(); //recipe -> ingredient-> ...

	void FindIngredient(string name); //Recipe.FindIngredient(); wywo³aæ
	void FindRecipe(string name); //Recipe.FindRecipe(); wywo³aæ
};