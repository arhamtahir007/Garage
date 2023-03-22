//
// Created by HP on 3/18/2023.
//

#include "SportsCar.h"

ostream &operator << (ostream& o,const SportsCar& temp) {
    temp.generalOutput();
    o<<"Turbo Type: "<<temp.turboType<<endl;
    o<<"Spoiler Type: "<<temp.spoilerType<<endl;
    return o;
}

istream &operator>>(istream& i,SportsCar& temp) {
    temp.generalInput();
    cout<<"Enter Turbo Type:\n";
    i>>temp.turboType;
    cout<<"Enter Spoiler Type:\n";
    i>>temp.spoilerType;

    sc0:
    if (temp.noOfDoors <= 0 || temp.noOfDoors == 3 || temp.noOfDoors > 4){
        cout<<"Invalid Number of Doors, Enter again.\n";
        cout<<"Enter no of Doors:\n";
        i>>temp.noOfDoors;
        goto sc0;
    }

    sc1:
    if (temp.noOfSeats <= 0 || temp.noOfSeats == 3 || temp.noOfSeats > 4){
        cout<<"Invalid Number of Seats, Enter again.\n";
        cout<<"Enter no of Seats:\n";
        i>>temp.noOfSeats;
        goto sc1;
    }

    sc2:
    if (temp.noOfTyres != 4){
        cout<<"Invalid Number of Tyres, Enter again.\n";
        cout<<"Enter no of Tyres:\n";
        i>>temp.noOfTyres;
        goto sc2;
    }
    return i;
}

void SportsCar::vehicleReturn() {
    cout<<"Classification of Car: "<<vehicleType<<endl;
    cout<<"Registration Number: "<<numPlate<<endl;
    cout<<"Color: "<<color<<endl;
}


void SportsCar::saveData() {
    fstream in("Vehicle Record.txt",ios::out | ios::app);
    in<<numPlate<<" "<<noOfDoors<<" "<<noOfTyres<<" "<<noOfSeats<<" "<<engineCC<<" "<<noOfFaults<<" "<<color<<" "<<transmissionType<<" "<<vehicleType<<" "<<turboType<<" "<<spoilerType<<" ";
    for (int i = 0; i < noOfFaults; ++i) {
        in<<fault[i]<<endl;
    }
    in.close();
}

void readData() {
    SportsCar sc;
    string counter;
    fstream out("Vehicle Record.txt", ios::in);
    int noOfEntries = 0;
    while (!out.eof()) {
        getline(out, counter);
        noOfEntries++;
    }
    string temp, type;
    cout << "Enter registration number:\n";
    cin >> temp;
    out.close();
    out.open("Vehicle Record.txt", ios::in);
    for (int i = 0; i < noOfEntries / 2; ++i) {
        out >> sc.numPlate;
        out >> sc.noOfDoors;
        out >> sc.noOfTyres;
        out >> sc.noOfSeats;
        out >> sc.engineCC;
        out >> sc.noOfFaults;
        out >> sc.color;
        out >> sc.transmissionType;
        out >> sc.vehicleType;
        out >> type;
        out >> sc.turboType;
        out >> sc.spoilerType;
        sc.vehicleType = sc.vehicleType + " " + type;
        sc.fault = new string[sc.noOfFaults];
        for (int j = 0; j < sc.noOfFaults; ++j) {
            getline(out, sc.fault[i]);
        }
        if (sc.numPlate == temp) {
            cout << sc;
            return;
        }

    }
    cout << "Record Not Found.\n";
}
