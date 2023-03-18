//
// Created by HP on 3/18/2023.
//

#include "SportsCar.h"

ostream &operator << (ostream& o,const SportsCar& temp) {
    temp.generalOutput();
    o<<"Turbo Type: "<<temp.turboType;
    o<<"Spoiler Type: "<<temp.spoilerType;
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
