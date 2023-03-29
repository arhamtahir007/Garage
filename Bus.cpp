#include "Bus.h"

Bus::Bus()
{
    vehicleType = "Bus";
    lcd = 0;
}

void Bus::dataRecord()
{
    ofstream ofile("Bus Record.txt");       //opening bus record file
    ofile<<numPlate<<" "<<noOfDoors<<" "<<noOfTyres<<" "<<noOfSeats<<" "<<engineCC<<" "<<color<<" "
    <<transmissionType<<" "<<vehicleType<<" "<<lcd<<" "<<fault;                     //writing all data of bus object to file
    ofile.close();          //closing file
}

ostream &operator <<(ostream &out, Bus &a)
{
    a.generalOutput();
    if(a.lcd)
        out<<"\nLCD: Yes";
    else
        out<<"\nLCD: No";
    return out;
}

istream &operator >>(istream &in, Bus &a)
{
    a.generalInput();
    string lcd;
    cout<<"\nLCD in bus? ";
    in>>lcd;

    if(lcd == "yes" || lcd == "Yes")
        a.lcd = true;
    else
        a.lcd = false;

    err1:
    if (a.noOfDoors <= 0)
    {
        cout<<"Invalid Number of Doors, Enter again";
        cout<<"Enter no of Doors:";
        in>>a.noOfDoors;
        goto err1;             //goes to err1 on line 25
    }

    err2:
    if (a.noOfSeats <= 0 || a.noOfSeats == 10)
    {
        cout<<"Invalid Number of Seats, Enter again\n";
        cout<<"Enter no of Seats:";
        in>>a.noOfSeats;
        goto err2;          //goes to err2 on line 34
    }

    err3:
    if (a.noOfTyres < 4)
    {
        cout<<"Invalid Number of Tyres, Enter again";
        cout<<"Enter no of Tyres:";
        in>>a.noOfTyres;
        goto err3;          //goes to err3 on line 43
    }
    return in;
}

void Bus::vehicleReturn()
{
    cout<<"\nClassification of Car: "<<vehicleType<<endl;
    cout<<"\nRegistration Number: "<<numPlate<<endl;
    cout<<"\nColor: "<<color<<endl;
}