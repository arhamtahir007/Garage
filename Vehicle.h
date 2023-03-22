//
// Created by HP on 3/18/2023.
//

#ifndef GARAGE_VEHICLE_H
#define GARAGE_VEHICLE_H

#endif //GARAGE_VEHICLE_H
//#pragma once
#include<iostream>
#include <fstream>
using namespace std;

class Vehicle{
protected:
    int noOfDoors;
    int noOfTyres;
    int noOfSeats;
    int engineCC;
    int noOfFaults;
    string numPlate;
    string color;
    string transmissionType;
    string* fault;
    string vehicleType;
public:
    Vehicle(){
        noOfDoors = 0;
        noOfSeats = 0;
        noOfTyres = 0;
        engineCC = 0;
        numPlate = "";
        color = "";
        transmissionType = "";
        fault = nullptr;
        noOfFaults = 0;
        vehicleType = "";
    }
    ~Vehicle(){
        delete[] fault;
    }

    void generalInput();
    void generalOutput() const;

    virtual void vehicleReturn() = 0;//ye polymorphism k liye hai sab apni spni class m is ka
                                     //function bananah. Refrence k liye SportsCar dekh lena
};