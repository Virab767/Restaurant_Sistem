#pragma once
#include <iostream>

class Dish {
protected:
	std::string name;
	double price;
public:
	Dish() = default;
	Dish(std::string _name, double _price);
	Dish(const Dish& other);
	Dish(Dish&& other) noexcept;
	Dish& operator=(const Dish& other);
	Dish& operator=(Dish&& other) noexcept;
	virtual ~Dish() = default;
	virtual void display() const;
	double get_price() const;
	std::string get_name() const;
};
