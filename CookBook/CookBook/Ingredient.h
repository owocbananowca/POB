#pragma once

//#include "AllIngredients.h"

using namespace std;

class Ingredient/*: public Seasoning, public Dairy, public Vegetable, public Fruit, public Meat, public Bread*/ {
//Klasa paskuda, �eby zrobi� �adny vector na sk�adniki
public:
	Ingredient() {}
	virtual void ListIngredient() = 0;
	virtual string GetMyName() = 0;
};