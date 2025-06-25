#pragma once
#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include "Order.h"

class Customer {
	std::string name;
	std::string contactinfo;
	std::vector<std::unique_ptr<Order>> orderhistory;
public:
	Customer(std::string _name, std::string _contactinfo);
	Customer(const Customer& other);
	Customer& operator=(const Customer& other);
	Customer(Customer&& other) noexcept;
	Customer& operator=(Customer&& other) noexcept;
	~Customer() = default;

	std::string get_name()const;
	void placeOrder(std::unique_ptr<Order> order);
	void viewOrderHistory() const;

};
