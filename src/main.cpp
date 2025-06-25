#include "Restaurant.h"
#include <iostream>

int main() {
    Restaurant restaurant;

    // Օրինակ՝ ավելացնել ճաշացանկ
    restaurant.showMenu();
    restaurant.get_menu()->addDish(new Appetizer("Salad", 5.99, true));
    restaurant.showMenu();
    restaurant.get_menu()->addDish(new Entree("Steak", 15.99, 800));
    restaurant.showMenu();
    restaurant.get_menu()->addDish(new Dessert("Cake", 4.99, false));
    restaurant.showMenu();

    // Ցուցադրել ճաշացանկը
    restaurant.showMenu();

    // Պատվեր կատարել
    restaurant.placeNewOrder("Alice");

    // Դիտել պատվերների պատմությունը
    restaurant.viewCustomerOrderHistory("Alice");

    return 0;
}
