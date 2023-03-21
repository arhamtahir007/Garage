//
// Created by fajar.pk on 3/21/2023.
//

//
// Created by fajar.pk on 3/20/2023.
//

#include "Person.h"

string Person::setFirstName( string n) {
    first_name =n;
    return first_name;
}
string Person::setSecondName(string m) {
    second_name=m;
    return second_name;
}
string Person::setNumberplate(string x){
    number_plate=x;
    return number_plate;
}
string Person::setContactNo(string y){
    contact_no=y;
    return contact_no;
}

string Person::getFirstName(){
    return first_name;
}
string Person::getSecondName(){
    return second_name;
}
string Person::getNumberplate(){
    return number_plate;
}
string Person::getContactNo(){
    return contact_no;
}

istream &operator >>(istream& input,Person& person){
    string a,b,c;
    int x,y,z;
    cout<<"Enter Users First Name "<<endl;
    input>>a;
    person.setFirstName(a);
    cout<<"Enter Users Second Name "<<endl;
    input>>a;
    person.setSecondName(a);
    cout<<"Enter Users Number Plate "<<endl;
    input>>a;
    person.setNumberplate(a);
    cout<<"Enter Users Contact Number "<<endl;
    input>>a;
    person.setContactNo(a);
    cout<<"Enter Users City Name "<<endl;
    input>>a;
    person.address.setCityName(a);
    cout<<"Enter Users Area Name "<<endl;
    input>>a;
    person.address.setArea(a);
    cout<<"Enter Users Street Number "<<endl;
    input>>x;
    person.address.setStreetNumber(x);
    cout<<"Enter Users House Number "<<endl;
    input>>y;
    person.address.setHouseNumber(y);
    person.filingToStore();

    return input;
}
ostream &operator <<(ostream& output,Person& person){
    cout<<endl;
    output<<" Users First Name "<<endl;
    output<<" "<<person.getFirstName();
    cout<<endl;
    output<<" Users Second Name "<<endl;
    output<<" "<<person.getSecondName();
    cout<<endl;
    output<<" Users Number Plate "<<endl;
    output<<" "<<person.getNumberplate();
    cout<<endl;
    output<<" Users Contact Number"<<endl;
    output<<" "<<person.getContactNo();
    cout<<endl;
    output<<" Users City Name"<<endl;
    output<<" "<<person.address.getCityName();
    cout<<endl;
    output<<" Users Area Name"<<endl;
    output<<" "<<person.address.GetArea();
    cout<<endl;
    output<<" Users Street Number"<<endl;
    output<<" "<<person.address.getStreetNumber();
    cout<<endl;
    output<<" Users House Number"<<endl;
    output<<" "<<person.address.getHouseNumber();
    return output;
}

void Person::filingToStore(){
    fstream object;

    object.open("person.txt",ios::app);

    object<<" "<<getFirstName()<<" "<<getSecondName()<<" "<<getContactNo()<<" "<<getNumberplate();
    object<<" "<<address.getCityName()<<" "<<address.getStreetNumber()<<" "<<address.getHouseNumber()<<"  "<<address.GetArea();
    object<<endl;


    object.close();


}

void Person::ReadingFileData() {
    //  ifstream object;
    Person y;
    ifstream object("person.txt");
    if (!object) {
        cout << "no  such file  exists";

    } else {
        string value;
        cout << "enter first name" << endl;
        cin >> value;
        while (!object.eof()) {
            int val;
            string read;
            object >> y.first_name;
            object >> y.second_name;
            object >> y.contact_no;
            object >> y.number_plate;
            object >> read;
            y.address.setCityName(read);
            object >> val;
            y.address.setStreetNumber(val);
            object >> val;
            y.address.setHouseNumber(val);
            object >> read;
            y.address.setArea(read);
            if (y.first_name == value) {
                cout << y;
             break;
            }


        }
    }
}

