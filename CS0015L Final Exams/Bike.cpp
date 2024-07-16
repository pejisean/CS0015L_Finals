#include "Bike.h"

// Function to show bike details
void showDetails() {
    cout << "Bike ID: " << bikeID << "\nBike Name: " << bikeName
        << "\nQuantity: " << quantity << "\nRent Status: " << (rentStatus ? "Rented" : "Available") << endl;
}