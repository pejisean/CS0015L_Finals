#pragma once
#include "customer.h"
#include <queue>
// Define the derived class bike_customer inheriting from customer
class bike_customer : public Customer {
public:
    queue<int> bikesRented; // Use queue to store rented bike IDs
};