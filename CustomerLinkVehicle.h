//
// Created by HP on 3/23/2023.
//

#ifndef MAIN_CPP_CUSTOMERLINKVEHICLE_H
#define MAIN_CPP_CUSTOMERLINKVEHICLE_H

#endif //MAIN_CPP_CUSTOMERLINKVEHICLE_H
#include "Customer.h"
#include "SportsCar.h"

class CusVeh{ //This class will be used for association and aggregation
    Customer customer;
    SportsCar sc;
public:
    void input();
};