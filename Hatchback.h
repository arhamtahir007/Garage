//
// Created by fajar.pk on 3/23/2023.
//

#ifndef GARAGE_HATCHBACK_H
#define GARAGE_HATCHBACK_H
#include "Sedan.h"

class Hatchback: public Vehicle {
protected:
    int airBags;
    string powerLocks;

public:
    Hatchback()
    {
        airBags=0;
        powerLocks=" ";
        vehicleType="HatchBack";

    }


    void vehicleReturn();  // virtual function by polymerization
    void dataRecord(); // data record
    void dataReading(); // data output

    friend ostream &operator << (ostream& ,const Hatchback&); // operator overloading of hatchback
    friend istream &operator >> (istream& ,Hatchback&);

};


#endif //GARAGE_HATCHBACK_H
