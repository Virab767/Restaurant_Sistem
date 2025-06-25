#pragma once
#include "Order.h"
#include "Dish.h"
#include "Customer.h"
#include "Menu.h"
#include "Entree.h"
#include "Dessert.h"
#include "Appetizer.h"
#include <iostream>
#include <vector>

class Restaurant {
private:
	Menu menu;
	std::vector <Customer*> customers;
	std::vector<Order> orders;
public:
	Restaurant();
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);
	Restaurant(Restaurant&& other) noexcept;
	Restaurant& operator=(Restaurant&& other) noexcept;
	~Restaurant();

	void showMenu() const;
	Customer* getCustomerByname(const std::string& name);
	void placeNewOrder(const std::string& customerName);
	void viewCustomerOrderHistory(const std::string& customerName) ;
	Menu* get_menu();
};
