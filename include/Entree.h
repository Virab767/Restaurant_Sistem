#pragma once
#include <iostream>
#include "Dish.h"
class Entree : public Dish {
private:
	int calories;
public:
	Entree(std::string dishname, double dishprice, int _calories);
	void display() const;
	int get_calories() const;
};
