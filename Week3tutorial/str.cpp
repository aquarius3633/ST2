#include <iostream>
#include <string>

using namespace std;

int main(){
    string name = "/Users/WEN/projects/ST2MidTermProject/NamesdataA1Txttst.txt";
    int index = name.rfind("N");
    cout << name.substr(index) << endl;

}