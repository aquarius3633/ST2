#pragma once

#include <string>

using namespace std;
#include "cat.hpp"

class Lion : public Cat
{                   // The class
public:             // Access specifier

    string sound();  // Attribute (string variable)
    Lion();

};




