#include <iostream>


using namespace std;
//class for abstraction
class AbstractClass {
    virtual void applyPenalty() = 0;//pure virtual function, only can be implement by inheritant class
};

class Car{
    public:
        int year;
};


class Employee : AbstractClass{
    private:
        double Salary;
    protected:
        double Bonus;
    public:
        int Age;
        string Name;
        string Company;
        Car* Employeecar;

    //delcare contructor
    Employee(string name, int age, string company);
    //delcare contructor
    //~Employee();
    //copy contructor
    Employee(Employee& cpEmployee);
    
    //delcare some member functions
    void show();
    void setSalary(double salary);
    double getSalary();
    void setBonus(double bonus);
    double getBonus();
    //implement Abstraction method
    void applyPenalty();
};

//initialise constructor
Employee::Employee(string name, int age, string company){
        this->Name = name;
        this->Age = age;
        this->Company = company;
        this->Salary = 0;
        //Employeecar = new Car();
    }
/*Employee::Employee(string name, int age, string company){
    Name = name;
    Age = age;
    Company = company;
    }*/
//initialise deconstructor
//Employee::~Employee(){};

//initialise copy constructor
Employee::Employee(Employee& cpEmployee){
    this->Name = cpEmployee.Name;
    this->Age = cpEmployee.Age;
    this->Company = cpEmployee.Company;
}

void Employee::show(){
        cout <<"Name: " << Name << endl;
        cout <<"Age: " << Age << endl;
        cout <<"Company: " << Company << endl; 
        cout <<"Salary: " << Salary << endl;
        cout <<"Year of this employee's car: " << Employeecar->year << endl;
    }
void Employee::setSalary(double salary) { this->Salary = salary; }
//void Employee::setSalary(double salary) { Salary = salary; }

double Employee::getSalary(){ return Salary; }

void Employee::setBonus(double bonus){ this->Bonus = bonus; }
double Employee::getBonus(){ return Bonus; }

void Employee::applyPenalty(){
    if(Age < 25)
        cout << Name << " 25% Penalty rate applied" << endl;
    else
        cout << Name << " 15% Penalty rate applied" << endl;
}
//CasualEmployee class inheritant from Employee class
//class inheritance by default is private, 
//in order to make inheritant object use super/base class method, 
//we need to explicity use "public" access modifier 
class CasualEmployee:public Employee{ 
    public:
        int AvailableDays;

        CasualEmployee(string name, int age, string company, int availableDays)
            :Employee(name,age,company)
        {
            this->AvailableDays = availableDays;
        }
};
//create another inheritant class
class ContractEmployee:public Employee{
    public:
        int Term;
        ContractEmployee(string name, int age, string company, int term, double bonus)
            :Employee(name,age, company)
        {
            this->Term = term;
            this->Bonus = bonus;
        }
        void applyExtension(){
            if(Bonus > 1000)
                cout << Name << " has successfully applied " << Term <<" months extension " << endl;
            else
                cout << Name << Term <<" month extension application is rejected!" << endl;
    }

};

int main(){
    Employee e1("jack", 23, "Amazon");
    Employee e2("john", 29, "Google");

    /*cout << "Employee 1 salary (Before): " << e1.getSalary() << endl;
    e1.setSalary(1000);
    e2.setSalary(2000);
    e1.applyPenalty();
    cout << "Employee 1 salary (After): " << e1.getSalary() << endl;*/
    cout << endl;
    cout << endl;
    e1.show();
    cout << endl;
    cout << endl;
    e2.show();
/*    cout << endl;
    cout << endl;
    CasualEmployee causal1("Fiona", 35, "Facebook", 4);
    causal1.applyPenalty();
    causal1.setSalary(5000);
    cout << causal1.Name << " salary is: " << causal1.getSalary() << endl;
    causal1.show();
    cout << endl;
    cout << endl;
    ContractEmployee contractor1("Tom", 45, "TikTok", 3, 2400);
    cout << contractor1.Name << "Current Bonus: " << contractor1.getBonus() << endl;
    contractor1.applyExtension();
    contractor1.setSalary(3000);
    contractor1.show();
    contractor1.applyPenalty();
    contractor1.setBonus(500);
    cout << contractor1.Name << "Bonus changed: " << contractor1.getBonus() << endl;
    contractor1.applyExtension();*/
}