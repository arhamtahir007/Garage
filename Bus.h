#ifndef GARAGE_BUS_H
#define GARAGE_BUS_H

#include "Vehicle.h"

class Bus : Vehicle
{
    bool lcd;

public:
    Bus();

    void vehicleReturn();
    void record();

    friend ostream &operator <<(ostream &, Bus &);
    friend istream &operator >>(istream &, Bus &);
};

#endif //GARAGE_BUS_H
