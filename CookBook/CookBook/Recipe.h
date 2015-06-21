#pragma once

#include <string>
#include <vector>

#include "Ingredient.h"

using namespace std;

class Recipe {
private:
	string name;
	string descripction;
	int minutes;
	vector<Ingredient*> ingredients;
public:
	Recipe() {}
	Recipe(string name, string description, int minutes);
	void AddRecipe(string n, string d, int m); //k
	//ListRecipe
	void ListRecipe(); //k
	string GetName(); //k
	size_t GetIngredientsSize(); //k
	string GetIngredientName(size_t i); //k

	void SaveRecipe();
	//void LoadRecipe(fstream file);

	void pushIngredient(Ingredient* i);
};