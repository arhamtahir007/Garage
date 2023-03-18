//
// Created by HP on 3/18/2023.
//

#include "Vehicle.h"

void Vehicle::generalInput(){
    cout<<"\nEnter no of Doors:\n";
    cin>>noOfDoors;
    cout<<"Enter no of Seats:\n";
    cin>>noOfSeats;
    cout<<"Enter no of Tyres:\n";
    cin>>noOfTyres;
    cout<<"Enter Engine Capacity:\n";
    cin>>engineCC;
    gI:
    cout<<"Enter Transmission Type:\n";
    cin>>transmissionType;
    if (transmissionType != "auto" && transmissionType != "Auto" && transmissionType != "manual" && transmissionType != "Manual"){
        cout<<"Enter \"Auto\" or \"Manual\" only.\n";
        goto gI;
    }
    cout<<"Enter Registration Number:\n";
    cin>>numPlate;
    cout<<"Enter Color:\n";
    cin>>color;
}

void Vehicle::generalOutput() const {
    cout<<"\nVehicle Type: "<<vehicleType<<endl;
    cout<<"Engine Capacity: "<<engineCC<<" CC"<<endl;
    cout<<"Transmission Type: "<<transmissionType<<endl;
    cout<<"Number of Doors: "<<noOfDoors<<endl;
    cout<<"Number of Seats: "<<noOfSeats<<endl;
    cout<<"Number of Tyres: "<<noOfTyres<<endl;
    cout<<"Registration Number: "<<numPlate<<endl;
}
