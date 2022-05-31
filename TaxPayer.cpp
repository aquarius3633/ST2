#include <iostream>
#include <string>
#include "TaxPayer.hpp" 

using namespace std;


TaxPayer::TaxPayer(string taxpayerId, string name, string address, string postcode,
    int salary, int deductions) //Constructor
{
    this->taxpayerId = taxpayerId; //same as TaxPayer.taxpayerId = taxpyerId
    this->name = name;
    this->address = address;
    this->postcode = postcode;
    this->salary = salary;
    this->deductions = deductions;
    taxDue = 0;

    // you can debate if we should call calctax here or not?
}

TaxPayer::~TaxPayer() {} //Destructor - could use default one but deliberatly being explicit

TaxPayer::TaxPayer(TaxPayer& tp) //Copy Constructor - there is a default one - but we will be explicit
{//tp is the object of TaxPayer "TaxPayer&" means the reference of tp object
    taxpayerId = tp.taxpayerId;//access the member attribute from tp object and copy the value to new "taxpayerId" variable
    name = tp.name;
    address = tp.address;
    postcode = tp.postcode;
    salary = tp.salary;
    deductions = tp.deductions;
    taxDue = tp.taxDue;
}

void TaxPayer::showFull()
{
    cout << "Taxpayer id:" << taxpayerId << endl;
    cout << "Name       :" << name << " " << salary << endl;
    cout << "Address    :" << address << endl;
    cout << "Post code  :" << postcode << endl;
    cout << "salary     :" << salary << endl;
    cout << "Deductions :" << deductions << endl;
    cout << "Tax due    :" << taxDue << endl;
}

void TaxPayer::show()
{
    cout << "taxpayer:" << taxpayerId << " " << name << " " << salary << endl;
}

void TaxPayer::setGrossSalary(int salary, int deductions)
{
    this->salary = salary;
    this->deductions = deductions;
}


void TaxPayer::setName(string name)
{
    this->name = name;
}


void TaxPayer::setAddress(string address, string postcode) //(which will include postcode)
{
    this->address = address;
    this->postcode = postcode;
}


double TaxPayer::calcTax() // returns calculated tax and updates taxDue
{
    // there is still a deliberate error here for students to debug
    //taxDue = (salary - deductions) / 100 * 33; // 33% right ?  
    taxDue = (salary - deductions) * 0.33; // 33% 
    return taxDue;
}
