#include <iostream>

using namespace std;
class Pet{
    public:
        string petname;
        Pet(string pn){ 
            petname = pn; 
        }
};

class Student{
    private:
        int age;
        int studentId;
        string fname;
        string lname;

    public:
        Pet *studentPet;
        //constructor
        Student(string fname, string lname, int age, int studentId){
            this->fname = fname;
            this->lname = lname;
            this->age = age;
            this->studentId = studentId;
            Pet *studentPet = new Pet("a");
            cout << "constructor invoked" << endl;
        }
        //copy constructor
        Student(const Student& s){
            this->fname = s.fname;
            this->lname = s.lname;
            this->age = s.age;
            this->studentId = s.studentId;
            this->studentPet = s.studentPet;//shallow copy
            this->studentPet = new Pet(*(s.studentPet)); //deep copy
            cout << "copy constructor invoked!" << endl;
        }
};


int main(){




}