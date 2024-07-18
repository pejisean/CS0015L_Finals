#include "customer.h"

// Constructor to initialize Customer
Customer::Customer(int id = 0, const string& name = "", const string& address = "") {
    Customer_ID = id;
    Name = name;
    Address = address;
};

//Customer ADT Functions

//Function to show Customer details
void Customer::showDetails() {
    cout << "Customer ID: " << Customer_ID << "\nCustomer Name: " << Name
        << "\nAddress: " << Address << endl;
}

// Function to add a customer to the queue
void Customer::addCustomer(Bikestore &store, int id, string name, string address) {
    store.customers.push_back(CustomerRent(id, name, address));
    cout << "Customer added successfully";
}

// Function to show customer details by ID
void Customer::showCustomerDetails(Bikestore &store, int CustomerID) {
    for (deque<CustomerRent>::iterator it = store.customers.begin(); it != store.customers.end(); ++it) {
        if (it->Customer_ID == CustomerID) {
            it->showDetails();
            return;
        }
    }
    cout << "Customer not found";
}

// Function to print the list of all customers
void Customer::printAllCustomers(Bikestore& store) {
    for (deque<CustomerRent>::iterator it = store.customers.begin(); it != store.customers.end(); ++it) {     
        it->showDetails();
        return;
    }
}

void Customer::listBikesRentedByCustomer(Bikestore& store, int CustomerID) {
    for (deque<CustomerRent>::iterator it = store.customers.begin(); it != store.customers.end(); ++it) {
        if (it->Customer_ID == CustomerID) {
            it->displayRentedBikes();
            return;
        }
    }
}
