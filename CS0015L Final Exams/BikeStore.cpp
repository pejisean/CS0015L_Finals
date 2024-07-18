#include "BikeStore.h"




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
                }
            }
            break;
        case 8:
            //Exit
            cout << "Exiting program...\n";
            break;
        default:
            break;
        }
        cout << "\nPress any key to continue...\n";
        _getch();
        system("CLS");
    }
};
