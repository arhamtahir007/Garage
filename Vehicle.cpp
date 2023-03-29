#include "Vehicle.h"

void Vehicle::generalInput(){
    cout<<"\nEnter no of Doors:\n";//bat suno apni apni Car k operator overloading m apni car k mutabik
    cin>>noOfDoors;                // doors, seats, or tyres k check laga dena refrence k liye SportsCar ki cpp
    cout<<"Enter no of Seats:\n";  // file m cin ki operator over loading check karo....
    cin>>noOfSeats;                // :D I believe in you ( ´･･)ﾉ(._.`)
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
    cin.ignore();
    cout<<"Enter briefly about Faults in "<<vehicleType<<":\n";
    getline(cin,fault);
}

void Vehicle::generalOutput() const {
    cout<<"\nVehicle Type: "<<vehicleType<<endl;
    cout<<"Engine Capacity: "<<engineCC<<" CC"<<endl;
    cout<<"Transmission Type: "<<transmissionType<<endl;
    cout<<"Number of Doors: "<<noOfDoors<<endl;
    cout<<"Number of Seats: "<<noOfSeats<<endl;
    cout<<"Number of Tyres: "<<noOfTyres<<endl;
    cout<<"Registration Number: "<<numPlate<<endl;
    cout<<"Faults: "<<fault<<endl;
}


