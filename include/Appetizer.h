#pragma once 
#include <iostream>
#include "Dish.h"
class Appetizer :public Dish {
private:
	bool is_spicy;
public:
	Appetizer(std::string dishname, double dishprice, bool _is_spicy);
	void display() const;
	bool get_is_spicy() const;
};
