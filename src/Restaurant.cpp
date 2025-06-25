#include <iostream>
#include "Restaurant.h"

Restaurant::Restaurant() {}
Restaurant::Restaurant(const Restaurant& other):menu(other.menu),orders(other.orders){
	for (Customer* customer : other.customers) {
		customers.push_back(new Customer(*customer));
	}
}
Restaurant& Restaurant::operator=(const Restaurant& other) {
	if (this == &other) return *this;
	for (Customer* customer : customers) delete customer;
	customers.clear();
	menu = other.menu;
	orders = other.orders;
	for (Customer* customer : other.customers) {
		customers.push_back(new Customer(*customer));
	}
	return *this;
}
Restaurant::Restaurant(Restaurant&& other)noexcept :menu(std::move(other.menu)), customers(std::move(other.customers)), orders(std::move(other.orders)) {}
Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
	if (this == &other) return *this;
	for (Customer* customer : other.customers) delete customer;
	customers = std::move(other.customers);
	menu = std::move(other.menu);
	orders = std::move(other.orders);
	return *this;
}

Restaurant::~Restaurant() { for (Customer* customer : customers) delete customer; }
void Restaurant::showMenu() const {
	menu.displayMenu();
}

Customer* Restaurant::getCustomerByname(const std::string& name) {
	for (Customer* customer : customers) {
		if (customer->get_name() == name) return customer;
	}
	return nullptr;
}
void Restaurant::placeNewOrder(const std::string& customerName) {
	Customer* customer = getCustomerByname(customerName);
	if (!customer) {
		std::string contact;
		std::cout << "Enter contact info for" << customerName << ": ";
		std::cin >> contact;
		customer = new Customer(customerName, contact);
		customers.push_back(customer);
	}

	auto order_ptr = std::make_unique<Order>(customer);
	std::string dishName;
	std::cout << "Enter dish name (or 'done' to finish): ";
	while (std::cin >> dishName && dishName != "done") {
		Dish* dish = menu.getDishByName(dishName);
		if (dish) {
			order_ptr->addDish(dish);
		}
		else {
			std::cout << "Dish not found!" << std::endl;
		}
		std::cout << "Enter dish name (or 'done' to finish):";
	}
	order_ptr->calculateTotal();
	customer->placeOrder(std::make_unique<Order>(*order_ptr));
	orders.push_back(*order_ptr);
	
}

void Restaurant::viewCustomerOrderHistory(const std::string& customerName)  {
	 Customer* customer=getCustomerByname(customerName);
	 if (!customer) {
		 std::cout << "Customer not found!" << std::endl;
	 }
	 customer->viewOrderHistory();
}

Menu* Restaurant::get_menu() {
	return &menu;
}
