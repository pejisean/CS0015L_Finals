#include "Bike.h"

// Constructor  
Bike::Bike(int id, string name, int qty){
    bikeID = id;
    bikeName = name;
    quantity = qty;
}
// Function to show bike details
void Bike::showDetails(){
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
                        store.saveCustomers();
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