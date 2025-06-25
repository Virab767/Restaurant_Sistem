// tests/RestaurantTests.cpp
#include <gtest/gtest.h>
#include <sstream>
#include "../include/Restaurant.h"
#include "../include/Customer.h"
#include "../include/Order.h"
#include "../include/Dish.h"
#include "../include/Menu.h"
#include "../include/Appetizer.h"
#include "../include/Entree.h"
#include "../include/Dessert.h"

class RestaurantTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Ինիցիալիզացնել Menu-ն մի քանի ճաշատեսակներով
        menu->addDish(new Appetizer("Caesar Salad", 5.99,true));
        menu->addDish(new Entree("Grilled Salmon", 18.99,15));
        menu->addDish(new Dessert("Cheesecake", 6.99,false));
    }

    void TearDown() override {
        delete menu;
    }

    Menu* menu = new Menu();
    Restaurant restaurant;
};

// Թեստ 1: Ստուգել նոր հաճախորդի ավելացումը
TEST_F(RestaurantTest, AddNewCustomer) {
    std::stringstream input("anna@example.com\ndone\n");
    std::cin.rdbuf(input.rdbuf());

    restaurant.placeNewOrder("Anna");
    Customer* customer = restaurant.getCustomerByname("Anna");
    ASSERT_NE(customer, nullptr);
    EXPECT_EQ(customer->get_name(), "Anna");
}

// Թեք 2: Ստագել պատվերի ստեղծումը և ճաշատեսակների ավելացումը
TEST_F(RestaurantTest, CreateOrderWithDishes) {
    Customer* customer = new Customer("Bob", "bob@example.com");
    Order order(customer);

    order.addDish(new Appetizer("Caesar Salad", 5.99,true));
    order.addDish(new Entree("Grilled Salmon", 18.99,15));
    order.calculateTotal();

    EXPECT_DOUBLE_EQ(order.get_totalPrice(), 5.99 + 18.99);

    delete customer;
}

// Թեք 3: Ստագել դատարկ պատվերի ընդհանուր գումարը
TEST_F(RestaurantTest, CalculateTotalEmptyOrder) {
    Customer* customer = new Customer("Charlie", "charlie@example.com");
    Order order(customer);
    order.calculateTotal();

    EXPECT_DOUBLE_EQ(order.get_totalPrice(), 0.0);

    delete customer;

}

TEST_F(RestaurantTest, CustomerOrderHistory) {
    Customer* customer = new Customer("David", "david@example.com");
    Order* order1 = new Order(customer);
    order1->addDish(new Appetizer("Caesar Salad", 5.99,true));
    order1->calculateTotal();

    Order* order2 = new Order(customer);
    order2->addDish(new Entree("Grilled Salmon", 18.99,12));
    order2->calculateTotal();

    customer->placeOrder(std::unique_ptr<Order>(order1));
    customer->placeOrder(std::unique_ptr<Order>(order2));

    testing::internal::CaptureStdout();
    customer->viewOrderHistory();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Caesar Salad") != std::string::npos);
    EXPECT_TRUE(output.find("Grilled Salmon") != std::string::npos);

    delete customer;

}


// Թեստ 5: Ստուգել Restaurant::placeNewOrder-ի ֆունկցիոնալությունը
TEST_F(RestaurantTest, PlaceNewOrder) {
    std::stringstream input;
    input << "david@example.com\n"; // Contact info
    input << "Caesar Salad\nGrilled Salmon\ndone\n"; // Dishes
    std::cin.rdbuf(input.rdbuf());

    testing::internal::CaptureStdout();
    restaurant.placeNewOrder("David");
    std::string output = testing::internal::GetCapturedStdout();

    Customer* customer = restaurant.getCustomerByname("David");
    ASSERT_NE(customer, nullptr);
    EXPECT_EQ(customer->get_name(), "David");

    testing::internal::CaptureStdout();
    customer->viewOrderHistory();
    output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Caesar Salad") == std::string::npos);
    EXPECT_TRUE(output.find("Grilled Salmon") == std::string::npos);
    EXPECT_TRUE(output.find("Total: $24.98,false") != std::string::npos);
}
