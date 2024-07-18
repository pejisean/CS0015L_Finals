#pragma once
#include "Bike.h"
#include "customer.h"
#include "CustomerRent.h"
#include <iostream>
#include <conio.h>
#include <queue>
#include <fstream>

#define repeat(a,x) for(int i=0; i<=x; i++){ cout << a;}


class Bikestore {
private:
    deque<Bike> bikes;
    deque<CustomerRent> customers;
    int bikeCounter;
    int customerCounter;
public:
    Bikestore() : bikeCounter(0), customerCounter(0) {
        loadBikes();
        loadCustomers();
        loadCustomerRents();
    }

    void loadBikes();
    void loadCustomers();
    void loadCustomerRents();
    void saveBikes();
    void saveCustomers();
    void saveCustomerRents();
    void menu(); //declare Menu Function

    friend struct Bike;
    friend struct Customer;
};

