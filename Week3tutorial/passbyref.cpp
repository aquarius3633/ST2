#include <iostream>
using namespace std;

void func(int &x)
{
   cout << "x in func before assign to value: " << x << endl;
   cout << "x address in func before assign to value: " << &x << endl;
   x = 4;
   cout << "x in func after assign to value: " << x << endl;
   cout <<"x address in func after assign to value: " << &x << endl;
}

void callfunc()
{
    int x = 7;
    cout << "x in callfunc before pass to func: " << x << endl;
    cout << "x address in callfunc before pass to func: " << &x << endl;
    func(x);
    cout << "x in callfunc after pass to func: " << x << endl;
    cout << "x address in callfunc after pass to func: " << &x << endl;
}

int main() {

    callfunc();
}