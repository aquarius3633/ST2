#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

int main(){
    
    for(int i = 5; i >= 1; i--){
       
        for(int j = 1; j < i; j++){

            cout  <<  " ";
        }
        cout << string(6-i,'*') << endl;
    }
}