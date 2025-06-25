#include <iostream>
#include "Dish.h"

Dish::Dish(std::string _name, double _price) :name(_name), price(_price) {}
Dish::Dish(const Dish& other) {
	name = other.name;
	price = other.price;
}

Dish& Dish::operator=(const Dish& other) {
	if (this == &other) return *this;
	name = other.name;
	price = other.price;
	return *this;
}

Dish::Dish(Dish&& other) noexcept {
	name = std::move(other.name);
	price = std::move(other.price);
}

Dish& Dish::operator=(Dish&& other) noexcept {
	if (this == &other) return *this;
	name = std::move(other.name);
	price = std::move(other.price);
}

void Dish::display() const {
	std::cout << name << "-$" << price << std::endl;
}
std::string Dish::get_name() const {
	return name;
}

double Dish::get_price() const {
	return price;
}
