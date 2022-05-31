// ExampleTaxClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "TaxPayer.hpp" 

using namespace std;

#define MAXARR 4




void  doTestRoutine()
{
    //test using array of pointers 

    TaxPayer* arr[MAXARR]; // array of 4  pointers to Taxpayer
    arr[0] = new TaxPayer("41235678", "Rupert Mudler", "21 Bastia drive Woolloomooloo NSW", "2011", 51000, 1856);
    arr[1] = new TaxPayer("112345678", "Robyn Janet Muller", "1/45 tinder avenue Agnes Vic", "3692", 21194, 290);
    arr[2] = new TaxPayer("34562391", "Wu Chan", "Hayz Station 284 Great Northern Highway Newman WA", "6753", 51256, 41091);
    arr[3] = new TaxPayer("312945623", "Mr David Von Braun", "67a rocket drive woomera", "5720", 180000, 27291);


    for (int i = 0; i < MAXARR; i++) { arr[i]->show(); }

    for (int i = 0; i < MAXARR; i++) { delete arr[i]; arr[i] = nullptr; }
}

int main()
{
    char ch;
    std::cout << "Taxpayer test harness" << endl;

    TaxPayer  rupert("41235678", "Rupert Mudler", "21 Bastia drive Woolloomooloo NSW", "2011", 51000, 1856);
    rupert.calcTax();
    rupert.showFull();
    std::cout << endl;

    TaxPayer* robyn = nullptr;
    //dynamically allocate new TaxPayer object to heap and use "robyn" pointer points to it
    robyn = new TaxPayer("112345678","Robyn Janet Muller","1/45 tinder avenue Agnes Vic","3692", 21194, 290);
    robyn->calcTax();//same as (*robyn.calcTax())
    robyn->showFull();
    std::cout << endl;

    doTestRoutine();
    
    std::cout << endl;
    std::cout << "enter a character to continue";
    cin >> ch; // stop screen turn off
}

