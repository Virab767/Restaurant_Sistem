#include <iostream>
#include "Menu.h"
#include "Dish.h"
#include "Appetizer.h"
#include "Entree.h"
#include "Dessert.h"

Menu::Menu(const Menu& other) {
   /* for (Dish* dish : other.dishes) {
        dishes.push_back(new Dish(*dish));
    }*/
    for (Dish* dish : other.dishes) {
        if (dynamic_cast<Appetizer*>(dish)) {
            dishes.push_back(new Appetizer(*dynamic_cast<Appetizer*>(dish)));
        }
        else if (dynamic_cast<Entree*>(dish)) {
            dishes.push_back(new Entree(*dynamic_cast<Entree*>(dish)));
        }
        else if (dynamic_cast<Dessert*>(dish)) {
            dishes.push_back(new Dessert(*dynamic_cast<Dessert*>(dish)));
        }
    }

}

Menu& Menu::operator=(const Menu& other) {
    if (this == &other) return *this;
    for (Dish* dish : other.dishes) delete dish;
        dishes.clear();
        for (Dish* dish : other.dishes) {
            if (dynamic_cast<Appetizer*>(dish)) {
                dishes.push_back(new Appetizer(*dynamic_cast<Appetizer*>(dish)));
            }
            else if (dynamic_cast<Entree*>(dish)) {
                dishes.push_back(new Entree(*dynamic_cast<Entree*>(dish)));
            }
            else if (dynamic_cast<Dessert*>(dish)) {
                dishes.push_back(new Dessert(*dynamic_cast<Dessert*>(dish)));
            }
        }
        return *this;
}

Menu::Menu(Menu&& other) noexcept : dishes(std::move(other.dishes)) {}
Menu& Menu::operator=(Menu&& other) noexcept {
    if (this != &other) {
        for (Dish* dish : dishes) delete dish;
        dishes = std::move(other.dishes);
    }
    return *this;
}
Menu::~Menu() {
    for (Dish* dish : dishes) delete dish;
}

void Menu::displayMenu() const {
    std::cout << "=== Menu ===" << std::endl;
    for (const Dish* dish : dishes) dish->display();
}

void Menu::addDish(Dish* dish) {
    dishes.push_back(dish);
}

Dish* Menu::getDishByName(const std::string& dishname) const {
    for (Dish* dish : dishes) {
        if (dish->get_name() == dishname) {
            return dish;
        }
    }
    return nullptr;
}
