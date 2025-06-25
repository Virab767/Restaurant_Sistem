# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(RestaurantOrderingSystem)

# Սահմանել C++ ստանդարտը
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Google Test-ի ճանապարհներ
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Հիմնական նախագծի include ճանապարհ
include_directories(include)

# Հիմնական ֆայլեր
set(SOURCES
    src/Customer.cpp
    src/Order.cpp
    src/Dish.cpp
    src/Menu.cpp
    src/Restaurant.cpp
    src/Appetizer.cpp
    src/Entree.cpp
    src/Dessert.cpp
)

# Հիմնական ծրագիր
add_executable(Restaurant src/main.cpp ${SOURCES})

# Թեքային ծրագիր
enable_testing()
add_executable(RestaurantTests tests/RestaurantTests.cpp ${SOURCES})
target_link_libraries(RestaurantTests GTest::GTest GTest::Main pthread)
add_test(NAME RestaurantTests COMMAND RestaurantTests)
