#include <iostream>
#include "Order.h"
#include "Customer.h"



Customer::Customer(std::string _name, std::string _contactinfo) :name(_name),contactinfo(_contactinfo) {}
Customer::Customer(const Customer& other) :name(other.name),contactinfo(other.contactinfo) {
	for (const auto& order : other.orderhistory) {
		orderhistory.push_back(std::make_unique<Order>(*order));
	}
}
Customer& Customer::operator=(const Customer& other) {
	if (this == &other) return *this;
	name = other.name;
	contactinfo = other.contactinfo;
	for (const auto& order : other.orderhistory) {
		orderhistory.push_back(std::make_unique<Order>(*order));
	}
	return *this;
}
Customer::Customer(Customer&& other)noexcept :name(std::move(other.name)),contactinfo(std::move(other.contactinfo)),orderhistory(std::move(other.orderhistory)){}
Customer& Customer::operator=(Customer&& other) noexcept {
	if (this == &other) return *this;
	orderhistory.clear();
	name = std::move(other.name);
	contactinfo = std::move(other.contactinfo);
	orderhistory = std::move(other.orderhistory);
	return *this;
}

std::string Customer::get_name() const { return name; }
void Customer::placeOrder(std::unique_ptr<Order> order) {
	orderhistory.push_back(std::move(order));
}
void Customer::viewOrderHistory() const {
	std::cout << name << "'s Order History:\n";
	for (const auto&  order : orderhistory) order->displayOrder();
}
