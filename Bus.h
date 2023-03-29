#ifndef GARAGE_BUS_H
#define GARAGE_BUS_H

#pragma once
#include "Vehicle.h"

class Bus : public Vehicle
{
    bool lcd;

public:
    Bus();

    void vehicleReturn() override;
    void dataRecord();

    friend ostream &operator <<(ostream &, Bus &);
    friend istream &operator >>(istream &, Bus &);
};

#endif //GARAGE_BUS_H
