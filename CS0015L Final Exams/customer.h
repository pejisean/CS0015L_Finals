#pragma once
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Structure to hold customer information
struct Customer {
    int Customer_ID;
    string Name;
    string Address;

    // Constructor to initialize Customer
    Customer(int id = 0, const string& name = "", const string& address = "") {
        Customer_ID = id;
        Name = name;
        Address = address;
    }
};