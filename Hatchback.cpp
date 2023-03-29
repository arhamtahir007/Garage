#include "Hatchback.h"
void Hatchback:: vehicleReturn() {   //virtual function call as in other car classes
    cout<<"Classification of Car: "<<vehicleType<<endl;
    cout<<"Registration Number: "<<numPlate<<endl;
    cout<<"Color: "<<color<<endl;
}

istream & operator >>(istream& in ,Hatchback& obj){
    obj.generalInput();
    cout<<" enter number of airbags"<<endl;
    in>>obj.airBags;

    cout<<" Enter type of Power locks"<<endl;  // door locking ability of car(single basically automatic system k bahir se lock hojaty hain or dual ka either way )

    in>>obj.powerLocks;
    if(obj.powerLocks!=" single"&& obj.powerLocks!="Single"&&obj.powerLocks!=" dual"&& obj.powerLocks!="Dual")
    {
        cout<<"Enter \"single \" or \"dual\" only.\n";
        in>>obj.powerLocks;
    }

    while(true) {
        if (obj.noOfDoors != 4) {
            cout << "Invalid Number of Doors, Enter again.\n";
            cout << "Enter no of Doors:\n";
            in >> obj.noOfDoors;

        }
        else
            break;
    }
    while(true) {
        if (obj.noOfSeats != 5) {
            cout << "Invalid Number of Seats, Enter again.\n";
            cout << "Enter no of Seats:\n";
            in >> obj.noOfSeats;

        }
        else
            break;
    }
    while(true) {
        if (obj.noOfTyres != 4) {
            cout << "Invalid Number of Tyres, Enter again.\n";
            cout << "Enter no of Tyres:\n";
            in >> obj.noOfTyres;

        }
        else
            break;
    }
    return in;
}
ostream &operator << (ostream& out,const Hatchback& obj) {
    obj.generalOutput();
    out<<"PowerLocks Type: "<<obj.powerLocks<<endl;
    out<<"AirBags Numbers: "<<obj.airBags<<endl;
    return out;
}


void Hatchback::dataRecord() {
    ofstream input("Hatchback Record.txt",ios::out | ios::app);
    input<<numPlate<<" "<<noOfDoors<<" "<<noOfTyres<<" "<<noOfSeats<<" "<<engineCC<<" "
         <<color<<" "<<transmissionType<<" "<<vehicleType<<" "<<airBags<<" "<<powerLocks<<" "<<fault<<endl;

    input.close();
}

Hatchback Hatchback:: dataReading(string temp) {
    Hatchback car;
    string input;
    ifstream output("HatchBack Record.txt");
    int noOfEntries = 0;
    while (!output.eof()) {
        getline(output, input);
        noOfEntries++;
    }
    output.close();
    output.open("HatchBack Record.txt", ios::in);
    for (int i = 0; i < noOfEntries; ++i) {
        output >> car.numPlate;
        output >> car.noOfDoors;
        output >> car.noOfTyres;
        output >> car.noOfSeats;
        output >> car.engineCC;
        output >> car.color;
        output >> car.transmissionType;
        output >> car.vehicleType;
        output >> car.airBags;
        output >> car.powerLocks;
        getline(output, car.fault);
        if (car.numPlate == temp) {
            return car;
        }
    }
    cout << "Record Not Found.\n";
}