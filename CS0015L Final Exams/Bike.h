#pragma once
#include <iostream>
#include <string>

using namespace std;
struct Bike
{
public:
    int bikeID;
    string bikeName;
    int quantity;
    bool rentStatus;

    // Constructor
    Bike(int id, string name, int qty)
        : bikeID(id), bikeName(name), quantity(qty), rentStatus(false) {}
};

