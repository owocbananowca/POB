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
	void AddRecipe(string n, string d, int m);
	//ListRecipe
	void ListRecipe();

	void FindIngredient(string name);
	void FindRecipe(string name);
	string GetName();
};