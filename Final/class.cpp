#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NameAndDetails
{
private:
    int id;
public:
    string firstname;
    string lastname;
    bool isTaxpayer;
    vector<double>* salary;
};
