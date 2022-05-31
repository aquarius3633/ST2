#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

// ---------------- Directory and file names --------------------------
#define DEFDIR "/Users/WEN/Downloads/TestFiles2022Assign2/"


string dir = DEFDIR;
string filename;
string fullFileName;

vector<char> Contents; // store charaters from file reading
map<char, double> MemoryContents; 
map<char,double>::iterator it;

string memoryKey; 
string retriveKey; 
double resultValue;
char keystroke;
char option;

//flag for display screen
enum Display { DEFAULT_DISPLAY, RESULT_DISPLAY, NEGATE_DISPLAY,SQRT_DISPLAY,MEMORY_DISPLAY, RETRIVE_DISPLAY};
int displayFlag = DEFAULT_DISPLAY;

bool fileExists(string fullFileName)
{
	ifstream openfile;
	openfile.open(fullFileName);
	if(openfile) return true;
	else return false;
}

bool getFileName()
{
	cout << "enter filename:";
	cin >> filename;
	cout << endl;
	fullFileName = dir + filename;
	cout << "Full FileName is:'" << fullFileName << "'" << endl;
	if (fileExists(fullFileName)) return true;
	cout << "** ERROR ** File '" << fullFileName << "'Does not exist";
	return false;
}

void do_S()
{
	cout << "enter directory:";
	cin >> dir;
	cout << endl;
	cout << "\nCurrent Directory :" << dir << endl;
}

// ----------------- End file name code --------------------------

class Calculator
{
private:
    vector<double> operands{0};
    char operators = ' ';
	string str = "";
public:
    Calculator();
    void add();
    void minus();
    void multiply();
    void divide();
    void calculate(char);
    void display();
	void processKeystrokes(char);
};

//overload constructor
Calculator::Calculator()
{
	if(!fileExists(fullFileName)) display();
	processKeystrokes(keystroke);
}

void Calculator::add()       { operands.front() += operands.back(); }
void Calculator::minus()     { operands.front() -= operands.back(); }
void Calculator::multiply()  { operands.front() *= operands.back(); }
void Calculator::divide()    { operands.front() /= operands.back(); }

void Calculator::calculate(char operators)
{
	if(operators == '+') add(); 
	if(operators == '-') minus();
	if(operators == '*') multiply();
	if(operators == '/') divide();
}

void Calculator::processKeystrokes(char keystroke)
{
	while(1)
	{
//-------------check whether read file or waiting for input from keyboard-----------------
		if(fileExists(fullFileName))                  
		{
			if(!Contents.empty()) 
			{
				keystroke = Contents.front();
				cout << "Key In: " << keystroke << endl << endl;
				Contents.erase(Contents.begin());
			}
			else
			{
				fullFileName.clear();//reset file name to empty
				break;
			}
		}
		else
		{
			keystroke = getchar();
		}
//-------------check file end -----------------------------------------------------------

// add display value to memory------------------------------------------------------WRONG!!!
		// if(displayFlag == MEMORY_DISPLAY){
		// 	cout << "Debug current key: " << memoryKey << endl;
		// 	if(keystroke >= '0' && keystroke <= '9'){
		// 		memoryKey += keystroke;
		// 		cout << "Debug Memory Key: " << memoryKey << endl;
		// 		MemoryContents.insert(pair<char,double>(keystroke, stod(str)));
		// 		cout << "Debug setting " << memoryKey << " to " << stod(str) << endl;
		// 		memoryKey.clear(); //reset memory key back to null and break out loop	
		// 		display();
		// 		displayFlag = DEFAULT_DISPLAY;
		// 	}
		// }
//retrive memory ------------------------------------------------------------------WRONG!!!
		// if(displayFlag == RETRIVE_DISPLAY){
		// 	retriveKey += keystroke;
		// 	cout << "retriveKey: " << retriveKey << endl;
		// 	it = MemoryContents.find(keystroke);
		// 	if(it != MemoryContents.end())
		// 	{
		// 		str = to_string(MemoryContents.find(keystroke)->second);
		// 		cout << "Debug retrive key" << retriveKey << " Value " << fixed << setprecision(2) << stod(str) << endl;
		// 		display();
		// 		displayFlag = DEFAULT_DISPLAY;
		// 		retriveKey.clear();
		// 		continue;
		// 	} else continue;
		// }

		if(keystroke == ';') break; 					  //exit to menu
		else if (keystroke >= '0' && keystroke <= '9')    // building string
		{
			if(displayFlag == RESULT_DISPLAY){
				str = "";
				operands.front() = 0;
				displayFlag = DEFAULT_DISPLAY;
			}
			str += keystroke; 
			// operators = '?';
			display();
		}
		else if (keystroke == '.')                        // building string
		{
			if (str.find('.') != -1) continue;
			str += keystroke;
			display();
		}
		else if (keystroke == '+' || keystroke == '-' || keystroke == '*' || keystroke == '/')
		{
			if (str.empty()) continue;
			if (displayFlag == RESULT_DISPLAY) {
				str = "";
				displayFlag = DEFAULT_DISPLAY;
				display();
				continue;
			}
			//check whether add first or second operand to vector container
			//if (operands.front() == 0)
			if (operands.front() == 0)
			{
				operands.front() = stod(str);// update first operand 
			} 
			else
			{
				operands.push_back(stod(str));// update second operand
			}
			str.clear();
			// check whether there are two items in the vecor or not
			if (operands.size() == 2)
			{
				calculate(operators); // calculate with previous operators
				operands.pop_back();
				operators = keystroke; // update new operators
				display();
			}
			else
			{
				operators = keystroke; // update current operator
				str.clear();
				display();
			}
		}
		else if (keystroke == '=')
		{
			if(displayFlag == RESULT_DISPLAY || str.empty()) continue;
			displayFlag = RESULT_DISPLAY;
			operands.push_back(stod(str));
			calculate(operators);
			str = to_string(operands.front());
			operators = ' ';
			cout << "Vector front item: " << operands.front() << endl;
			cout << "Vector size  " << operands.size() << endl;
			cout << "Current display Value: " << str << endl;
			display();
			operands.clear();
			cout << "Vecotr size after clear: " << operands.size() << endl;
			cout << "Vector front item: " << operands.front() << endl;
		}
		else if (toupper(keystroke) == 'C') // clear all
		{
			operands.front() = 0;
			operators = ' ';
			str = "";
			display();
		}
		else if (toupper(keystroke) == 'K') // clear calculator display only
		{
			str = "";
			display();
		}
		else if (toupper(keystroke) == 'S') // sqare root key
		{

			if (str.empty() || str.find('-') != -1)
				continue;
			str = to_string(sqrt(stod(str)));
			displayFlag = SQRT_DISPLAY;
			display();
			cout << "Debugger Actual str Value: " << str << endl;
			displayFlag = DEFAULT_DISPLAY;
		}
		else if (keystroke == '!')          // negate key
		{

			if (str.empty() || str == "0")
				continue;
			// check whether the display value(string) is positive or negative
			if (str.find('-') == -1)   // positive value
			{ 
				str = "-" + str;
				displayFlag = NEGATE_DISPLAY;
				display();
				cout << "Debugger Actual str Value: " << str << endl;
				displayFlag = DEFAULT_DISPLAY;
			}
			else                      // negative value
			{								
				size_t pos = str.find('-'); // find negative sign position
				str = str.substr(pos + 1);	// get substring after negative sign re-assign to str variable
				cout << "Debugger updated str value: " << str << endl;
				displayFlag = NEGATE_DISPLAY;
				display();
				cout << "Debugger Actual str Value: " << str << endl;
				displayFlag = DEFAULT_DISPLAY;
			}
		}
		else if (toupper(keystroke) == 'R') // display memory contents to screen------------------ WRONG!!!
		{
			if(!str.empty() || MemoryContents.empty()) continue;
			retriveKey += keystroke;
			displayFlag = RETRIVE_DISPLAY;
			display();
		}
		else if (toupper(keystroke) == 'M') // start add contents to memory------------------------WRONG!!!
		{
			
			if(resultValue || str.empty()){
				memoryKey += keystroke;
				displayFlag = MEMORY_DISPLAY;
				display(); 
			}
			
		}
		
		else                              //ignore other invalid input
		{
			continue;
		}
	}
	
}
void Calculator::display()
{
    switch(displayFlag){
		case DEFAULT_DISPLAY:
			cout << "(" << operators << ") : " << fixed << setprecision(6) << operands.front() << endl;
			cout << " +------------+" << endl;
			cout << " | " << setw(10) << right << str << " |" << endl;
			cout << " +------------+" << endl;
			break;
		case RESULT_DISPLAY:
			cout << "(" << operators << ") : " << fixed << setprecision(6) << operands.front() << endl;
			cout << " +------------+" << endl;
			cout << " | " << setw(10) << right << fixed << setprecision(2) << stod(str) << " |" << endl;
			cout << " +------------+" << endl;
			break;
		case NEGATE_DISPLAY:
			cout << "(" << operators << ") : " << fixed << setprecision(6) << operands.front() << endl;
			cout << " +------------+" << endl;
			cout << " | " << setw(10) << right << fixed << setprecision(2) << stod(str) << " |" << endl;
			cout << " +------------+" << endl;
			break;
		case SQRT_DISPLAY:
			cout << "(" << operators << ") : " << fixed << setprecision(6) << operands.front() << endl;
			cout << " +------------+" << endl;
			cout << " | " << setw(10) << right << fixed << setprecision(2) << stod(str) << " |" << endl;
			cout << " +------------+" << endl;
			break;
		case MEMORY_DISPLAY:
			cout << "(" << operators << ") : " << fixed << setprecision(6) << operands.front() << endl;
			cout << " +M-----------+" << endl;
			cout << " | " << setw(10) << right << str << " |" << endl;
			cout << " +------------+" << endl;
			break;
		case RETRIVE_DISPLAY:
			cout << "(" << operators << ") : " << fixed << setprecision(6) << operands.front() << endl;
			cout << " +R-----------+" << endl;
			cout << " | " << setw(10) << right << fixed << setprecision(2) << stod(str) << " |" << endl;
			cout << " +------------+" << endl;
			break;
	}
}

void do_R()
{
	cout << "\nCurrent Directory :" << dir << endl;
	if (!getFileName()) return;
// ………………. your code here…………………. 
	string fileContents;
	int i;
	ifstream myFile(fullFileName);
	if(!myFile.is_open()) { cout << "Fail to open the file!!!!!" << endl; return;}
	while(getline(myFile, fileContents)){
		//cout <<"--- Debugger line --- " << fileContents << endl;
		for(string::iterator it = fileContents.begin(); it != fileContents.end(); ++it){
			if(isspace(*it)) continue;
			cout << "Key In-> " << *it << endl;
			Contents.push_back(toupper(*it));
		}
	}
	myFile.close();
	Calculator calculateMyFileObject;
}

void do_Calculation()
{
	Calculator cal;
}

void displayMenu()
{
	do{
		cout << endl << endl;
		cout << "Assign2 2022 Menu" << endl;
		cout << "-----------------" << endl;
		cout << "E  - Exit"         << endl;
		cout << "S  - Set Directory"<< endl;
		cout << "4  - Rund 4 function calculator from keyboard input" << endl;
		cout << "R  - Read single test file and run" << endl;
		cout << "Enter Option: ";
		cin  >> option;
		cout << "Option selected: " << option << endl;
		switch(toupper(option)){
			case 'E':
				break;
			case 'S':
				do_S();
				break;
			case '4':
				do_Calculation();
				break;
			case 'R':
				do_R();
				break;
			default:
				cout << "Invalid. Please re-enter your option!!!" << endl;
				break;
		}
		
	}while(toupper(option) != 'E');
}
	
int main()
{
	displayMenu();
    return 0;
}

