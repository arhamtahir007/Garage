#include "Functions.h"

int main(){
    int a = userLogIn();
    if (a == 1 ){
        Customer customer;
        char menu; //variable bing used to navigate in menu
        re: //goto statement label
        cout<<"Enter 1 to add Customer.\n"
              "Enter 2 to return Vehicle.\n"
              "Enter 3 to see and manage records.\n"
              "Enter 4 to manage Employees.\n"
              "Enter 0 to exit.\n"; //command for output
        cin>>menu; //command for input
        switch (menu) { //switch cases being used to create menu
            case '1':{
                cin>>customer;
                addVehicle(customer);
                break;
            }

            case '2':{
                break;
            }

            case '0':{
                return 0; //end of program
            }

            default:{
                cout<<"Invalid Input. Enter again.\n";
                goto re;
            }
        }
        goto re;
    }
    else{
        return 0;
    }
}