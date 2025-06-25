#pragma once
#include <iostream>
#include "Dish.h"

class Dessert : public Dish {
private:
	bool containsNuts;
public:
	Dessert(std::string dishname, double dishprice, bool _containsNuts);
	void display() const;

};
