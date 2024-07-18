#include "CustomerRent.h"



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