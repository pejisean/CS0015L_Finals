#pragma once
#include <iostream>
#include <queue> // Include queue for storing rented bike IDs
#include "customer.h"

using namespace std;

// Define the derived class bike_customer inheriting from customer
class bike_customer : public Customer {
public:
    queue<int> bikesRented; // Use queue to store rented bike IDs
};