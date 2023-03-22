#include "SportsCar.h"

int main(){
    SportsCar s,r;
    Vehicle* v = &s;
    cin>>s;
    v->vehicleReturn();
    s.saveData();

    readData();

}