#include "bikeList.h"


void addBike(int ) {
    bikesRented.push(bikeID); // Add bikeID to rented bikes
}

void returnBike(int bikeID) {
    // Remove bikeID from rented bikes
    queue<int> temp;
    while (!bikesRented.empty()) {
        int currentBikeID = bikesRented.front();
        bikesRented.pop();
        if (currentBikeID != bikeID) {
            temp.push(currentBikeID);
        }
    }
    bikesRented = temp;
}

void displayBikes() {
    // Display rented bikes for the customer
    cout << "Bikes rented by Customer " << customerID << ":\n";
    queue<int> temp = bikesRented;
    while (!temp.empty()) {
        cout << "Bike ID: " << temp.front() << "\n";
        temp.pop();
    }
}

void clearBikes() {
    while (!bikesRented.empty()) {
        bikesRented.pop();
    }
}