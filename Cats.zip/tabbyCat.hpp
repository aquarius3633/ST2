#pragma once

#include <string>

using namespace std;
#include "cat.hpp"

class TabbyCat : public Cat
{                   // The class
public:             // Access specifier
    
    string sound();  // Attribute (string variable)
    TabbyCat(string name);

};



