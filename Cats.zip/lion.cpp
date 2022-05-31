// code for class Lion 

#include <string>
#include "Cat.hpp"
#include "Lion.hpp"

string Lion::sound()
{
	return std::string("Roar");
}

Lion::Lion() : Cat(string("Kimba"))
{

}


// end
