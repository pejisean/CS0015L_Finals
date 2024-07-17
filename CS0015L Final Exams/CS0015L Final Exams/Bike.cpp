#include "Bike.h"

// Constructor  
Bike::Bike(int id, string name, int qty){
    bikeID = id;
    bikeName = name;
    quantity = qty;
}
// Function to show bike details
void Bike::showDetails() const {
    cout << "Bike ID: " << bikeID << "\nBike Name: " << bikeName
        << "\nQuantity: " << quantity << "\nRent Status: " << (rentStatus ? "Rented" : "Available") << endl;
}