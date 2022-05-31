#include<iostream>

using namespace std;

int main() 
{
    int c, i=0;
    int size;
    char *str = new char[size];//why we need to indicate the number of character
    cout << "Please enter the size of the string you wish to enter:";
    cin >> size;
    cout << "Please enter a string:" << endl;
    while ((c=getchar()) != '\n' ) {
        str[i] = c;
        i++;
    }
    cout << str;
    delete[] str;
    return 0;
}