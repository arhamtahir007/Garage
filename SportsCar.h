#ifndef GARAGE_SPORTSCAR_H
#define GARAGE_SPORTSCAR_H

#endif //GARAGE_SPORTSCAR_H
#include "Vehicle.h"
//#pragma once

class SportsCar:public Vehicle{
    string turboType;
    string spoilerType;
public:
    SportsCar(){
        turboType = "";
        spoilerType = "";
        vehicleType = "Sports Car";
    }

    void vehicleReturn();

    void saveData();

    friend void readDataSpecific();

    friend ostream &operator << (ostream&,const SportsCar&);
    friend istream &operator >> (istream&,SportsCar&);

};

void readDataSpecific();