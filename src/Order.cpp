#include <iostream>
#include "Order.h"
#include "Customer.h"
#include "Dish.h"

Order::Order(Customer* _customer) :customer(_customer), totalPrice{0.0} {}
Order::Order(const Order& other) : customer(other.customer), totalPrice(other.totalPrice) {
	for (Dish* dish : other.orderedDishes) {
		orderedDishes.push_back(dish);
	}
}

Order& Order::operator=(const Order& other) {
	if (this == &other) return *this;
	customer = other.customer;
	totalPrice = other.totalPrice;
	orderedDishes = other.orderedDishes;
	return *this;
}

Order::Order(Order&& other) noexcept :customer(std::move(other.customer)),totalPrice(std::move(other.totalPrice)),orderedDishes(std::move(orderedDishes)){}
Order& Order::operator=(Order&& other) noexcept {
	if (this == &other) return *this;
	customer = std::move(other.customer);
	totalPrice = std::move(other.totalPrice);
	orderedDishes = std::move(orderedDishes);
	return *this;
}

double Order::get_totalPrice() const { return totalPrice; }
void Order::calculateTotal() {
	totalPrice = 0.0;
	for (Dish* dish : orderedDishes) totalPrice += dish->get_price();
}
void Order::addDish(Dish* dish) {
	orderedDishes.push_back(dish);
}
void Order::displayOrder() const {
	std::cout << "Order for " << customer->get_name() << ":\n";
	for (const Dish* dish : orderedDishes) dish->display();
	std::cout << "Total: $" << totalPrice << "\n\n";
}
