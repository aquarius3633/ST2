// Header file for input output functions 
#include<iostream>  

using namespace std;

#include "cat.hpp"
#include "lion.hpp"
#include "TabbyCat.hpp"

Cat* catInstance = NULL; // old way of null pointer 
Lion* lionInstance = nullptr;// new way of null pointer 
TabbyCat* tabbyInstance = nullptr;



int main()
{
    char ch;
    // prints hello world 
    cout << "Hello Cats main1" << endl;
    catInstance = new Cat(string("Crookshanks"));
    catInstance->show();
    tabbyInstance = new TabbyCat(string("Salem")); 
    tabbyInstance->show();
    lionInstance = new Lion();
    lionInstance->show();
    cout << "Enter a character to exit:";
    cin >> ch;
    delete catInstance;    
    delete tabbyInstance; 
    delete lionInstance;
    return 0;
}
