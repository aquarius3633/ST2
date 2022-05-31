#include <iostream>
#include <map>
#include <string>


using namespace std;


int main(){
    map<int, string> myMapie = {
        {34,"Fred"}, 
        {444,"Jane"}, 
        {78, "Simon"}, 
        {2,"Jix"}
        };

    map<int, string>::iterator it;

    for(it = myMapie.begin(); it != myMapie.end(); it++){
        cout << it->first << " => " << it->second << endl;
    }
}