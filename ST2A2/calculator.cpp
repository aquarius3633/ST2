// calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <cmath>


using namespace std;

// main.cpp
// calculator using vectors

#include <iostream>
#include <vector>
#include <stdexcept>
char c = ' ';
char op = ' ';
//double value = 0;
double currentNum = 0;
double preNum = 0;
double result = 0;
double square = 0;
string temstr = "";
map<char, double> memory;
//vector<double> num;


void myCalculator();

enum saveAndRead {
    defaultP,
    save,
    read,
    resultF
};

int option = defaultP;


bool IsSymbol(char a) {
    char symbols[4] = { '+', '-', '*', '/'};
    for (int i = 0; i < 4; i++) {
        if (symbols[i] == a) {
            return true;
        }
    }
    return false;
}

void displayDefault() {
    cout << "(" << op << ") :" << fixed << setprecision(6) << preNum << endl;
    if (option == save)
    {
        cout << "+M----------+" << endl;
    }
    else if (option == read)
    {
        cout << "+R----------+" << endl;
    }
    else 
    {
        cout << "+-----------+" << endl;
    }
    cout     << "|" << setw(10) << temstr << " |" << endl;
    cout     << "+-----------+" << endl;

}


void displayResult() {
    cout << "(" << op << ") :" << fixed << setprecision(6) << preNum << endl;
    cout << "+-----------+" << endl;
    cout << "|" << setw(10) << fixed << setprecision(2) << result << " |" << endl;
    cout << "+-----------+" << endl;

}


double calculate(double& result) {
    currentNum = stod(temstr);
    //convert the previous number(stored as string) into double
    //cout << "current num" << currentNum << endl;
    result = currentNum;
    //cout << "result" << result << endl;

    if (op != ' ') {
        switch (op) {
        case '+':
            result = preNum + currentNum;
            //cout << "addition result" << result << endl;
            break;
        case '-':
            result = preNum - currentNum;
            //cout << "sub result" << result << endl;
            break;
        case '*':
            result = preNum * currentNum;
            //cout << "mul result" << result << endl;
            break;
        case '/':
            result = preNum / currentNum;
            //cout << "div result" << result << endl;
            break;
        default:
            throw std::runtime_error("Error");
        }
    }

    
    
}



void myCalculator() {
    
    //cout << "(for debug) key in = " << c << endl;
    option = defaultP;

    displayDefault();

    while (c != 'E')
    {
        //c = _getch();
        // c is to get user input
        c = getchar();

        if (isdigit(c) || c=='.') {
            if (option == save)
            {
                if (c < '0' || c > '9') continue;
                double value = stod(temstr);
                memory[c] = value;
                cout << "m  " << c << " " << " value: " << value << endl;
                displayDefault();
                option = defaultP;
                continue;
            }
            if (option == read)
            {
                if (c < '0' || c>'9') continue;
                if (memory.count(c) > 0) {
                    double v = memory[c];
                    temstr = to_string(v);
                    //calculate(result);
                    //op = c;
                    //cout << c << endl;
                    //preNum = result;
                    stringstream sstr;
                    sstr << fixed << setprecision(2) << v;
                    temstr = sstr.str();
                    
                    
        /*            cout <<"r: " << memory[c] << endl;*/
                    //temstr = memory[c];
                    displayDefault();
                    option = resultF;
                    continue;
                }
            }
            else {
                temstr = temstr + c;
                cout << temstr << endl;
                //store the number in the temporary string
                //if (op == ' ') { op = '?'; }
                displayDefault();
            }
            
        }
        if (IsSymbol(c)) {
            
            //after calculation
            //update the operator
            calculate(result);
            op = c;
            cout << c << endl;
            //store the result into prenum for the next calculation
            preNum = result;
            
            temstr.clear();
            displayDefault();

            if (option == resultF) {
                option = defaultP;
            }

            
        }

        if (option == save)
        {
            if (c < '0' && c > '9') continue;
            double value = stod(temstr);
            memory[c] = value;
            cout << "m  " << c << " " <<" value: " << value << endl;
        }
        
        if (c == '=')
        {
            calculate(result);
            //double r = ("%.2f\n", result);
            //cout << r << endl;
            op = ' ';
            //temstr = to_string(r);
            displayResult();
            option = resultF;
        }
        if (c == 's') {
            cout << c << endl;
            if (result == 0) {
                
                square = stod(temstr);
                result = sqrt(square);
                displayResult();
            }
            else {
                result = sqrt(result);
                displayResult();
            }
            
        }
        if (c == '!') {
            cout << c << endl;
            if (result == 0) {
                double negative = stod(temstr);
                result = negative*(-1);
                displayResult();
            }
            else {
                result *= -1;
                displayResult();
            }
        }

        if (c == 'c'|| c == 'C') {
            cout << c << endl;
            preNum = 0;
            currentNum = 0;
            result = 0;
            op = 0;
            temstr = ' ';
            displayDefault();
        }

        if (c == 'k' || c == 'K') {
            /*result = 0;
            op = 0;*/
            cout << c << endl;
            op = 0;
            temstr.clear();
            displayDefault();
        }
        
        if (c == ';') {
            break;
        }

        if (c == '.') { 
            if (temstr.find('.') != -1) continue; 
            temstr += c; }

        if (c == 'm' || c == 'M') {
            cout << c << endl;
            if (temstr.empty()) continue;
            option = save;
            displayDefault();
        }

        if (c == 'r' || c == 'R') {
            cout << c << endl;
            option = read;
            displayDefault();

        }

        /*if (c=='.' || temstr.find('.') != string::npos) {
            cout << "You entered two dots. " << endl; 
        }
        if (temstr.find('.') != -1) continue;*/
        
  
    }
       
}




int main() {
    
    myCalculator();
    return 0;
}


  
