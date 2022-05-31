#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <map>
#include <iostream>

#include <iomanip>


using namespace std;

// ---------------- Directory and file names --------------------------
#define DEFDIR "/Users/WEN/Downloads/TestFiles2022Assign2/"


string dir = DEFDIR;
string filename;
string fullFileName;
vector<char> Contents;
char option;
enum Display { DEFAULT_DISPLAY, RESULT_DISPLAY, NEGATE_DISPLAY, SQRT_DISPLAY, MEMORY_DISPLAY, RETRIVE_DISPLAY };
int displayFlag = DEFAULT_DISPLAY;

map<char, double> MemoryContents;
map<char, double>::iterator it;

bool fileExists(string fullFileName)
{
	ifstream openfile;
	openfile.open(fullFileName);
	if (openfile) return true;
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

class Calculator
{
private:
	vector<double> operands{ 0 };
	char operators = ' ';
	string str = "";

public:
	Calculator();
	// ~Calculator();
	// double getOperand1();
	// double getOperand2();
	void add();
	void minus();
	void multiply();
	void divide();
	void calculate(char operators);
	void display();
	void toString(double);

};
//overload constructor
Calculator::Calculator()
{
	displayFlag = DEFAULT_DISPLAY; //initialise display status
	if (!fileExists(fullFileName)) display(); //check whether read from file
	char keystroke;
	while (1)
	{
		//-------------check whether read file or waiting for input from keyboard-----------------
		if (fileExists(fullFileName))     //check file input         
		{
			if (!Contents.empty())
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
		else                             //keyboard input
		{
			keystroke = getchar();
		}
		//-------------check file end -----------------------------------------------------------
		if (keystroke == ';') break;
		else if (keystroke >= '0' && keystroke <= '9')
		{
			if (displayFlag == MEMORY_DISPLAY)
			{
				MemoryContents[keystroke] = stod(str);
				// cout << "---Debugger Map content---" << endl << endl;
				// for(it = MemoryContents.begin(); it != MemoryContents.end(); it++){
				// 	cout << it->first << " => " << it->second << endl;
				// }
				displayFlag = DEFAULT_DISPLAY;
				display();
				continue;
			}
			if (displayFlag == RETRIVE_DISPLAY)
			{
				//display();
				str = to_string(MemoryContents.find(keystroke)->second);
				// cout << "---Debug line R----" << endl << endl;
				// cout << " display string value " << str << endl;
				display();
				displayFlag = DEFAULT_DISPLAY;
				continue;
			}
			if (displayFlag == RESULT_DISPLAY) {
				str.clear();
				operands.front() = 0;
				displayFlag = DEFAULT_DISPLAY;
			}
			else {
				str.clear();
		
				displayFlag = DEFAULT_DISPLAY;
			}
			
			str += keystroke; // building string
			if (operators == ' ') operators = '?';
			// operators = '?';
			display();
		}
		else if (keystroke == '.')
		{
			if (str.find('.') != -1 || displayFlag == MEMORY_DISPLAY || displayFlag == RETRIVE_DISPLAY)
				continue;

			str += keystroke;
			display();
		}
		else if (keystroke == '+' || keystroke == '-' || keystroke == '*' || keystroke == '/')
		{
			if (str.empty() || displayFlag == MEMORY_DISPLAY || displayFlag == RETRIVE_DISPLAY)
				continue;
			if (operands.front() == 0)
			{
				operands.front() = stod(str);
			} // update vector element
			else
			{
				if (displayFlag == RESULT_DISPLAY)
				{
					str.clear();
					displayFlag = DEFAULT_DISPLAY;
				}
				else
				{
					operands.push_back(stod(str));
				}
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
				display();
			}
		}
		else if (keystroke == '=')
		{
			if (displayFlag == RESULT_DISPLAY || str.empty() || displayFlag == MEMORY_DISPLAY || displayFlag == RETRIVE_DISPLAY) continue;
			displayFlag = RESULT_DISPLAY;
			operands.push_back(stod(str));
			calculate(operators);
			// cout << "--------Debugger-----" << endl << endl;
			// cout << "vector Front: " << operands.front() << endl;
			// cout << "display string value: " << str << endl;
			operators = ' ';
			display();
			//str.clear();
			operands.pop_back();

		}
		else if (toupper(keystroke) == 'C') // clear all
		{
			if (displayFlag == MEMORY_DISPLAY || displayFlag == RETRIVE_DISPLAY) continue;
			if (displayFlag == RESULT_DISPLAY) displayFlag = DEFAULT_DISPLAY;
			operands.front() = 0;
			operators = ' ';
			str = "";
			display();
		}
		else if (toupper(keystroke) == 'K') // clear calculator display only
		{
			if (displayFlag == MEMORY_DISPLAY || displayFlag == RETRIVE_DISPLAY) continue;
			if (displayFlag == RESULT_DISPLAY)
			{
				displayFlag = DEFAULT_DISPLAY;
				operands.front() = 0;
			}
			str = "";
			display();
		}
		else if (toupper(keystroke) == 'S') // square root key
		{

			if (displayFlag == MEMORY_DISPLAY || displayFlag == RETRIVE_DISPLAY) continue;
			if (str.empty() || stod(str) < 0 || str.find('-') != -1)
				continue;
			if (displayFlag == RESULT_DISPLAY)
			{
				displayFlag = SQRT_DISPLAY;
				str = to_string(operands.front());
				cout << "Debugger Actual str Value: " << str << endl;
				operands.front() = 0;
			}
			else
			{
				displayFlag = SQRT_DISPLAY;
				//str = to_string(sqrt(stod(str)));
				toString(sqrt(stod(str)));
				cout << "Debugger Actual str Value: " << str << endl;
			}

			display();
			displayFlag = DEFAULT_DISPLAY;
		}
		else if (keystroke == '!')          // negate key
		{
			if (displayFlag == MEMORY_DISPLAY || displayFlag == RETRIVE_DISPLAY) continue;
			if (str.empty() || str == "0")
				continue;
			if (displayFlag == RESULT_DISPLAY)
			{
				str = to_string(operands.front());
				operands.front() = 0;
			}
			// check whether the display value(string) is positive or negative
			if (str.find('-') == -1)
			{ // positive value
				str = "-" + str;
				displayFlag = NEGATE_DISPLAY;
				display();
				cout << "Debugger Actual str Value: " << str << endl;
				displayFlag = DEFAULT_DISPLAY;
			}
			else
			{								// negative value
				size_t pos = str.find('-'); // find negative sign position
				str = str.substr(pos + 1);	// get substring after negative sign re-assign to str variable
				cout << "Debugger updated str value: " << str << endl;
				displayFlag = NEGATE_DISPLAY;
				display();
				cout << "Debugger Actual str Value: " << str << endl;
				displayFlag = DEFAULT_DISPLAY;
			}
		}
		else if (toupper(keystroke) == 'R') // display memory contents
		{
			if (MemoryContents.empty()) continue;
			if (displayFlag == RESULT_DISPLAY)
			{
				if (!MemoryContents.empty()) {
					str = "";
					operands.front() = 0;
					displayFlag = RETRIVE_DISPLAY;
					display();
					continue;
				}
				else
					display();
			}
			else
			{
				if (!MemoryContents.empty())
				{
					displayFlag = RETRIVE_DISPLAY;
					display();
				}
				else
				{
					display();
				}
			}
		}
		else if (toupper(keystroke) == 'M') // add display value to memory
		{
			if (displayFlag == RESULT_DISPLAY)
			{
				displayFlag = MEMORY_DISPLAY;
				str = to_string(operands.front());
				operands.front() = 0;
			}
			if (str.empty()) continue;
			displayFlag = MEMORY_DISPLAY;
			display();
		}
		else
		{
			continue;
		}
	}
}

// Calculator::~Calculator(){}

void Calculator::toString(double n)
{
	ostringstream ss;
	ss << std::fixed << std::setprecision(2) << n;
	str = ss.str();
}

// double Calculator::getOperand1(){ return operands.front(); }
// double Calculator::getOperand2(){ return operands.back();  }
void   Calculator::add() { operands.front() += operands.back(); }
void   Calculator::minus() { operands.front() -= operands.back(); }
void   Calculator::multiply() { operands.front() *= operands.back(); }
void   Calculator::divide() { operands.front() /= operands.back(); }

void Calculator::calculate(char operators)
{
	if (operators == '+') add();
	if (operators == '-') minus();
	if (operators == '*') multiply();
	if (operators == '/') divide();
}

void Calculator::display()
{
	cout << "(" << operators << ") : " << fixed << setprecision(6) << operands.front() << endl;
	cout << " +------------+" << endl;
	switch (displayFlag) {
	case DEFAULT_DISPLAY:
		cout << " | " << setw(10) << right << str << " |" << endl;
		break;
	case RESULT_DISPLAY:
		cout << " | " << setw(10) << right << fixed << setprecision(2) << operands.front() << " |" << endl;
		break;
	case NEGATE_DISPLAY:
		cout << " | " << setw(10) << right << fixed << setprecision(2) << stod(str) << " |" << endl;
		break;
	case SQRT_DISPLAY:
		cout << " | " << setw(10) << right << fixed << setprecision(2) << stod(str) << " |" << endl;
		break;
	case MEMORY_DISPLAY:
		cout << " | " << setw(10) << right << str << " |" << endl;
		break;
	case RETRIVE_DISPLAY:
		cout << " | " << setw(10) << right << fixed << str << " |" << endl;
		break;
	}
	cout << " +------------+" << endl;
}

void do_S()
{
	cout << "enter directory:";
	cin >> dir;
	cout << endl;
	cout << "\nCurrent Directory :" << dir << endl;
}
void do_R()
{
	cout << "\nCurrent Directory :" << dir << endl;
	if (!getFileName()) return;
	// ������. your code here�������. 
	string fileContents;
	int i;
	ifstream myFile(fullFileName);
	if (!myFile.is_open()) { cout << "Fail to open the file!!!!!" << endl; return; }
	while (getline(myFile, fileContents)) {
		cout << "--- Debugger line --- " << fileContents << endl;
		for (string::iterator it = fileContents.begin(); it != fileContents.end(); ++it) {
			if (isspace(*it)) continue;
			//cout << "Debug Key In -> " << *it << " ";
			Contents.push_back(toupper(*it));
		}
	}
	myFile.close();
	Calculator calculateMyFileObject;//constructor 4 function calculator
}
// ----------------- End file name code --------------------------



void do_C()
{
	Calculator cal;//constructor 4 function calculator
}

void displayMenu()
{
	do {
		cout << endl << endl;
		cout << "Assign2 2022 Menu" << endl;
		cout << "-----------------" << endl;
		cout << "E  - Exit" << endl;
		cout << "S  - Set Directory" << endl;
		cout << "4  - Rund 4 function calculator from keyboard input" << endl;
		cout << "R  - Read single test file and run" << endl;
		cout << "Enter Option: ";
		cin >> option;
		cout << "Option selected: " << option << endl;
		switch (toupper(option)) {
		case 'E':
			break;
		case 'S':
			do_S();
			break;
		case '4':
			do_C();
			break;
		case 'R':
			do_R();
			break;
		default:
			cout << "Invalid. Please re-enter your option!!!" << endl;
			break;
		}

	} while (toupper(option) != 'E');
}

int main()
{
	displayMenu();
	return 0;
}

