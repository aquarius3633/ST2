#include <iostream>
#include<string>

using namespace std;

int main(){
    int a = 6;
    int* bozo = nullptr;
    int** jane = nullptr;
    float dix = 34.1f;
    float* dixie = nullptr;

    bozo = jane;                   //---wrong!
    bozo = &a;                     //right
    cout << *dixie << endl;        //----> not sure
    cout << dix->dixie << endl;    //----wrong!
    a = &dix;                      //---wrong!

    

}