//
// Created by HP on 3/26/2023.
//

#include "Functions.h"

void addVehicle(Customer temp){
    char menu; //variable bing used to navigate in menu
    re: //goto statement label
    cout<<"Type of Vehicle of Customer:\n"
          "1. Sedan\n"
          "2. HatchBack\n"
          "3. Sports Car\n";
    cin>>menu; //command for input
    switch (menu) { //switch cases being used to create menu
        case '1':{
            Sedan car;
            cin>>car;
            CusVeh<Sedan> save(&temp,&car);
            save.filing();
            break;
        }

        case '2':{
            Hatchback car;
            cin>>car;
            CusVeh<Hatchback> save(&temp,&car);
            save.filing();
            break;
        }

        case '3':{
            SportsCar car;
            cin>>car;
            CusVeh<SportsCar> save(&temp,&car);
            save.filing();
            break;
        }

        default:{
            cout<<"Invalid Input. Enter a number.\n";
            goto re;
        }
    }
}