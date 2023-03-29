#ifndef MAIN_CPP_CUSTOMER_H
#define MAIN_CPP_CUSTOMER_H

#endif //MAIN_CPP_CUSTOMER_H
#include "Person.h"

class Customer:public Person{
    string number_plate;
public:
    Customer(){
        number_plate = "";
    }

    string setNumberPlate(string x);
    string getNumberPlate();

    void writeToFile();
    friend void readFromFileCustomer();

    friend istream &operator >> (istream& input,Customer& person);
    friend ostream &operator << (ostream& output,const Customer& person);

};

void readFromFileCustomer();