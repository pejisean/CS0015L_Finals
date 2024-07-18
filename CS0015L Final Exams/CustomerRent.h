#pragma once
#include "customer.h"
#include <iostream>
#include <list> // Include queue for storing rented bike IDs


using namespace std;

// Define the derived class bike_customer inheriting from customer
class CustomerRent : public Customer {
public:
    list<int> bikesRented; // Use queue to store rented bike IDs

    CustomerRent(int id, string name, string address) : Customer(id, name, address) {}

    //Rent Bikes to Customer
    void rentBike(int bikeID);
    //Return Bikes rented by Customer
    void returnBike(int bikeID);
    //Display all Rented Bikes by customer
    void displayRentedBikes() const;

    //Returns all Rented Bikes from Customer
    void returnAllBikes();
};