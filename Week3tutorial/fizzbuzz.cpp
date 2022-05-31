//Write a program that prints the numbers from 1 to 100. But for multiples of three print “Fizz” instead 
//of the number and for the multiples of five print “Buzz”. For numbers which are multiples of both 
//three and five print “FizzBuzz”.

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n){
        vector<string> v;
        for(int i = 1; i <= 15; i++){
            if(i % 15 == 0) v.push_back("FizzBuzz");
            else if(i % 3 == 0) v.push_back("Fizz");
            else if(i % 5 == 0) v.push_back("Buzz");
            else v.push_back(to_string(i));
        }
    return v;
    }
        
};

int main() {
    
    // for(int i = 1; i <= 25; i++){
    //     string outPut = "";
    //     if (i % 3 == 0) { outPut += "one sister";}
    //     if (i % 4 == 0) { outPut += "one brother";}
    //     if (outPut == ""){ outPut = to_string(i);}
    //     cout << outPut << endl;
    // }
    Solution s;
    vector<string> vec = s.fizzBuzz(3);
    for(string items : vec){
        cout << items << " ";
    }
}