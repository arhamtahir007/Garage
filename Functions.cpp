//
// Created by HP on 3/26/2023.
//

#include "Functions.h"

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

void returningVehicle() {
    Customer returning = searchCustomer();
    cout<<"Here 1\n";
    cout<<returning.getVehicleType()<<endl;
    if (returning.getVehicleType() == "Sedan") {
        Sedan sedan;
        Vehicle *veh = &sedan;
        sedan.dataReading(returning.getNumberPlate());
        cout << returning;
        veh->vehicleReturn();
        payment();
    } else if (returning.getVehicleType() == "HatchBack") {
        Hatchback hatchback;
        hatchback.dataReading(returning.getNumberPlate());
        Vehicle *veh = &hatchback;
        cout << returning;
        veh->vehicleReturn();
        payment();
    } else if (returning.getVehicleType() == "SportsCar") {
        SportsCar sportsCar;
        Vehicle *veh = &sportsCar;
        sportsCar.dataReading(returning.getNumberPlate());
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
            "Enter 3 to remove an Employee.\n"
            "Enter 4 to see all Employee Data.\n"
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

        case '3': {
            removeEmployee();
            break;
        }

        case '4': {
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
}

void removeEmployee() {
    string counter, name1st, name2nd;
    fstream read("Employee Record.txt", ios::in);
    int noOfEntries = 0;
    while (!read.eof()) {
        getline(read, counter);
        noOfEntries++;
    }
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
        remove("Employee Record.txt");
        for (int i = 0; i < indexToRemove; ++i) {
            removeEmp[i].writeToFile();
        }
        for (int i = indexToRemove + 1; i < noOfEntries; ++i) {
            removeEmp[i].writeToFile();
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
}

void customerManagement(){
    char menu; //variable bing used to navigate in menu
    re: //goto statement label
    cout<<"Enter 1 to search for a Customer & Vehicle.\n"
          "Enter 2 to remove a Customer & Vehicle.\n"
          "Enter 3 to see all Customer records.\n"
          "Enter 0 to exit.\n"; //command for output
    cin>>menu; //command for input
    switch (menu) { //switch cases being used to create menu
        case '1': {
            Customer customer = searchCustomer();
            if (customer.getVehicleType() == "Sedan") {
                Sedan sedan;
                sedan.dataReading(customer.getNumberPlate());
                cout << customer << endl;
                cout << sedan << endl;
            } else if (customer.getVehicleType() == "HatchBack") {
                Hatchback hatchback;
                hatchback.dataReading(customer.getNumberPlate());
                cout << customer << endl;
                cout<< hatchback << endl;
            } else if (customer.getVehicleType() == "SportsCar") {
                SportsCar sportsCar;
                sportsCar.dataReading(customer.getNumberPlate());
                cout << customer << endl;
                cout << sportsCar << endl;
            }
            break;
        }

        case '2':{
            removeCustomer();
            break;
        }

        case '3':{
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

void removeCustomer(){
    string counter, name1st, name2nd;
    fstream read("Customer Record.txt", ios::in);
    int noOfEntries = 0;
    while (!read.eof()) {
        getline(read, counter);
        noOfEntries++;
    }
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
        remove("Customer Record.txt");
        for (int i = 0; i < indexToRemove; ++i) {
            removeCus[i].writeToFile();
        }
        for (int i = indexToRemove + 1; i < noOfEntries; ++i) {
            removeCus[i].writeToFile();
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
        if (removeCus[indexToRemove].getVehicleType() == "Sedan") {
            removeSedan(removeCus[indexToRemove].getNumberPlate());
        }
        else if (removeCus[indexToRemove].getVehicleType() == "HatchBack") {
            removeHatchBack(removeCus[indexToRemove].getNumberPlate());
        }
        else if (removeCus[indexToRemove].getVehicleType() == "SportsCar") {
            removeSportsCar(removeCus[indexToRemove].getNumberPlate());
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
    }
}

void removeSedan(string regNum) {
    string input;
    int indexToRemove = -100;
    ifstream output("Sedan Records.txt");
    int noOfEntries = 0;
    while (!output.eof()) {
        getline(output, input);
        noOfEntries++;
    }
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
        remove("Sedan Records.txt");
        for (int i = 0; i < indexToRemove; ++i) {
            sedan[i].dataRecord();
        }
        for (int i = indexToRemove + 1; i < noOfEntries; ++i) {
            sedan[i].dataRecord();
        }
    }
}


void removeHatchBack(string regNum) {
    string input;
    int indexToRemove = -100;
    ifstream output("HatchBack Record.txt");
    int noOfEntries = 0;
    while (!output.eof()) {
        getline(output, input);
        noOfEntries++;
    }
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
        remove("HatchBack Record.txt");
        for (int i = 0; i < indexToRemove; ++i) {
            hatchback[i].dataRecord();
        }
        for (int i = indexToRemove + 1; i < noOfEntries; ++i) {
            hatchback[i].dataRecord();
        }
    }
}

void removeSportsCar(string regNum) {
    string counter;
    int indexToRemove = -100;
    fstream out("Sports Car Record.txt", ios::in);
    int noOfEntries = 0;
    while (!out.eof()) {
        getline(out, counter);
        noOfEntries++;
    }
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
        remove("SportsCar Record.txt");
        for (int i = 0; i < indexToRemove; ++i) {
            sc[i].dataRecord();
        }
        for (int i = indexToRemove + 1; i < noOfEntries; ++i) {
            sc[i].dataRecord();
        }
    }
}

void viewAllCusVeh() {
    string counter;
    fstream read("Customer Record.txt", ios::in);
    int noOfEntries = 0;
    while (!read.eof()) {
        getline(read, counter);
        noOfEntries++;
    }
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
            sedan.dataReading(customer.getNumberPlate());
            cout << customer << endl << sedan << endl;
        } else if (customer.getVehicleType() == "HatchBack") {
            Hatchback hatchback;
            hatchback.dataReading(customer.getNumberPlate());
            cout << customer << endl << hatchback << endl;
        } else if (customer.getVehicleType() == "SportsCar") {
            SportsCar sportsCar;
            sportsCar.dataReading(customer.getNumberPlate());
            cout << customer << endl << sportsCar << endl;
        }
    }
}