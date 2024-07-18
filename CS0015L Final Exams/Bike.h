#pragma once
#include "BikeStore.h"
#include <iostream>
#include <string>
#include <queue>
#include <list>


using namespace std;

struct Bike {
public:
    int bikeID;
    string bikeName;
    int quantity;
    bool rentStatus;
    // Constructor
    Bike(int id, string name, int qty);

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
