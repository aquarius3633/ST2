#include <iostream>
#include <string>
using namespace std;

int main() {
    
    for(int i = 1; i <= 25; i++){
        string outPut = "";
        cout << i << " ";
        if (i % 3 == 0) { outPut += "one sister";}
        if (i % 4 == 0) { outPut += "one brother";}
        if (i % 3 == 0 && i % 4 == 0){ outPut = "one sister and one brother";}
        cout << outPut << endl;
    }
}