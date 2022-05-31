#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>

#include <map>

#define DEFDIR "E:\\A_ST2\\ST2_2022\\Assignment2\\"

using namespace std;

class Calculator
{
public:
	map<char, double> memory;
	vector<char> fromFile;
	string dir = DEFDIR;
	string fileName;
	string fullFileName;
	string screenDisplay = "";
	
	char op = ' ';

	double result = 0;
	double previousNumber = 0;

	bool fileExists(const string& fname);
	void do_S();
	void setDirectory(const char* path);
	bool getFileName();
	void displayScreen();
	void clearAll();
	void clearDisplay();
	void toDisplay(double number);
	void printFromFile(char c, bool fromFile);
	int calculate(double& result);
	void do_C(vector<char>* file);
	void do_R();
	void direction();

private: // Set as private to allow to be accessed only by the member functions inside the class
	enum condition // Learned from website & youtube
	{
		StatusIsNormal,
		StatusHasResult,
		SaveToMemory,
		ReadFromMemory,
		ResultIsTrue,
		ResulltIsFalse
	};

	int status = StatusIsNormal;
};

bool Calculator::fileExists(const string& filename)
{
	FILE* file;
	if (0 == fopen_s(&file, filename.c_str(), "r"))
	{
		fclose(file);
		return true;
	}
	else
	{
		return false;
	}
}

bool Calculator::getFileName()
{
	cout << "Enter file name:";
	cin >> fileName;
	cout << endl;
	fullFileName = dir + fileName;
	cout << "Full FileName is:'" << fullFileName << "'" << endl;
	if (fileExists(fullFileName)) return true;
	cout << "** ERROR ** File '" << fullFileName << "'Does not exist" << endl;
	return false;
}

void Calculator::setDirectory(const char* path)
{
	dir = path;
	if (!dir.empty() && dir.back() != '\\' && dir.back() != '/') {
		dir += '\\';
	}
}

void Calculator::direction()
{
	setDirectory(_getcwd(NULL, 0));
}

void Calculator::do_S()
{
	string path;
	cout << "Enter directory:";
	getline(cin, path);
	getline(cin, path);
	setDirectory(path.c_str());

	cout << endl;
	cout << "\nCurrent Directory :" << dir << endl;
}

void Calculator::displayScreen()
{
	cout << endl;
	cout << "(" << op << ") :" << to_string(previousNumber) << endl;
	if (status == SaveToMemory)
	{
		cout << " +M----------+" << endl;
	}
	else if (status == ReadFromMemory)
	{
		cout << " +R----------+" << endl;
	}
	else
	{
		cout << " +-----------+" << endl;
	}
	cout << " |" << setw(10) << screenDisplay << " |" << endl;
	cout << " +-----------+" << endl;
}

void Calculator::clearAll() //Clear screen and memory
{
	op = ' ';
	previousNumber = 0;
	screenDisplay = "";
	memory.clear();
}

void Calculator::clearDisplay() //Clear display only
{
	//if (op != ' ' && op != '?')
	//{
	//	op = ' ';
	//}
	screenDisplay = "";
}

void Calculator::toDisplay(double number) //Display "=" result
{
	ostringstream oString; // This is allowing to use member str to be accessed directly as a string object.
	oString << fixed << setprecision(2) << number;
	screenDisplay = oString.str();
}

void Calculator::printFromFile(char c, bool fromFile)
{
	if (fromFile)
	{
		cout << "key In:";
	}
	cout << c << endl;
}

int Calculator::calculate(double& result)
{
	//Save number from user input here
	double newNumber = stod(screenDisplay.c_str());
	result = newNumber;

	//When there is an operator passed here, do following calculation
	if (op == '+')
	{
		result = previousNumber + newNumber;
	}
	else if (op == '-')
	{
		result = previousNumber - newNumber;
	}
	else if (op == '*')
	{
		result = previousNumber * newNumber;
	}
	else if (op == '/')
	{
		if (newNumber == 0)
		{
			return ResulltIsFalse;
		}
		result = previousNumber / newNumber;
	}
	//else
	//{
	//	return ResultCopy;
	//}
	return ResultIsTrue;
}

void Calculator::do_C(vector<char>* file) // Combine option R and D
{
	clearAll();
	if (!file)  //First to check if there is a file loaded, if no, display calculator
	{
		displayScreen();
	}

	char c;
	while (1)
	{
		if (file) {
			if (file->empty()) {
				break;
			}
			else {
				c = file->at(0);
				file->erase(file->begin());
			}
		}
		else // if no file, start user input
		{
			c = getchar();
		}

		if (c == ';' || c == 'E' || c == 'e') // Exit calculator
		{
			printFromFile(c, file);
			break;
		}

		if (status == SaveToMemory) //Save to memory
		{
			if (c < '0' || c > '9') continue;
			double savedValue = stod(screenDisplay);
			memory[c] = savedValue;
			
			status = StatusHasResult;
			printFromFile(c, file);
			cout << "DEBUG setting M" << c << " to " << fixed << setprecision(6) << savedValue << endl;
		}
		else if (status == ReadFromMemory) // Read from memory
		{
			if (c < '0' || c > '9') continue;
			if (memory.count(c) > 0)
			{
				toDisplay(memory[c]);
			}
			status = StatusHasResult;
			printFromFile(c, file);
		}
		else if (c >= '0' && c <= '9') // User input numbers
		{
			if (status == StatusHasResult) //Handle while "=" is presse
			{
				screenDisplay.clear();
				status = StatusIsNormal;
			}
			int dotIndex = screenDisplay.find('.');
			if (dotIndex >= 0 && screenDisplay.size() - dotIndex - 1 >= 2) continue;
			screenDisplay += c;
			if (op == ' ') op = '?';
			printFromFile(c, file);
		}
		else if (c == 'M' || c == 'm')
		{
			if (screenDisplay.size() <= 0) continue; // check display condition
			status = SaveToMemory;
			printFromFile(c, file);
		}
		else if (c == 'R' || c == 'r')
		{
			status = ReadFromMemory;
			printFromFile(c, file);
		}
		else if (c == '.')
		{
			if (screenDisplay.size() <= 0) continue;
			if ((int)screenDisplay.find('.') > 0) continue; // handle if there is more than one dot
			screenDisplay += c;
			printFromFile(c, file);

		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (screenDisplay.size() <= 0) continue;
			/*double result;*/
			if (calculate(result) == ResulltIsFalse) continue;
			op = c;
			previousNumber = result; // pass user input
			screenDisplay.clear();
			if (status == StatusHasResult)
			{
				status = StatusIsNormal;
				
			}
			printFromFile(c, file);
		}
		else if (c == '=')
		{
			if (screenDisplay.size() <= 0) continue;
			/*double result;*/
			if (calculate(result) != ResultIsTrue) continue;
			op = ' ';
			toDisplay(result);
			status = StatusHasResult;
			printFromFile(c, file);
		}
		else if (c == '!')
		{
			if (screenDisplay.size() <= 0) continue;
			toDisplay(-stod(screenDisplay));
			printFromFile(c, file);
		}
		else if (toupper(c) == 'S') {
			if (screenDisplay.size() <= 0) continue;
			double value = stod(screenDisplay);
			if (value < 0) continue;
			toDisplay(sqrt(value));
			printFromFile(c, file);
		}
		else if (toupper(c) == 'C') {
			clearAll();
			
		}
		else if (toupper(c) == 'K') {
			clearDisplay();
			
		}
		else {
			continue;
		}
		displayScreen();
	}
}

void Calculator::do_R() // Combine option R and D
{
	char byte = 0;
	cout << "\nCurrent Directory :" << dir << endl;
	if (!getFileName()) return;

	ifstream myFile(fullFileName);
	//string line;
	//string text;
	//while (getline(myFile, line)) {
	//	text += line;
	//}

	while (myFile.get(byte))
	{
		fromFile.push_back(byte);
	}
	myFile.close();


	//fromFile.resize(text.size());
	//fromFile.assign(text.begin(), text.end());

	do_C(&fromFile);
}

void displayMenu()
{
	cout << endl;
	cout << "Assign2 2022 Menu" << endl;
	cout << "-----------------" << endl;
	cout << ";  - Exit Calculator" << endl;
	cout << "E  - Exit Menu Or Calculator" << endl;
	cout << "S  - Set Directory" << endl;
	cout << "4  - Run 4 function calculator from keyboard input" << endl;
	cout << "R  - Read single test file and run" << endl;
	cout << "D  - Distinction/HD level Read a test file and run test" << endl;
	cout << "Enter Option:";
}

bool getOption(string& stringInput)
{
	static string options[] = { "E", "S", "4", "R", "D" };
	string menuOption;
	cin >> menuOption;
	stringInput = menuOption;
	transform(stringInput.begin(), stringInput.end(), stringInput.begin(), ::toupper); //cover lower case to Capital
	int n = sizeof(options) / sizeof(string);
	int i = 0;
	for (i = 0; i < n; i++) {
		if (stringInput == options[i]) break;
	}
	if (i == n) {
		cout << "Invalid selected:" << menuOption << endl;
		return false;
	}
	cout << "Option selected:" << menuOption << endl;
	return true;
}

int main()
{
	Calculator cal;
	cal.direction();
	string inputOption;
	cout << "Assignment2 2022! - START RUN -" << endl;
	while (1) {
		displayMenu();
		if (!getOption(inputOption)) continue;
		if (inputOption == "E") {
			cout << "Thank you, see you!" << endl;
			break;
		}
		if (inputOption == "S") {
			cal.do_S();
		}
		else if (inputOption == "4") {
			cal.do_C(NULL); // No file needed for this option
		}
		else if (inputOption == "R") {
			cal.do_R();
		}
		else if (inputOption == "D") {
			cal.do_R();
		}
	}
	return 0;
}
