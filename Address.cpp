//
// Created by fajar.pk on 3/21/2023.
//

#include "Address.h"
void Address:: setCityName(string x){
    city_name=x;
}
void Address:: setArea(string a){
    area=a;
}
void  Address::setStreetNumber(int c){
    street_number=c;
}
void Address::setHouseNumber(int y){
    house_number=y;
}
string Address:: getCityName(){
    return city_name;
}
string Address::GetArea(){
    return area;
}
int Address::getStreetNumber(){
    return street_number;
}
int Address::getHouseNumber(){
    return house_number;
}
