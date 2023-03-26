//
// Created by HP on 3/23/2023.
//

#ifndef MAIN_CPP_CUSTOMER_H
#define MAIN_CPP_CUSTOMER_H

#endif //MAIN_CPP_CUSTOMER_H
#include "Employee.h"

class Customer:public Person{
    string vehicleType;
    string number_plate;
public:
    Customer(){
        number_plate = "";
        vehicleType = "";
    }

    string setNumberPlate(string x);
    string getNumberPlate();

    string setVehicleType(string x);
    string getVehicleType();

    void writeToFile();
    friend void readFromFileCustomer();

    friend istream &operator >> (istream& input,Customer& person);
    friend ostream &operator << (ostream& output,const Customer& person);

};

void readFromFileCustomer();