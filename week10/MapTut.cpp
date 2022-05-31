#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>
using namespace std;


class NameAndNumber
{
public:
    std::string number;
    std::string name;
    NameAndNumber();
    NameAndNumber(std::string nam, std::string num);
    void show();
};
NameAndNumber::NameAndNumber(string num, string nam)
{
    name = nam;
    number = num;
}
NameAndNumber::NameAndNumber() // default constructor
{
    name = "";
    number = "";
}
void NameAndNumber::show()
{
    cout << setw(7) << number << " " << setw(20) << name << " ";
}
int main()
{
    
    cout << "\n\n\n Task 6 \n\n";
    // Then declare the map:
    map <string, NameAndNumber> nnmap = {}; 
    // finally we can populate the map shown here using two different approaches , the second one is 
    // IMHO much better because it keeps the Key in synch with the relevant record.
    // now add a couple
        nnmap["John"] = NameAndNumber("66","John");
        nnmap["Fred"] = NameAndNumber("22","Fred");
        //of course this may be a better way 
    NameAndNumber rupert("23","Ruby");
    nnmap[rupert.name] = rupert; 
    // this way name is same as in the record guaranteed
    // and finally print the contents of the map.
    map<string, NameAndNumber>::iterator P6iter;  // construct an iterator
    for (P6iter = nnmap.begin(); P6iter != nnmap.end(); ++P6iter)
    {
        cout << P6iter->first << " - ";
        P6iter->second.show();
        cout << '\n';
    }
}