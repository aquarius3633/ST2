/* cat.hpp */
#pragma once
using namespace std;
#include <string>

class Cat 
{                   // The class
public:             // Access specifier
    int legs = 4;        // Attribute (int variable)
    virtual string sound();  // Attribute (string variable)
    Cat(string name); // constructor
    string name = string("");

    void show();
    
};


/* end */