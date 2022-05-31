// code for class cat 

using namespace std;
#include<iostream>
#include <iomanip> 
#include <string>
#include "Cat.hpp"

string Cat::sound()
{
	return std::string("meooww");
}

Cat::Cat(string name)
{
	this->name = string(name);//why not use this->name??
}

void Cat::show()
{
	cout << "cat Record:" << setw(14)<< name << setw(8) << legs << " legs" << setw(12) << sound();
	cout << endl;
}


// end