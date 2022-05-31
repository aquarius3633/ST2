// code for class tabbycat 

#include <string>
#include "Cat.hpp"
#include "tabbyCat.hpp"

string TabbyCat::sound()
{
	return std::string("mew");
}

TabbyCat::TabbyCat(string name) : Cat(name)
{
	
}


// end