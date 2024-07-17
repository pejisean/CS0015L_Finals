// CS0015L Final Exams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <queue>
#include "Bike.h"
#include "customer.h"
#include "bike_customer.h"

using namespace std;

#define repeat(a,x) for(int i=0; i<=x; i++){ cout << a;}



//Customer ADT Functions

// Function to add a customer to the queue
void addCustomer(queue<Customer>&customerQueue, int& nextID) {
    string name, address;
    cout << "Enter the name of the customer: ";
    getline(cin, name);
    cout << "Enter the address of the customer: ";
    getline(cin, address);
    Customer newCustomer(nextID++, name, address);
    customerQueue.push(newCustomer);
    cout << "Customer added: ID=" << nextID++ << ", Name=" << name << ", Address=" << address << endl;
}

// Function to show customer details by ID
void showCustomerDetails(const queue<Customer>&customerQueue, int id) {
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

// Function to search for a customer by ID
void searchCustomer(const queue<Customer>&customerQueue, int id) {
    queue<Customer> tempQueue = customerQueue;
    while (!tempQueue.empty()) {
        Customer customer = tempQueue.front();
        if (customer.Customer_ID == id) {
            cout << "Customer found:" << endl;
            cout << "Customer ID: " << customer.Customer_ID << endl;
            cout << "Name: " << customer.Name << endl;
            cout << "Address: " << customer.Address << endl;
            return;
        }
        tempQueue.pop();
    }
    cout << "Customer not found!" << endl;
}

// Function to remove a customer by ID
void removeCustomer(queue<Customer>&customerQueue, int id) {
    queue<Customer> tempQueue;
    bool found = false;

    while (!customerQueue.empty()) {
        Customer customer = customerQueue.front();
        customerQueue.pop();
        if (customer.Customer_ID == id) {
            found = true;
            cout << "Customer removed:" << endl;
            cout << "Customer ID: " << customer.Customer_ID << endl;
            cout << "Name: " << customer.Name << endl;
            cout << "Address: " << customer.Address << endl;
        }
        else {
            tempQueue.push(customer);
        }
    }

    // Refill the original queue with remaining customers
    while (!tempQueue.empty()) {
        customerQueue.push(tempQueue.front());
        tempQueue.pop();
    }

    if (!found) {
        cout << "Customer not found!" << endl;
    }
}

// Function to print the list of all customers
void printAllCustomers(const queue<Customer>&customerQueue) {
    queue<Customer> tempQueue = customerQueue;
    while (!tempQueue.empty()) {
        Customer customer = tempQueue.front();
        cout << "Customer ID: " << customer.Customer_ID << ", Name: " << customer.Name << ", Address: " << customer.Address << endl;
        tempQueue.pop();
    }
}

// Function to search for a customer by ID using linear search on a queue
void searchCustomer(queue<Customer> customerQueue, int id) {
    bool found = false;
    Customer foundCustomer(0, "", "");

    while (!customerQueue.empty() && !found) {
        Customer current = customerQueue.front();
        customerQueue.pop();

        if (current.Customer_ID == id) {
            found = true;
            foundCustomer = current;
        }
    }

    if (found) {
        cout << "Customer found:" << endl;
        cout << "Customer ID: " << foundCustomer.Customer_ID << endl;
        cout << "Name: " << foundCustomer.Name << endl;
        cout << "Address: " << foundCustomer.Address << endl;
    }
    else {
        cout << "Customer not found!" << endl;
    }
}




//Function to display the Menu
void menu() {
    Customer customers;
    int choice = 0;
    int num = 0;
    

    while (choice != 8) {
        repeat('=', 20);
        cout << endl;
        cout << '\t' << "MENU" << endl;
        repeat('=', 20);
        cout << endl;

        cout << "1. Add Bike" << endl;
        cout << "2. Rent a Bike" << endl;
        cout << "3. Return Bike" << endl;
        cout << "4. Show Bike Details" << endl;
        cout << "5. Display All Bikes" << endl;
        cout << "6. Check Bike Availability" << endl;
        cout << "7. Customer Maintenance" << endl;
        cout << "8. Exit" << endl;



        cin >> choice;
        switch (choice) {
        case 1:
            //Add New Bike
            break;
        case 2:
            //Rent a Bike
            break;
        case 3:
            //Return Bike
            break;
        case 4:

           //Show Bike Details
            break;
        case 5:
            //Display all Bikes
            break;
        case 6:
            //Check Bike Availability
            break;
        case 7:
            //Customer Maintenance
            system("CLS");
            while (!num) {
                repeat('=', 20);
                cout << endl;
                cout << '\t' << "MENU" << endl;
                repeat('=', 20);
                cout << endl;

                cout << "1. Add New Customer" << endl;
                cout << "2. Show Customer Details" << endl;
                cout << "3. List of Bikes rented by Customer" << endl;

                cin >> num;

                switch (num) {
                    
                case 1:
                    cout << "test";
                    //Add new Customer
                    break;
                case 2:
                    //Show Customer Details
                    break;
                case 3:
                    //List of Bikes Rented by Customer
                    break;
                }
            }
            break;
        case 8:
            //Exit
            break;
        default:
            break;
        }
        cout << "\nPress any key to continue...\n";
        _getch();
        system("CLS");
    }
}

int main()
{
    menu();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
