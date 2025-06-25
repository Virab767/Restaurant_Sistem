#pragma once
#include <iostream>
#include <vector>
//#include "Customer.h"
#include <string>
#include "Dish.h"
class Customer;
class Order {
private:
	Customer* customer;
	std::vector<Dish*> orderedDishes;
	double totalPrice;
public:
	Order(Customer* _customer);
	Order(const Order& other);
	Order& operator=(const Order& other);
	Order(Order&& other) noexcept;
	Order& operator=(Order&& other) noexcept;
	~Order() = default;

	double get_totalPrice() const;
	void calculateTotal();
	void addDish(Dish* dish);
	void displayOrder() const;

};

