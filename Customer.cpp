#include "Customer.h"

string Customer::getNumberPlate(){
    return number_plate;
}

string Customer::setNumberPlate(string x){
    number_plate=x;
    return number_plate;
}

istream &operator>>(istream &input, Customer& person) {
    int i;string s;
    cout<<"Enter Customer First Name:"<<endl;
    input>>person.first_name;
    cout<<"Enter Customer Second Name:"<<endl;
    input>>person.second_name;
    cout<<"Enter Customer Contact Number:"<<endl;
    input>>person.contact_no;
    cout<<"Enter Customer Vehicle Registration Number:"<<endl;
    input>>person.number_plate;
    cout<<"Enter Customer City Name:"<<endl;
    input>>s; person.address.setCityName(s);
    cout<<"Enter Customer Area Name:"<<endl;
    cin.ignore();
    getline(input,s); person.address.setArea(s);
    cout<<"Enter Customer Street Number:"<<endl;
    input>>i; person.address.setStreetNumber(i);
    cout<<"Enter Customer House Number:"<<endl;
    input>>i; person.address.setHouseNumber(i);
    return input;
}

ostream &operator<<(ostream &output, const Customer &person) {
    output<<"First Name: "<<person.first_name<<endl;
    output<<"Second Name: "<<person.second_name<<endl;
    output<<"Contact Number: "<<person.contact_no<<endl;
    output<<"Vehicle Registration Number: "<<person.number_plate<<endl;
    output<<"City Name: "<<person.address.getCityName()<<endl;
    output<<"Area Name: "<<person.address.getArea()<<endl;
    output<<"Street Number: "<<person.address.getStreetNumber()<<endl;
    output<<"House Number: "<<person.address.getHouseNumber()<<endl;
    return output;
}

void Customer::writeToFile() {
    fstream write("Customer Record.txt",ios::out | ios::app);
    write<<first_name<<" "<<second_name<<" "<<contact_no<<" "<<number_plate<<" "<<address.getCityName()
    <<" "<<address.getStreetNumber()<<" "<<address.getHouseNumber()<<" "<<address.getArea()<<endl;
}

void readFromFileCustomer() {
    Customer temp;
    string counter;
    fstream read("Customer Record.txt",ios::in);
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
    read.open("Customer Record.txt",ios::in);
    string s;int j;
    for (int i = 0; i < noOfEntries; ++i) {
        read >> temp.first_name;
        read >> temp.second_name;
        read >> temp.contact_no;
        read >> temp.number_plate;
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
