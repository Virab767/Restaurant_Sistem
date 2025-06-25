#include <iostream>
#include "Dish.h"
#include "Dessert.h"


Dessert::Dessert(std::string dishname, double dishprice, bool _containsNuts) :Dish(dishname, dishprice), containsNuts(_containsNuts) {}
void Dessert::display() const {
	std::cout << "Dessert: " << name << " - $" << price << (containsNuts ? " (Contains Nuts)" : "") << std::endl;
}
