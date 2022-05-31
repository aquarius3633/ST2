// code for class Student 


#include<iostream>
#include <iomanip> 
#include <string>

using namespace std;


class Pet
{
public:
	string name;
	Pet(string n);	
	Pet(Pet& p);
	void setName(string n);
};

Pet::Pet(string n)
{
	name = n;
}

Pet::Pet(Pet& p)
{
	this->name = p.name;
}

void Pet::setName(string n)
{
	name = n;
}

class Student
{
public:
	string name;
	string studentId;
	string course;
	Pet* studentsPet = nullptr;//"studentsPet" as a pointer points to Pet object (in this case it initialise to nullptr)
	Student(); // default or empty constructor
	Student(Student& student); // copy constructor
	Student(string name, string id, string course, int age); // main constructor
	~Student(); // destructor (in this case not actually needed)

	void show();
	void setAge(int age);
	int getAge();

	string toString();

private:
	int age;
};



void Student::show()
{
	cout << "Name  :" << setw(14) << name << endl;
	cout << "ID    :" << setw(14) << studentId << endl;
	cout << "Course:" << setw(14) << course << endl;
	cout << "Age   :" << setw(14) << age << endl;	
	cout << "pet   :" << setw(14) << studentsPet->name << endl;
	cout << endl;
}


void Student::setAge(int age)
{
	this->age = age;
}

int Student::getAge()
{
	return age;
}

string Student::toString()
{
	string s = name + " " +
		studentId + " " +
		course + " " +
		to_string(age);
	return s;
}

Student::Student() // default or empty constructor
{
	name = "noname";
	studentId = "000000";
	course = "chicken sexing";
	age = 0;
	studentsPet = new Pet("empty");
}

Student::Student(Student& student) // copy constructor
{	
	this->name=student.name;
	this->studentId = student.studentId;
	this->course = student.course;
	this->age = student.age;
	//this->studentsPet = student.studentsPet; // shallow copy which just copied the memory of Pet object(studentsPet)
	this->studentsPet = new Pet(*(student.studentsPet)); // deep copy
}

Student::Student(string name, string id, string course, int age) // main constructor
{
	this->name=name;
	this->studentId = id;
	this->course = course;
	this->age = age;
	studentsPet = new Pet("Fido");
}

Student::~Student() // destructor (in this case not doing anything)
{
	//delete listofmatks;
}

Student& fred()
{
Student fred1("fred", "200221", "BCOM", 20);
fred1.show();
return fred1;  // fred1 is out of scope and should not be return
}

int main()
{
	// create one local to this function which c++ will delete for me as it goes out of scope 
	Student stu1("Rupert", "300129", "BIT", 18);
	stu1.show(); // call function with .

    Student stu3(stu1); // copy constructor
	stu3.name = "Fred";
	//stu3.studentsPet = new Pet("Kitty");
	stu3.studentsPet->setName("kitty2");
	stu3.show(); // call function with .
	
	stu1.show(); // call function with .

	//// create one using a pointer 
	//Student* stu2 = new Student("Janie", "304169", "BIT", 19);
	//stu2->show(); // call function with ->
	////or 
	//(*stu2).show(); // call function with derefernce and .

	
	//cout << "s.toString() is:" << s.toString() << endl; 
	////s.age = 8; // not allowed
	//s.setAge(8); // works
	//cout << "s.toString() is:" << s.toString() << endl;

	//Student ss = fred(); // omg it let me do it 
	//ss.show();

	//delete stu2;

}

/* end */