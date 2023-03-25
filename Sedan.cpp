//
// Created by fajar.pk on 3/25/2023.
//

#include "Sedan.h"
void Sedan:: vehicleReturn() {   //virtual function call as in other car classes
    cout<<"Classification of Car: "<<vehicleType<<endl;
    cout<<"Registration Number: "<<numPlate<<endl;
    cout<<"Color: "<<color<<endl;
}
void Sedan:: dataReading() {
    Sedan car;
    string input;
    ifstream output("Sedan.txt");
    int noOfEntries = 0;
    while (!output.eof()) {
        getline(output, input);
        noOfEntries++;
    }
    output.close();
    string temp, type;
    cout << "Enter registration number:\n";
    cin >> temp;
    output.open("Sedan.txt", ios::in);
    for (int i = 0; i < noOfEntries; ++i) {
        output >> car.numPlate;
        output >> car.noOfDoors;
        output >> car.noOfTyres;
        output >> car.noOfSeats;
        output >> car.engineCC;
        output >> car.color;
        output >> car.transmissionType;
        output >> car.vehicleType;
        output >> type;
        output >> car.airBags;
        output >> car.powerLocks;
        output >> car.powerWindows;
        car.vehicleType = car.vehicleType + " " + type;
        getline(output, car.fault);
        if (car.numPlate == temp) {
            cout << car;
            return;
        }
    }
    cout << "Record Not Found.\n";
}
void Sedan::dataRecord() {
    ofstream input("Sedan.txt",ios::out | ios::app);
    input<<numPlate<<" "<<noOfDoors<<" "<<noOfTyres<<" "<<noOfSeats<<" "<<engineCC<<" "
         <<fault<<" "<<color<<" "<<transmissionType<<" "<<vehicleType<<" "<<airBags<<" "<<powerLocks<<" "<<powerWindows;

    input.close();
}


istream &operator >> (istream& input ,Sedan& car){
    car.generalInput();
    cout<<" enter number of airbags"<<endl;
    input>>car.airBags;

    cout<<" Enter type of Powerlocks"<<endl;  // door locking ability of car(single basically automatic system k bahir se lock hojaty hain or dual ka either way )

    input>>car.powerLocks;
    if(car.powerLocks!=" single"&& car.powerLocks!="Single"&&car.powerLocks!=" dual"&& car.powerLocks!="Dual")
    {
        cout<<"Enter \"single \" or \"dual\" only.\n";
        input>>car.powerLocks;
    }
    input>>car.powerWindows;// window locking ability of car(single basically automatic system k bahir se lock hojaty hain or dual ka either way )
    if(car.powerWindows!=" single"&& car.powerWindows!="Single"&&car.powerWindows!=" dual"&& car.powerWindows!="Dual")
    {
        cout<<"Enter \"single \" or \"dual\" only.\n";
        input>>car.powerWindows;
    }
    while(true) {
        if (car.noOfDoors!=4) {
            cout << "Invalid Number of Doors, Enter again.\n";
            cout << "Enter no of Doors:\n";
            input >> car.noOfDoors;

        } else

        break;
    }
    while(true) {
        if (car.noOfSeats != 5 ) {
            cout << "Invalid Number of Seats, Enter again.\n";
            cout << "Enter no of Seats:\n";
            input >> car.noOfSeats;

        }
        else
            break;
    }
    while(true) {
        if (car.noOfTyres != 4) {
            cout << "Invalid Number of Tyres, Enter again.\n";
            cout << "Enter no of Tyres:\n";
            input >> car.noOfTyres;

        } else

        break;
    }
    return input;




}

ostream &operator << (ostream& out,const Sedan& obj) {
    obj.generalOutput();
    out<<"PowerLocks Type: "<<obj.powerLocks<<endl;
    out<<"PowerWindows Type: "<<obj.powerWindows<<endl;
    out<<"AirBags Numbers: "<<obj.airBags<<endl;
    return out;
}