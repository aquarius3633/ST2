#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void recurse(int startNum, int endNum)
{
    int count = 0;
    if (startNum == endNum)
    {
        cout << endNum << endl;
        return;
    }
    if (startNum >= endNum)
    {
        if (startNum % 7 == 0)
        {
            cout << "FizzBuds" << endl;
        }
        else
        {
            cout << startNum << endl;
        }
    }
    recurse(startNum - 1, endNum);
}
int main(){

   recurse(24,1);
}