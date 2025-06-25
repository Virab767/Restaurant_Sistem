#pragma once
#include <iostream>
#include <vector>
#include "Dish.h"

class Menu : public Dish {
private:
	std::vector<Dish*> dishes;
public:
	Menu()=default;
    Menu(const Menu& other);
    Menu& operator=(const Menu& other);
    Menu(Menu&& other) noexcept;
    Menu& operator=(Menu&& other) noexcept;
    ~Menu();

    void displayMenu() const;
    void addDish(Dish* dish);
    Dish* getDishByName(const std::string& dishName) const;
};
