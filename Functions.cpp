//
// Created by HP on 3/26/2023.
//

#include "Functions.h"
//working properly 👍
void addVehicle(Customer temp) {
    char menu; //variable bing used to navigate in menu
    re: //goto statement label
    cout << "Type of Vehicle of Customer:\n"
            "1. Sedan\n"
            "2. HatchBack\n"
            "3. Sports Car\n";
    cin >> menu; //command for input
    switch (menu) { //switch cases being used to create menu
        case '1': {
            Sedan car;
            cin >> car;
            CusVeh<Sedan> save(&temp, &car);
            save.filing();
            break;
        }

        case '2': {
            Hatchback car;
            cin >> car;
            CusVeh<Hatchback> save(&temp, &car);
            save.filing();
            break;
        }

        case '3': {
            SportsCar car;
            cin >> car;
            CusVeh<SportsCar> save(&temp, &car);
            save.filing();
            break;
        }

        default: {
            cout << "Invalid Input. Enter a number.\n";
            goto re;
        }
    }
}
//Now working absolutely fine 👌
void returningVehicle() {
    Customer returning = searchCustomer();
    if (returning.getVehicleType() == "Sedan") {
        Sedan sedan;
        sedan = sedan.dataReading(returning.getNumberPlate());
        Vehicle *veh = &sedan;
        cout << returning;
        veh->vehicleReturn();
        payment();
    } else if (returning.getVehicleType() == "HatchBack") {
        Hatchback hatchback;
        hatchback = hatchback.dataReading(returning.getNumberPlate());
        Vehicle *veh = &hatchback;
        cout << returning;
        veh->vehicleReturn();
        payment();
    } else if (returning.getVehicleType() == "SportsCar") {
        SportsCar sportsCar;
        sportsCar = sportsCar.dataReading(returning.getNumberPlate());
        Vehicle *veh = &sportsCar;
        cout << returning;
        veh->vehicleReturn();
        payment();
    } else
        cout << "No Record Found.\n";
}

Customer searchCustomer() {
    Customer temp;
    string counter;
    fstream read("Customer Record.txt", ios::in);
    int noOfEntries = 0;
    while (!read.eof()) {
        getline(read, counter);
        noOfEntries++;
    }
    noOfEntries = noOfEntries - 1;
    read.close();
    string nameOne, nameTwo, num;
    cout << "Enter First Name:\n";
    cin >> nameOne;
    cout << "Enter Second Name:\n";
    cin >> nameTwo;
    cout << "Enter Vehicle Registration Number:\n";
    cin >> num;
    read.open("Customer Record.txt", ios::in);
    string s;
    int j;
    for (int i = 0; i < noOfEntries; ++i) {
        read >> temp.first_name;
        read >> temp.second_name;
        read >> temp.contact_no;
        read >> temp.number_plate;
        read >> temp.vehicleType;
        read >> s;
        temp.address.setCityName(s);
        read >> j;
        temp.address.setStreetNumber(j);
        read >> j;
        temp.address.setHouseNumber(j);
        getline(read, s);
        temp.address.setArea(s);
        if (temp.first_name == nameOne) {
            if (temp.second_name == nameTwo) {
                if (temp.number_plate == num) {
                    return temp;
                }
            }
        }
    }
    cout << "Record Not Found!\n";
    Customer null;
    return null;
}

void payment() {
    double charged, payed, returned;
    cout << "Amount Charged:\n";
    cin >> charged;
    rePay:
    cout << "Amount Payed:\n";
    cin >> payed;
    if (payed < charged) {
        cout << "Least payable amount is " << charged << " Rs.\n";
        goto rePay;
    }
    cout << "Change:\n";
    returned = payed - charged;
    cout << returned << " Rs\n";
    fstream file("Sales Record.txt", ios::in);
    double totalSales;
    int noOfVehRepaired;
    string a1, a2, b1;
    file >> a1;
    file >> totalSales;
    file >> a2;
    file >> b1;
    file >> noOfVehRepaired;
    file.close();
    file.open("Sales Record.txt", ios::out | ios::trunc);
    file << a1 << " " << totalSales + charged << " " << a2 << endl;
    file << b1 << " " << noOfVehRepaired + 1 << endl;
}

void employeeManagement() {
    char menu; //variable bing used to navigate in menu
    re: //goto statement label
    cout << "Enter 1 to search for an Employee.\n"
            "Enter 2 to add an Employee.\n"
            "Enter 3 to edit an Employee Data.\n"
            "Enter 4 to remove an Employee.\n"
            "Enter 5 to see all Employee Data.\n"
            "Enter 0 to go back.\n"; //command for output
    cin >> menu; //command for input
    switch (menu) { //switch cases being used to create menu
        case '1': {
            Employee employee = searchEmployee();
            if (!employee.getFirstName().empty()) {
                cout << employee;
            }
            break;
        }

        case '2': {
            Employee employee;
            cin >> employee;
            employee.writeToFile();
            break;
        }

        case '3':{
            removeEmployee(1);
            break;
        }

        case '4': {
            removeEmployee(0);
            break;
        }

        case '5': {
            readFromFileEmployee();
            break;
        }

        case '0': {
            return;
        }

        default: {
            cout << "Invalid Input. Enter again.\n";
            goto re;
        }
    }
    goto re;
}

Employee searchEmployee() {
    Employee temp;
    string counter;
    fstream read("Employee Record.txt", ios::in);
    int noOfEntries = 0;
    while (!read.eof()) {
        getline(read, counter);
        noOfEntries++;
    }
    noOfEntries = noOfEntries - 1;
    read.close();
    string nameOne, nameTwo;
    cout << "Enter First Name:\n";
    cin >> nameOne;
    cout << "Enter Second Name:\n";
    cin >> nameTwo;
    read.open("Employee Record.txt", ios::in);
    string s;
    int j;
    for (int i = 0; i < noOfEntries; ++i) {
        read >> temp.first_name;
        read >> temp.second_name;
        read >> temp.contact_no;
        read >> temp.salary;
        read >> s;
        temp.address.setCityName(s);
        read >> j;
        temp.address.setStreetNumber(j);
        read >> j;
        temp.address.setHouseNumber(j);
        getline(read, s);
        temp.address.setArea(s);
        if (temp.first_name == nameOne) {
            if (temp.second_name == nameTwo) {
                return temp;
            }
        }
    }
    cout << "Record Not Found!\n";
    Employee null;
    return null;
}

void removeEmployee(int mode) {
    string counter, name1st, name2nd;
    fstream read("Employee Record.txt", ios::in);
    int noOfEntries = 0;
    while (!read.eof()) {
        getline(read, counter);
        noOfEntries++;
    }
    noOfEntries = noOfEntries - 1;
    read.close();
    read.open("Employee Record.txt", ios::in);
    auto *removeEmp = new Employee[noOfEntries];
    cout << "Enter First Name of Employee:\n";
    cin >> name1st;
    cout << "Enter second Name of Employee:\n";
    cin >> name2nd;
    string s;
    int j, indexToRemove = -100;
    for (int i = 0; i < noOfEntries; ++i) {
        read >> removeEmp[i].first_name;
        read >> removeEmp[i].second_name;
        read >> removeEmp[i].contact_no;
        read >> removeEmp[i].salary;
        read >> s;
        removeEmp[i].address.setCityName(s);
        read >> j;
        removeEmp[i].address.setStreetNumber(j);
        read >> j;
        removeEmp[i].address.setHouseNumber(j);
        getline(read, s);
        removeEmp[i].address.setArea(s);
        if (removeEmp[i].first_name == name1st) {
            if (removeEmp[i].second_name == name2nd) {
                indexToRemove = i;
            }
        }
    }
    
    if (indexToRemove >= 0) {
        if (mode == 0) {
            remove("Employee Record.txt");
            for (int i = 0; i < noOfEntries; ++i) {
                if (i != indexToRemove) {
                    removeEmp[i].writeToFile();
                }
            }
            char asking[] = "Employee has been Successfully Removed.\n";
            for (int i = 0; asking[i] != '\0'; i++) {
                cout << asking[i];
                cout.flush();
                if (asking[i] == '\n')
                    Sleep(500);
                else
                    Sleep(5);
            }
        }
        else if (mode == 1){
            employeeEdit(removeEmp,noOfEntries,indexToRemove);
            return;
        }
    } else {
        char asking[] = "Employee Record Not Found.\n";
        for (int i = 0; asking[i] != '\0'; i++) {
            cout << asking[i];
            cout.flush();
            if (asking[i] == '\n')
                Sleep(500);
            else
                Sleep(5);
        }
    }
    delete[] removeEmp;
}

void customerManagement(){
    char menu; //variable bing used to navigate in menu
    re: //goto statement label
    cout<<"Enter 1 to search for a Customer & Vehicle.\n"
          "Enter 2 to edit a Customer & Vehicle Data.\n"
          "Enter 3 to remove a Customer & Vehicle.\n"
          "Enter 4 to see all Customer records.\n"
          "Enter 0 to go back.\n"; //command for output
    cin>>menu; //command for input
    switch (menu) { //switch cases being used to create menu
        case '1': {
            Customer customer = searchCustomer();
            if (customer.getVehicleType() == "Sedan") {
                Sedan sedan;
                sedan = sedan.dataReading(customer.getNumberPlate());
                cout << customer << endl;
                cout << sedan << endl;
            } else if (customer.getVehicleType() == "HatchBack") {
                Hatchback hatchback;
                hatchback = hatchback.dataReading(customer.getNumberPlate());
                cout << customer << endl;
                cout<< hatchback << endl;
            } else if (customer.getVehicleType() == "SportsCar") {
                SportsCar sportsCar;
                sportsCar = sportsCar.dataReading(customer.getNumberPlate());
                cout << customer << endl;
                cout << sportsCar << endl;
            }
            break;
        }

        case '2':{
            removeCustomer(1);
            break;
        }

        case '3':{
            removeCustomer(0);
            break;
        }

        case '4':{
            viewAllCusVeh();
            break;
        }

        case '0':{
            return;
        }

        default:{
            cout<<"Invalid Input. Enter again.\n";
            goto re;
        }
    }
    goto re;
}

void removeCustomer(int mode) {
    string counter, name1st, name2nd;
    fstream read("Customer Record.txt", ios::in);
    int noOfEntries = 0;
    while (!read.eof()) {
        getline(read, counter);
        noOfEntries++;
    }
    noOfEntries = noOfEntries - 1;
    read.close();
    read.open("Customer Record.txt", ios::in);
    auto *removeCus = new Customer[noOfEntries];
    cout << "Enter First Name of Customer:\n";
    cin >> name1st;
    cout << "Enter second Name of Customer:\n";
    cin >> name2nd;
    string s;
    int j, indexToRemove = -100;
    for (int i = 0; i < noOfEntries; ++i) {
        read >> removeCus[i].first_name;
        read >> removeCus[i].second_name;
        read >> removeCus[i].contact_no;
        read >> removeCus[i].number_plate;
        read >> removeCus[i].vehicleType;
        read >> s;
        removeCus[i].address.setCityName(s);
        read >> j;
        removeCus[i].address.setStreetNumber(j);
        read >> j;
        removeCus[i].address.setHouseNumber(j);
        getline(read, s);
        removeCus[i].address.setArea(s);
        if (removeCus[i].first_name == name1st) {
            if (removeCus[i].second_name == name2nd) {
                indexToRemove = i;
            }
        }
    }

    if (indexToRemove >= 0) {
        if (mode == 0) {
            remove("Customer Record.txt");
            for (int i = 0; i < noOfEntries; ++i) {
                if (i != indexToRemove) {
                    removeCus[i].writeToFile();
                }
            }
            char asking[] = "Customer has been Successfully Removed.\n";
            for (int i = 0; asking[i] != '\0'; i++) {
                cout << asking[i];
                cout.flush();
                if (asking[i] == '\n')
                    Sleep(500);
                else
                    Sleep(5);
            }
        }
        else if (mode == 1) {
            customerEdit(removeCus,noOfEntries,indexToRemove);
            return;
        }
    } else {
        char asking[] = "Customer Record Not Found.\n";
        for (int i = 0; asking[i] != '\0'; i++) {
            cout << asking[i];
            cout.flush();
            if (asking[i] == '\n')
                Sleep(500);
            else
                Sleep(5);
        }
        return;
    }
    if (removeCus[indexToRemove].getVehicleType() == "Sedan") {
        removeSedan(removeCus[indexToRemove].getNumberPlate(),"*",0);
    } else if (removeCus[indexToRemove].getVehicleType() == "HatchBack") {
        removeHatchBack(removeCus[indexToRemove].getNumberPlate(),"*",0);
    } else if (removeCus[indexToRemove].getVehicleType() == "SportsCar") {
        removeSportsCar(removeCus[indexToRemove].getNumberPlate(),"*",0);
    }
}

void removeSedan(string regNum,string numPlateChange,int mode) {
    string input;
    int indexToRemove = -100;
    ifstream output("Sedan Records.txt");
    int noOfEntries = 0;
    while (!output.eof()) {
        getline(output, input);
        noOfEntries++;
    }
    noOfEntries = noOfEntries - 1;
    output.close();
    auto *sedan = new Sedan[noOfEntries];
    output.open("Sedan Records.txt", ios::in);
    for (int i = 0; i < noOfEntries; ++i) {
        output >> sedan[i].numPlate;
        output >> sedan[i].noOfDoors;
        output >> sedan[i].noOfTyres;
        output >> sedan[i].noOfSeats;
        output >> sedan[i].engineCC;
        output >> sedan[i].color;
        output >> sedan[i].transmissionType;
        output >> sedan[i].vehicleType;
        output >> sedan[i].airBags;
        output >> sedan[i].powerLocks;
        output >> sedan[i].powerWindows;
        getline(output, sedan[i].fault);
        if (sedan[i].numPlate == regNum) {
            indexToRemove = i;
        }
    }
    if (indexToRemove >= 0) {
        if (mode == 0) {
            remove("Sedan Records.txt");
            for (int i = 0; i < noOfEntries; ++i) {
                if (i != indexToRemove) {
                    sedan[i].dataRecord();
                }
            }
        }
        else if (mode == 1){
            if (numPlateChange != "*") {
                sedan[indexToRemove].numPlate = numPlateChange;
            }
            sedanEdit(sedan,noOfEntries,indexToRemove);
        }
    }
    delete[] sedan;
}


void removeHatchBack(string regNum,string numPlateChange,int mode) {
    string input;
    int indexToRemove = -100;
    ifstream output("HatchBack Record.txt");
    int noOfEntries = 0;
    while (!output.eof()) {
        getline(output, input);
        noOfEntries++;
    }
    noOfEntries = noOfEntries - 1;
    output.close();
    auto *hatchback = new Hatchback[noOfEntries];
    output.open("HatchBack Record.txt", ios::in);
    for (int i = 0; i < noOfEntries; ++i) {
        output >> hatchback[i].numPlate;
        output >> hatchback[i].noOfDoors;
        output >> hatchback[i].noOfTyres;
        output >> hatchback[i].noOfSeats;
        output >> hatchback[i].engineCC;
        output >> hatchback[i].color;
        output >> hatchback[i].transmissionType;
        output >> hatchback[i].vehicleType;
        output >> hatchback[i].airBags;
        output >> hatchback[i].powerLocks;
        getline(output, hatchback[i].fault);
        if (hatchback[i].numPlate == regNum) {
            indexToRemove = i;
        }
    }
    if (indexToRemove >= 0) {
        if (mode == 0) {
            remove("HatchBack Record.txt");
            for (int i = 0; i < noOfEntries; ++i) {
                if (i != indexToRemove) {
                    hatchback[i].dataRecord();
                }
            }
        }
        else if (mode == 1){
            if (numPlateChange != "*") {
                hatchback[indexToRemove].numPlate = numPlateChange;
            }
            hatchBackEdit(hatchback,noOfEntries,indexToRemove);
        }
    }
    delete[] hatchback;
}

void removeSportsCar(string regNum,string numPlateChange,int mode) {
    string counter;
    int indexToRemove = -100;
    fstream out("Sports Car Record.txt", ios::in);
    int noOfEntries = 0;
    while (!out.eof()) {
        getline(out, counter);
        noOfEntries++;
    }
    noOfEntries = noOfEntries - 1;
    out.close();
    auto *sc = new SportsCar[noOfEntries];
    out.open("SportsCar Record.txt", ios::in);
    for (int i = 0; i < noOfEntries; ++i) {
        out >> sc[i].numPlate;
        out >> sc[i].noOfDoors;
        out >> sc[i].noOfTyres;
        out >> sc[i].noOfSeats;
        out >> sc[i].engineCC;
        out >> sc[i].color;
        out >> sc[i].transmissionType;
        out >> sc[i].vehicleType;
        out >> sc[i].turboType;
        out >> sc[i].spoilerType;
        getline(out, sc[i].fault);
        if (sc[i].numPlate == regNum) {
            indexToRemove = i;
        }
    }
    if (indexToRemove >= 0) {
        if (mode == 0) {
            remove("SportsCar Record.txt");
            for (int i = 0; i < noOfEntries; ++i) {
                if (i != indexToRemove) {
                    sc[i].dataRecord();
                }
            }
        }
        else if (mode == 1){
            if (numPlateChange != "*") {
                sc[indexToRemove].numPlate = numPlateChange;
            }
            sportsCarEdit(sc,noOfEntries,indexToRemove);
        }
    }
    delete[] sc;
}

void viewAllCusVeh() {
    string counter;
    fstream read("Customer Record.txt", ios::in);
    int noOfEntries = 0;
    while (!read.eof()) {
        getline(read, counter);
        noOfEntries++;
    }
    noOfEntries = noOfEntries - 1;
    read.close();
    Customer customer;
    string s;int j;
    read.open("Customer Record.txt", ios::in);
    for (int i = 0; i < noOfEntries; ++i) {
        read >> customer.first_name;
        read >> customer.second_name;
        read >> customer.contact_no;
        read >> customer.number_plate;
        read >> customer.vehicleType;
        read >> s;
        customer.address.setCityName(s);
        read >> j;
        customer.address.setStreetNumber(j);
        read >> j;
        customer.address.setHouseNumber(j);
        getline(read, s);
        customer.address.setArea(s);
        if (customer.getVehicleType() == "Sedan") {
            Sedan sedan;
            sedan = sedan.dataReading(customer.getNumberPlate());
            cout << customer << endl << sedan << endl;
        } else if (customer.getVehicleType() == "HatchBack") {
            Hatchback hatchback;
            hatchback = hatchback.dataReading(customer.getNumberPlate());
            cout << customer << endl << hatchback << endl;
        } else if (customer.getVehicleType() == "SportsCar") {
            SportsCar sportsCar;
            sportsCar = sportsCar.dataReading(customer.getNumberPlate());
            cout << customer << endl << sportsCar << endl;
        }
    }
}

void customerEdit(Customer* ptr,int noOfEntries,int indexToEdit){
    string numPlateChange = "*";
    char menu; //variable bing used to navigate in menu
    re: //goto statement label
    cout<<"Enter 1 to edit Customer Name.\n"
          "Enter 2 to edit Customer Contact Number.\n"
          "Enter 3 to edit Customer Address.\n"
          "Enter 4 to edit Customer's Vehicle Details.\n"
          "Enter 0 to go back.\n"; //command for output
    cin>>menu; //command for input
    switch (menu) { //switch cases being used to create menu
        case '1':{
            cout<<"Enter First Name:\n";
            cin>>ptr[indexToEdit].first_name;
            cout<<"Enter Second Name:\n";
            cin>>ptr[indexToEdit].second_name;
            break;
        }

        case '2':{
            cout<<"Enter Contact Number:\n";
            cin>>ptr[indexToEdit].contact_no;
            break;
        }

        case '3':{
            int i;string s;
            cout << "Enter Customer City Name:" << endl;
            cin >> s;
            ptr[indexToEdit].address.setCityName(s);
            cout << "Enter Customer Area Name:" << endl;
            cin.ignore();
            getline(cin, s);
            ptr[indexToEdit].address.setArea(s);
            cout << "Enter Customer Street Number:" << endl;
            cin >> i;
            ptr[indexToEdit].address.setStreetNumber(i);
            cout << "Enter Customer House Number:" << endl;
            cin >> i;
            ptr[indexToEdit].address.setHouseNumber(i);
            break;
        }

        case '4': {
            char numPlate;
            caseIV:
            cout << "Do you wish to change Vehicle Registration Number? (y/n)\n";
            cin >> numPlate;
            if (numPlate != 'y' && numPlate != 'n') {
                cout << "Invalid Input. Enter Again:\n";
                goto caseIV; //goto line 690
            }
            if (numPlate == 'y') {
                numPlateChange = ptr[indexToEdit].number_plate;
                cout << "Enter Vehicle Registration Number:\n";
                cin >> ptr[indexToEdit].number_plate;
            }
            if (ptr[indexToEdit].getVehicleType() == "Sedan") {
                removeSedan(ptr[indexToEdit].getNumberPlate(), numPlateChange, 1);
            } else if (ptr[indexToEdit].getVehicleType() == "HatchBack") {
                removeHatchBack(ptr[indexToEdit].getNumberPlate(), numPlateChange, 1);
            } else if (ptr[indexToEdit].getVehicleType() == "SportsCar") {
                removeSportsCar(ptr[indexToEdit].getNumberPlate(), numPlateChange, 1);
            }
            break;
        }

        case '0':{
            remove("Customer Record.txt");
            for (int i = 0; i < noOfEntries; ++i) {
                ptr[i].writeToFile();
            }
            return; //end of program
        }

        default:{
            cout<<"Invalid Input. Enter again.\n";
            goto re;
        }
    }
    goto re;
}

void sedanEdit(Sedan* ptr,int noOfEntries,int indexToEdit){
    char menu; //variable bing used to navigate in menu
    re: //goto statement label
    cout<<"Enter 1 to edit Engine Power.\n"
          "Enter 2 to edit Color.\n"
          "Enter 3 to edit Transmission Type.\n"
          "Enter 4 to edit Fault in Car.\n"
          "Enter 5 to edit number of AirBags.\n"
          "Enter 6 to edit type of Power Locks.\n"
          "Enter 7 to edit type of Power Windows.\n"
          "Enter 0 to go back.\n"; //command for output
    cin>>menu; //command for input
    switch (menu) { //switch cases being used to create menu
        case '1':{
            cout<<"Enter Engine Capacity:\n";
            cin>>ptr[indexToEdit].engineCC;
            break;
        }

        case '2':{
            cout<<"Enter Color:\n";
            cin>>ptr[indexToEdit].color;
            break;
        }

        case '3':{
            gI:
            cout<<"Enter Transmission Type:\n";
            cin>>ptr[indexToEdit].transmissionType;
            if (ptr[indexToEdit].transmissionType != "auto" && ptr[indexToEdit].transmissionType != "Auto" && ptr[indexToEdit].transmissionType != "manual" && ptr[indexToEdit].transmissionType != "Manual"){
                cout<<"Enter \"Auto\" or \"Manual\" only.\n";
                goto gI;
            }
            break;
        }

        case '4':{
            cin.ignore();
            cout<<"Enter briefly about Faults in "<<ptr[indexToEdit].vehicleType<<":\n";
            getline(cin,ptr[indexToEdit].fault);
            break;
        }

        case '5':{
            cout << "Enter number of Airbags:" << endl;
            cin >> ptr[indexToEdit].airBags;
            break;
        }

        case '6':{
            cout << "Enter type of Power locks:"<< endl;  // door locking ability of car(single basically automatic system k bahir se lock hojaty hain or dual ka either way )
            cin >> ptr[indexToEdit].powerLocks;
            while (true) {
                if (ptr[indexToEdit].powerLocks != "single" && ptr[indexToEdit].powerLocks != "Single" && ptr[indexToEdit].powerLocks != "dual" &&
                ptr[indexToEdit].powerLocks != "Dual") {
                    cout << "Enter \"single \" or \"dual\" only.\n";
                    cin >> ptr[indexToEdit].powerLocks;
                }
                else
                    break;
            }
            break;
        }

        case '7':{
            cout<<"Type of Power Windows:\n";
            cin >> ptr[indexToEdit].powerWindows;// window locking ability of car(single basically automatic system k bahir se lock hojaty hain or dual ka either way )
            while (true) {
                if (ptr[indexToEdit].powerWindows != "single" && ptr[indexToEdit].powerWindows != "Single" && ptr[indexToEdit].powerWindows != "dual" &&
                ptr[indexToEdit].powerWindows != "Dual") {
                    cout << "Enter \"single \" or \"dual\" only.\n";
                    cin >> ptr[indexToEdit].powerWindows;
                }
                else
                    break;
            }
            break;
        }

        case '0':{
            remove("Sedan Records.txt");
            for (int i = 0; i < noOfEntries; ++i) {
                ptr[i].dataRecord();
            }
            return; //end of program
        }

        default:{
            cout<<"Invalid Input. Enter again.\n";
            goto re;
        }
    }
    goto re;

}

void hatchBackEdit(Hatchback* ptr,int noOfEntries,int indexToEdit){
    char menu; //variable bing used to navigate in menu
    re: //goto statement label
    cout<<"Enter 1 to edit Engine Power.\n"
          "Enter 2 to edit Color.\n"
          "Enter 3 to edit Transmission Type.\n"
          "Enter 4 to edit Fault in Car.\n"
          "Enter 5 to edit number of AirBags.\n"
          "Enter 6 to edit type of Power Locks.\n"
          "Enter 0 to go back.\n"; //command for output
    cin>>menu; //command for input
    switch (menu) { //switch cases being used to create menu
        case '1':{
            cout<<"Enter Engine Capacity:\n";
            cin>>ptr[indexToEdit].engineCC;
            break;
        }

        case '2':{
            cout<<"Enter Color:\n";
            cin>>ptr[indexToEdit].color;
            break;
        }

        case '3':{
            gI:
            cout<<"Enter Transmission Type:\n";
            cin>>ptr[indexToEdit].transmissionType;
            if (ptr[indexToEdit].transmissionType != "auto" && ptr[indexToEdit].transmissionType != "Auto" && ptr[indexToEdit].transmissionType != "manual" && ptr[indexToEdit].transmissionType != "Manual"){
                cout<<"Enter \"Auto\" or \"Manual\" only.\n";
                goto gI;
            }
            break;
        }

        case '4':{
            cin.ignore();
            cout<<"Enter briefly about Faults in "<<ptr[indexToEdit].vehicleType<<":\n";
            getline(cin,ptr[indexToEdit].fault);
            break;
        }

        case '5':{
            cout<<"Enter Number of AirBags:\n";
            cin>>ptr[indexToEdit].airBags;
            break;
        }

        case '6':{
            cout << "Enter type of Power locks:"<< endl;  // door locking ability of car(single basically automatic system k bahir se lock hojaty hain or dual ka either way )
            cin >> ptr[indexToEdit].powerLocks;
            while (true) {
                if (ptr[indexToEdit].powerLocks != "single" && ptr[indexToEdit].powerLocks != "Single" && ptr[indexToEdit].powerLocks != "dual" &&
                    ptr[indexToEdit].powerLocks != "Dual") {
                    cout << "Enter \"single \" or \"dual\" only.\n";
                    cin >> ptr[indexToEdit].powerLocks;
                }
                else
                    break;
            }
            break;
        }

        case '0': {
            remove("HatchBack Record.txt");
            for (int i = 0; i < noOfEntries; ++i) {
                ptr[i].dataRecord();
            }
            return;
        }

        default:{
            cout<<"Invalid Input. Enter again.\n";
            goto re;
        }
    }
    goto re;

}

void sportsCarEdit(SportsCar* ptr,int noOfEntries,int indexToEdit) {
    char menu; //variable bing used to navigate in menu
    re: //goto statement label
    cout << "Enter 1 to edit Engine Power.\n"
            "Enter 2 to edit Color.\n"
            "Enter 3 to edit Transmission Type.\n"
            "Enter 4 to edit Fault in Car.\n"
            "Enter 5 to edit Turbo Type.\n"
            "Enter 6 to edit Spoiler Type.\n"
            "Enter 0 to go back.\n"; //command for output
    cin >> menu; //command for input
    switch (menu) { //switch cases being used to create menu
        case '1': {
            cout << "Enter Engine Capacity:\n";
            cin >> ptr[indexToEdit].engineCC;
            break;
        }

        case '2': {
            cout << "Enter Color:\n";
            cin >> ptr[indexToEdit].color;
            break;
        }

        case '3': {
            gI:
            cout << "Enter Transmission Type:\n";
            cin >> ptr[indexToEdit].transmissionType;
            if (ptr[indexToEdit].transmissionType != "auto" && ptr[indexToEdit].transmissionType != "Auto" &&
                ptr[indexToEdit].transmissionType != "manual" && ptr[indexToEdit].transmissionType != "Manual") {
                cout << "Enter \"Auto\" or \"Manual\" only.\n";
                goto gI;
            }
            break;
        }

        case '4': {
            cin.ignore();
            cout << "Enter briefly about Faults in " << ptr[indexToEdit].vehicleType << ":\n";
            getline(cin, ptr[indexToEdit].fault);
            break;
        }

        case '5': {
            cout << "Enter Turbo Type:\n";
            cin >> ptr[indexToEdit].turboType;
            break;
        }

        case '6': {
            cout << "Enter Spoiler Type:\n";
            cin >> ptr[indexToEdit].spoilerType;
            break;
        }

        case '0': {
            remove("SportsCar Record.txt");
            for (int i = 0; i < noOfEntries; ++i) {
                ptr[i].dataRecord();
            }
            return;
        }

        default: {
            cout << "Invalid Input. Enter again.\n";
            goto re;
        }
    }
    goto re;
}

void employeeEdit(Employee* ptr,int noOfEntries,int indexToEdit){
    char menu; //variable bing used to navigate in menu
    re: //goto statement label
    cout<<"Enter 1 to edit Employee Name.\n"
          "Enter 2 to edit Employee Contact Number.\n"
          "Enter 3 to edit Employee Address.\n"
          "Enter 4 to edit Employee Salary.\n"
          "Enter 0 to go back.\n"; //command for output
    cin>>menu; //command for input
    switch (menu) { //switch cases being used to create menu
        case '1':{
            cout<<"Enter First Name:\n";
            cin>>ptr[indexToEdit].first_name;
            cout<<"Enter Second Name:\n";
            cin>>ptr[indexToEdit].second_name;
            break;
        }

        case '2':{
            cout<<"Enter Contact Number:\n";
            cin>>ptr[indexToEdit].contact_no;
            break;
        }

        case '3':{
            int i;string s;
            cout << "Enter Customer City Name:" << endl;
            cin >> s;
            ptr[indexToEdit].address.setCityName(s);
            cout << "Enter Customer Area Name:" << endl;
            cin.ignore();
            getline(cin, s);
            ptr[indexToEdit].address.setArea(s);
            cout << "Enter Customer Street Number:" << endl;
            cin >> i;
            ptr[indexToEdit].address.setStreetNumber(i);
            cout << "Enter Customer House Number:" << endl;
            cin >> i;
            ptr[indexToEdit].address.setHouseNumber(i);
            break;
        }

        case '4':{
            cout<<"Enter Salary of Employee:\n";
            cin>>ptr[indexToEdit].salary;
            break;
        }

        case '0':{
            remove("Employee Record.txt");
            for (int i = 0; i < noOfEntries; ++i) {
                ptr[i].writeToFile();
            }
            return;
        }

        default:{
            cout<<"Invalid Input. Enter again.\n";
            goto re;
        }
    }
    goto re;
}