//
// Created by HP on 3/18/2023.
//

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

    friend ostream &operator << (ostream&,const SportsCar&);
    friend istream &operator >> (istream&,SportsCar&);

};