#include <iostream>
#include <string>

using namespace std;

int main(){

    for(int i = 24; i >= 1; i--){
        if (i % 7 == 0) cout << "FizzBuds" << endl;
        else cout << i << endl;
    }

}