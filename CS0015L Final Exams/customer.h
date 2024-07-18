#pragma once
#include "BikeStore.h"
#include <iostream>
#include <string>
#include <queue>


using namespace std;

// Structure to hold customer information
struct Customer {

public:
    int Customer_ID;
    string Name;
    string Address;
    // Constructor to initialize Customer
    Customer(int id = 0, const string& name = "", const string& address = "");

    void showDetails();
    static void addCustomer(class Bikestore &store, int id, string name, string address);
    static void showCustomerDetails(class Bikestore& store, int CustomerID);
    static void printAllCustomers(class Bikestore& store);
    static void listBikesRentedByCustomer(class Bikestore& store, int CustomerID);
};

