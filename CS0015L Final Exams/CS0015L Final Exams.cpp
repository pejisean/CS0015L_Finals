// CS0015L Final Exams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <conio.h>
#include <queue>
#include <list>
#include <fstream>
#include <string>

using namespace std;

#define repeat(a,x) for(int i=0; i<=x; i++){ cout << a;}

class BikeStore;

//Bike ADT
class Bike {
public:
    int bikeID;
    string bikeName;
    int quantity;
    bool rentStatus;
    // Constructor
    Bike(int id, string name, int qty) : bikeID(id), bikeName(name), quantity(qty) {};

    //Display Bike;
    void showDetails();

    //Insert Bike into queue
    static void insertBike(class Bikestore& store, int id, string name, int quantity);

    //Rent Bike to Customer
    static void rentBike(class Bikestore& store, int customerID, int bikeID);

    //Return Bike from Customer
    static void returnBike(class Bikestore& store, int customerID);

    //Show Bike Details
    static void showBikeDetails(class Bikestore& store, int bikeID);

    //Display all Bikes
    static void displayAllBikes(class Bikestore& store);

    //Check Bike Availability
    static void checkBikeAvailability(class Bikestore& store, int bikeID);

};

class Customer {

public:
    int Customer_ID;
    string Name;
    string Address;
    // Constructor to initialize Customer
    Customer(int id, string name, string address) : Customer_ID(id), Name(name), Address(address) {};

    void showDetails();
    static void addCustomer(class Bikestore& store, int id, string name, string address);
    static void showCustomerDetails(class Bikestore& store, int CustomerID);
    static void printAllCustomers(class Bikestore& store);
    static void listBikesRentedByCustomer(class Bikestore& store, int CustomerID);
};

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


// Function to show bike details
void Bike::showDetails() {
    cout << "Bike ID: " << bikeID << "\nBike Name: " << bikeName
        << "\nQuantity: " << quantity << "\nRent Status: " << (rentStatus ? "Rented" : "Available") << endl;
}

//Insert Bike into queue
void Bike::insertBike(Bikestore& store, int id, string name, int quantity) {
    store.bikes.push_back(Bike(id, name, quantity));
    store.saveBikes();
    cout << "Bike added successfully";
}

//Rent Bike to Customer
void Bike::rentBike(Bikestore& store, int customerID, int bikeID) {
    for (deque<Bike>::iterator it = store.bikes.begin(); it != store.bikes.end(); it++) {
        if (it->bikeID == bikeID) {
            it->showDetails();
            if (it->quantity > 0) {
                it->quantity--;
                for (deque<CustomerRent>::iterator cit = store.customers.begin(); cit != store.customers.end(); ++cit) {
                    if (cit->Customer_ID == customerID) {
                        cit->rentBike(bikeID);
                        store.saveBikes();
                        store.saveCustomerRents();
                        cout << "Bike rented successfully." << endl;
                        return;

                    }
                }
                cout << "Customer not found." << endl;
                return;
            }
            cout << "Bike not available." << endl;
            return;
        }
    }
    cout << "Bike not found." << endl;
}

//Return Bike from Customer
void Bike::returnBike(Bikestore& store, int customerID) {
    for (deque<CustomerRent>::iterator cit = store.customers.begin(); cit != store.customers.end(); ++cit) {
        if (cit->Customer_ID == customerID) {
            cit->displayRentedBikes();
            for (list<int>::iterator it = cit->bikesRented.begin(); it != cit->bikesRented.end(); ++it) {
                for (deque<Bike>::iterator bit = store.bikes.begin(); bit != store.bikes.end(); ++bit) {
                    if (bit->bikeID == *it) {
                        bit->quantity++;
                    }
                }
            }
            cit->returnAllBikes();
            store.saveBikes();
            store.saveCustomerRents();
            cout << "All Bikes returned successfully." << endl;
            return;
        }
    }
    cout << "Customer not found." << endl;
}

//Show Bike Details
void Bike::showBikeDetails(Bikestore& store, int bikeID) {
    for (deque<Bike>::iterator it = store.bikes.begin(); it != store.bikes.end(); ++it) {
        if (it->bikeID == bikeID) {
            it->showDetails();
            return;
        }
    }
}

//Display all Bikes
void Bike::displayAllBikes(Bikestore& store) {
    for (deque<Bike>::iterator it = store.bikes.begin(); it != store.bikes.end(); ++it) {
        it->showDetails();
        cout << endl;
    }
}

//Check Bike Availability
void Bike::checkBikeAvailability(Bikestore& store, int bikeID) {
    for (deque<Bike>::iterator it = store.bikes.begin(); it != store.bikes.end(); ++it) {
        if (it->bikeID == bikeID) {
            it->showDetails();
            cout << "Number of Bikes available: " << it->quantity << endl;
            if (it->quantity > 0) {
                cout << "Status: Available" << endl;
                it->rentStatus = true;
            }
            else {
                cout << "Status: Unavailable" << endl;
                it->rentStatus = false;
            }
            return;
        }
    }
    cout << "Bike not found." << endl;
}


//Customer ADT Functions

//Function to show Customer details
void Customer::showDetails() {
    cout << "Customer ID: " << Customer_ID << "\nCustomer Name: " << Name
        << "\nAddress: " << Address << endl;
}

// Function to add a customer to the queue
void Customer::addCustomer(Bikestore& store, int id, string name, string address) {
    store.customers.push_back(CustomerRent(id, name, address));
    store.saveCustomers();
    cout << "Customer added successfully";
}

// Function to show customer details by ID
void Customer::showCustomerDetails(Bikestore& store, int CustomerID) {
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


//Rent Bikes to Customer
void CustomerRent::rentBike(int bikeID) {
    bikesRented.push_back(bikeID);
}
//Return Bikes rented by Customer
void CustomerRent::returnBike(int bikeID) {
    bikesRented.remove(bikeID);
}
//Display all Rented Bikes by customer
void CustomerRent::displayRentedBikes() const {
    cout << "Bikes rented by Customer ID " << Customer_ID << ":\n";
    for (list<int>::const_iterator it = bikesRented.begin(); it != bikesRented.end(); ++it) {
        cout << "Bike ID: " << *it << endl;
    }
}

//Returns all Rented Bikes from Customer
void CustomerRent::returnAllBikes() {
    bikesRented.clear();
}

void Bikestore::loadBikes() {
    ifstream inFile("bikes.txt");
    if (!inFile) {
        cerr << "Error opening bikes file." << endl;
        return;
    }

    int id;
    int qty;
    string bikeName;
    while (inFile >> id) {
        inFile.ignore();
        getline(inFile, bikeName);
        inFile >> qty;
        bikes.push_back(Bike(id, bikeName, qty));
    }
    inFile.close();
}
void Bikestore::loadCustomers() {
    ifstream inFile("customers.txt");
    if (!inFile) {
        cerr << "Error opening customers file" << endl;
        return;
    }

    int id;
    string name, address;
    while (inFile >> id) {
        inFile.ignore();
        getline(inFile, name);
        getline(inFile, address);
        customers.push_back(CustomerRent(id, name, address));
    }
    inFile.close();
}

void Bikestore::loadCustomerRents() {
    ifstream inFile("customer_rents.txt");
    if (!inFile) {
        cerr << "Error opening customer rents file" << endl;
        return;
    }

    int bike_id;
    int customer_id;
    while (inFile >> customer_id >> bike_id) {
        for (deque<CustomerRent>::iterator it = customers.begin(); it != customers.end(); ++it) {
            if (it->Customer_ID == customer_id) {
                it->rentBike(bike_id);
                break;
            }
        }
    }
    inFile.close();
}
void Bikestore::saveBikes() {
    ofstream outFile("bikes.txt");
    if (!outFile) {
        cerr << "Error opening bikes file for writing";
        return;
    }

    for (deque<Bike>::iterator it = bikes.begin(); it != bikes.end(); ++it) {
        outFile << it->bikeID << endl << it->bikeName << endl << it->quantity << endl;
    }
    outFile.close();
}
void Bikestore::saveCustomers() {
    ofstream outFile("customers.txt");
    if (!outFile) {
        cerr << "Error opening customers file for writing";
        return;
    }

    for (deque<CustomerRent>::iterator it = customers.begin(); it != customers.end(); ++it) {
        outFile << it->Customer_ID << endl << it->Name << endl << it->Address << endl;
    }
    outFile.close();
}
void Bikestore::saveCustomerRents() {
    ofstream outFile("customer_rents.txt");
    if (!outFile) {
        cerr << "Error opening customer rents file for writing";
        return;
    }

    for (deque<CustomerRent>::iterator it = customers.begin(); it != customers.end(); ++it) {
        for (list<int>::iterator bit = it->bikesRented.begin(); bit != it->bikesRented.end(); ++bit) {
            outFile << it->Customer_ID << endl << " " << *bit << endl;
        }

    }
    outFile.close();
}

//Menu Function
void Bikestore::menu() {
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
        case 1: {
            //Add New Bike
            int id;
            string bikeName;
            int quantity;
            cout << "Enter Bike ID: ";
            cin >> id;
            cout << "Enter Bike Name: ";
            cin.ignore();
            getline(cin, bikeName);
            cout << "Enter quantity of bikes: ";
            cin >> quantity;
            Bike::insertBike(*this, id, bikeName, quantity);
            break;
        }
        case 2:
            //Rent a Bike
        {
            int customerID, bikeID;
            cout << "Enter Customer ID: ";
            cin >> customerID;
            char rentAgain;
            do {
                cout << "Enter Bike ID: ";
                cin >> bikeID;
                Bike::rentBike(*this, customerID, bikeID);
                cout << "Do you want to rent another? (Y/N): ";
                cin >> rentAgain;
            } while (rentAgain == 'y' || rentAgain == 'Y');
            break;
        }
        case 3:
            //Return Bike
        {
            int CustomerID;
            cout << "Enter Customer's ID: ";
            cin >> CustomerID;
            Bike::returnBike(*this, CustomerID);
            break;
        }
        case 4:

            //Show Bike Details
        {
            int BikeID;
            cout << "Enter the ID of the bike you want to see details of: ";
            cin >> BikeID;
            Bike::showBikeDetails(*this, BikeID);
            break;
        }
        case 5:
            //Display all Bikes
        {
            Bike::displayAllBikes(*this);
            break;
        }
        case 6:
        {
            //Check Bike Availability
            int BikeID;
            cout << "Enter the ID of the Bike you want to see it's availability of: ";
            cin >> BikeID;
            Bike::checkBikeAvailability(*this, BikeID);
            break;
        }
        case 7:
                //Customer Maintenance
                system("CLS");

                repeat('=', 20);
                cout << endl;
                cout << '\t' << "Bike Rental Menu" << endl;
                repeat('=', 20);
                cout << endl;

                cout << "1. Add New Customer" << endl;
                cout << "2. Show Customer Details" << endl;
                cout << "3. List of Bikes rented by Customer" << endl;

                cin >> num;

                switch (num) {

                case 1:
                {
                    //Add new Customer
                    int CustomerID;
                    string name, address;
                    cout << "Enter the ID you want to identify the customer with: ";
                    cin >> CustomerID;
                    cout << "Enter Customer's name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Customer's Address: ";
                    getline(cin, address);
                    Customer::addCustomer(*this, CustomerID, name, address);
                    break;
                }
                case 2:

                {
                    //Show Customer Details
                    int CustomerID;
                    cout << "Enter the ID of the Customer you want to view: ";
                    cin >> CustomerID;
                    Customer::showCustomerDetails(*this, CustomerID);

                    break;
                }
                case 3:
                {
                    //List of Bikes Rented by Customer
                    int CustomerID;
                    cout << "Enter the ID of the Customer you want to view the rental history of: ";
                    cin >> CustomerID;
                    Customer::listBikesRentedByCustomer(*this, CustomerID);
                    break;
                }
            break;
            case 8:
                //Exit
                cout << "Exiting program...\n";
                break;
            default:
               
                cout << "Please input a number from 1-8...";
                break;
            }
            cout << "\nPress any key to continue...\n";
            _getch();
            system("CLS");
        }
    }
}


int main()
{
    Bikestore store;
    store.menu();
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
