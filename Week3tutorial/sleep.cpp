#include <iostream>
#include <unistd.h>

using namespace std;

int main(){

    cout << "Before Sleep!" << endl;
    
    sleep(4);
    cout << "After Sleep!" << endl;
}