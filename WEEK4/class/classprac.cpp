#include <iostream>
#include <string>

using namespace std;

class Taxpayer{
    string taxplayerid;
    string name;
    string address;
    int postcode;
    int salary;
    int deductions;
    double taxdue;

    //constructor
    Taxpayer(string taxplayerid, string name, string address, int postcode, 
            int salary, int deductions) 
    {
        this->taxplayerid = taxplayerid;
        this->name = name;
        this->address = address;
        this->postcode = postcode;
        this->salary = salary;
        this->deductions = deductions;
        taxdue = 0;
    }

    //destructor
    ~Taxpayer(){}

    //copy constructor
    Taxpayer(Taxpayer& tp){
        taxplayerid = tp.taxplayerid;
        name = tp.name;
        address = tp.address;
        postcode = tp.postcode;
        salary = tp.salary;
        deductions = tp.deductions;
        taxdue = tp.taxdue;
    }

};

int main() {

/*     Taxpayer mk = new Taxpayer(7101003,Mike,23 boinig road,2615,48000,12000,0);
    Taxpayer jn = new Taxpayer(7201003,Jane Philips,29 boinig cresent,2616,47000,12000,0);
    Taxpayer pl = new Taxpayer(7301003,Philip Jane,23 bong road,2615,49000,000,0);
    Taxpayer pt = new Taxpayer(7401004,Peta,23 bong bong road,2615,148000,19000,0);
    Taxpayer ad = new Taxpayer(7101205,Abdulla,23 Station st,2615,80000,21000,0); */


    return 0;

}