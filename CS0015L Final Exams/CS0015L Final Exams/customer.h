#pragma once
#include <iostream>
#include <string>
#include <queue>

using namespace std;

// Structure to hold customer information
struct Customer {
    friend void showCustomerDetails(const queue<Customer>& customerQueue, int id);
    friend void searchCustomer(const queue<Customer>& customerQueue, int id);
    friend void removeCustomer(queue<Customer>& customerQueue, int id);
    friend void printAllCustomers(const queue<Customer>& customerQueue);
    friend void searchCustomer(queue<Customer> customerQueue, int id);


private:
    int Customer_ID;
    string Name;
    string Address;

public:
    // Constructor to initialize Customer
    Customer(int id = 0, const string& name = "", const string& address = "");
};

