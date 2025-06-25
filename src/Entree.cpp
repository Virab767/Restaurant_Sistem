#include <iostream>
#include "Dish.h"
#include "Entree.h"

Entree::Entree(std::string dishname, double dishprice, int _calories) :Dish(dishname, dishprice), calories(_calories) {}
void Entree::display() const {
	std::cout << "Entree: " << name << " - $" << price << ", " << calories << " calories" << std::endl;
}
