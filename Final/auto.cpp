#include <iostream>
#include <string>

using namespace std;

int main(){
    auto var1 = 21.3 + 34;
    cout << typeid(var1).name() << endl;
}