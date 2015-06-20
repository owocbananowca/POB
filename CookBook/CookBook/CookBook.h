#pragma once

#include <string>
#include <vector>

#include "Recipe.h"
#include "AllIngredients.h"

using namespace std;

class CookBook {
private:
	string name;
	//int amount;
	vector<Recipe> recipes;
public:
	CookBook() {}
	CookBook(string name);

	void CreateBook(string name);
	//ListBook
	void ListAll(); //k

	void SaveBook();
	void LoadBook();

	void AddRecipe(); //k
	void FindIngredient(string name); //k
	void FindRecipe(string name); //k
	void DeleteRecipe(string name); //k
};