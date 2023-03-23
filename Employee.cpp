//
// Created by HP on 3/23/2023.
//

#include "Employee.h"

istream &operator>>(istream &input, Employee &person) {
    int i;string s;
    cout<<"Enter Employee First Name:"<<endl;
    input>>person.first_name;
    cout<<"Enter Employee Second Name:"<<endl;
    input>>person.second_name;
    cout<<"Enter Employee Contact Number:"<<endl;
    input>>person.contact_no;
    cout<<"Enter Employee Monthly Salary:"<<endl;
    input>>person.salary;
    cout<<"Enter Employee City Name:"<<endl;
    input>>s; person.address.setCityName(s);
    cout<<"Enter Employee Area Name:"<<endl;
    cin.ignore();
    getline(input,s); person.address.setArea(s);
    cout<<"Enter Employee Street Number:"<<endl;
    input>>i; person.address.setStreetNumber(i);
    cout<<"Enter Customer House Number:"<<endl;
    input>>i; person.address.setHouseNumber(i);
    return input;
}

ostream &operator<<(ostream &output, const Employee &person) {
    output<<"First Name: "<<person.first_name<<endl;
    output<<"Second Name: "<<person.second_name<<endl;
    output<<"Contact Number: "<<person.contact_no<<endl;
    output<<"Salary: "<<person.salary<<" $"<<endl;
    output<<"City Name: "<<person.address.getCityName()<<endl;
    output<<"Area Name: "<<person.address.getArea()<<endl;
    output<<"Street Number: "<<person.address.getStreetNumber()<<endl;
    output<<"House Number: "<<person.address.getHouseNumber()<<endl;
    return output;
}

void Employee::writeToFile() {
    fstream write("Employee Record.txt",ios::out | ios::app);
    write<<first_name<<" "<<second_name<<" "<<contact_no<<" "<<salary<<" "<<address.getCityName()
         <<" "<<address.getStreetNumber()<<" "<<address.getHouseNumber()<<" "<<address.getArea()<<endl;
}

void readFromFileEmployee() {
    Employee temp;
    string counter;
    fstream read("Employee Record.txt",ios::in);
    int noOfEntries = 0;while (!read.eof()) {
        getline(read, counter);
        noOfEntries++;
    }
    read.close();
    string nameOne,nameTwo;
    cout<<"Enter First Name:\n";
    cin>>nameOne;
    cout<<"Enter Second Name:\n";
    cin>>nameTwo;
    read.open("Employee Record.txt",ios::in);
    string s;int j;
    for (int i = 0; i < noOfEntries; ++i) {
        read >> temp.first_name;
        read >> temp.second_name;
        read >> temp.contact_no;
        read >> temp.salary;
        read >> s; temp.address.setCityName(s);
        read >> j; temp.address.setStreetNumber(j);
        read >> j; temp.address.setHouseNumber(j);
        getline(read,s);
        temp.address.setArea(s);
        if (temp.first_name == nameOne){
            if (temp.second_name == nameTwo){
                cout<<temp;
                return;
            }
        }
    }
    cout<<"Record Not Found!\n";
}