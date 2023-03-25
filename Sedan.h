//
// Created by fajar.pk on 3/25/2023.
//

#ifndef GARAGE_SEDAN_H
#define GARAGE_SEDAN_H

#include "Vehicle.h"

class Sedan: public Vehicle{
protected:
    int airBags ;
    string powerLocks;
    string powerWindows;
public:
    Sedan(){ // default constructor
        airBags=0;
        powerLocks=" ";
        powerWindows=" ";

    }

    void vehicleReturn(); // polymirization virtual function
    void dataReading(); //filing data reading function
    void dataRecord();// storing data

    friend istream &operator >> (istream& ,Sedan&);
    friend ostream &operator << (ostream& ,const Sedan& );

};




#endif //GARAGE_SEDAN_H
