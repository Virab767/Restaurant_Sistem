#include <iostream>
#include "Dish.h"
#include "Appetizer.h"

Appetizer::Appetizer(std::string dishname, double dishprice, bool _is_spicy) :Dish(dishname, dishprice), is_spicy(_is_spicy) {}
void Appetizer::display() const {
	std::cout << "Appetizer: " << name << " - $" << price << (is_spicy ? " (Spicy)" : "") << std::endl;
}
bool Appetizer::get_is_spicy() const {
	return is_spicy;
}
