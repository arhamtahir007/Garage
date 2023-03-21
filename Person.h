//
// Created by fajar.pk on 3/21/2023.
//

#ifndef GARAGE_PERSON_H
#define GARAGE_PERSON_H

#include "Address.h"
#include "fstream"

class Person {
private:
    string first_name ;
    string second_name ;
    string number_plate;
    string  contact_no;
    //  Address address;
public:
    Person(){
        first_name= " ";
        second_name=" ";
        number_plate=" ";
        contact_no=" ";

    }
    Address address;

    string  setFirstName(string n);
    string  setSecondName(string m);
    string  setNumberplate(string x);
    string  setContactNo(string y);
    string  getFirstName();
    string  getSecondName();
    string  getContactNo();
    string  getNumberplate();
    void filingToStore();
    void ReadingFileData();
    friend istream &operator >>(istream& input,Person& person);
    friend ostream &operator <<(ostream& output,Person& person);


};


#endif //GARAGE_PERSON_H
