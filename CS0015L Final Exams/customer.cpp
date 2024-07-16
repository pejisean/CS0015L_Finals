#include "customer.h"

// Function to add a customer to the queue
void addCustomer(queue<Customer>& customerQueue, int& nextID) {
    string name, address;
    cout << "Enter the name of the customer: ";
    getline(cin, name);
    cout << "Enter the address of the customer: ";
    getline(cin, address);
    Customer newCustomer(nextID++, name, address);
    customerQueue.push(newCustomer);
    cout << "Customer added: ID=" << newCustomer.Customer_ID << ", Name=" << newCustomer.Name << ", Address=" << newCustomer.Address << endl;
}

// Function to show customer details by ID
void showCustomerDetails(const queue<Customer>& customerQueue, int id) {
    queue<Customer> tempQueue = customerQueue;
    while (!tempQueue.empty()) {
        Customer customer = tempQueue.front();
        if (customer.Customer_ID == id) {
            cout << "Customer ID: " << customer.Customer_ID << endl;
            cout << "Name: " << customer.Name << endl;
            cout << "Address: " << customer.Address << endl;
            return;
        }
        tempQueue.pop();
    }
    cout << "Customer not found!" << endl;
}

// Function to print the list of all customers
void printAllCustomers(const queue<Customer>& customerQueue) {
    queue<Customer> tempQueue = customerQueue;
    while (!tempQueue.empty()) {
        Customer customer = tempQueue.front();
        cout << "Customer ID: " << customer.Customer_ID << ", Name: " << customer.Name << ", Address: " << customer.Address << endl;
        tempQueue.pop();
    }
}
