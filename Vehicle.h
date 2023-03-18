//
// Created by HP on 3/18/2023.
//

#ifndef GARAGE_VEHICLE_H
#define GARAGE_VEHICLE_H

#endif //GARAGE_VEHICLE_H
#include<iostream>
using namespace std;

class Vehicle{
protected:
    int noOfDoors;
    int noOfTyres;
    int noOfSeats;
    int engineCC;
    string numPlate;
    string color;
    string transmissionType;
    int fuelTankCapacity;
    int groundClearance;
public:
    Vehicle(){
        noOfDoors = 0;
        noOfSeats = 0;
        noOfTyres = 0;
        engineCC = 0;
        numPlate = "";
        color = "";
        transmissionType = "";
        fuelTankCapacity = 0;
        groundClearance = 0;
    }
};