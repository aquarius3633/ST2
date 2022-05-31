#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> val;
    string userInput = "";
    char keystrokes;
    int n = 0;
    do {
        
        if(keystrokes == '+' || keystrokes == '-' || keystrokes == '*' || keystrokes == '/')
        {   
            val.push_back(userInput);
            userInput.empty();
            n = 0;
        }
        else
        {
            userInput[n] = keystrokes;
        }
        cout << userInput <<endl;
        n++;
    } while((keystrokes = getchar()) != 'E');
    
    
    for(string item:val){
        cout << item << endl;
    }

}