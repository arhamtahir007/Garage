//
// Created by HP on 3/23/2023.
//

#ifndef MAIN_CPP_CUSTOMERLINKVEHICLE_H
#define MAIN_CPP_CUSTOMERLINKVEHICLE_H

#endif //MAIN_CPP_CUSTOMERLINKVEHICLE_H
#include "Customer.h"
#include "Hatchback.h"

template<typename T>
class CusVeh{ //This class will be used for association and aggregation
    Customer* customer;
    T* vehicle;
public:
    CusVeh(){
        customer = nullptr;
        vehicle = nullptr;
    }
    explicit CusVeh(Customer* temp,T* temp2){
        customer = temp;
        vehicle = temp2;
    }

    void setCustomer(Customer* temp){
        customer = temp;
    }

    void setVehicle(T* temp){
        vehicle = temp;
    }

    void filing(){
        customer->setVehicleType(vehicle->getVehicleType());
        customer->writeToFile();
        vehicle->setNumPlate(customer->getNumberPlate());
        vehicle->dataRecord();
    }
};

