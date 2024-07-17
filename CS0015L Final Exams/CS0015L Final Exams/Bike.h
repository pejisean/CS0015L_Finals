#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Bike {
private:
    int bikeID;
    string bikeName;
    int quantity;
    bool rentStatus;
public:
    // Constructor
    Bike(int id, string name, int qty);

    // Function to show bike details
    void showDetails() const;

    // Overload comparison operators for sorting
    bool operator<(const Bike& other) const {
        return bikeID < other.bikeID;
    }
    bool operator==(int id) const {
        return bikeID == id;
    }
};
