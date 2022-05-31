#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <map>
//#include <conio.h>
#include <algorithm>
#include <cmath>


using namespace std;

// This code is taken from the Lecturer
#define DEFDIR "E:\\A_ST2\\ST2_2022\\Assignment2\\"
string dir = DEFDIR;// 
string filename;
string fullFileName;

bool fileExists(const string& fname)
{
	FILE* file;
	if (0 == fopen_s(&file, fname.c_str(), "r"))
	{
		fclose(file);
		return true;
	}
	else
	{
		return false;
	}
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

// Some predefined variables.
char keyPress = ' ';
string str = " ";
bool fullStop = false;
bool memoryYes = false;
bool returnMemory = false;
double num2 = 0.0;
double result = 0.0;
char currentOpr = ' ';
map<char, double> memoryMap;
char memoryStatus = '-';


void addition() // This function is called to handle addition
{
	num2 = atof(str.c_str());
	cout << "This is the value of num2: " << num2 << endl;
	result = result + num2;
	cout << "This is the result of the + equation: " << result << endl;
	currentOpr = keyPress;
	str = " ";
}


void subtraction() // This function is called to handle subtraction
{
	num2 = atof(str.c_str());
	cout << "This is the value of num2: " << num2 << endl;
	result = result - num2;
	cout << "This is the result of the - equation: " << result << endl;
	currentOpr = keyPress;
	str = " ";
}


void multiplication() // This function is called to handle multiplication
{
	num2 = atof(str.c_str());
	cout << "This is the value of num2: " << num2 << endl;
	result = result * num2;
	cout << "This is the result of the * equation: " << result << endl;
	currentOpr = keyPress;
	str = " ";
}


void division() // This function is called to handle division
{
	num2 = atof(str.c_str());
	cout << "This is the value of num2: " << num2 << endl;
	result = result / num2;
	cout << "This is the result of the / equation: " << result << endl;
	currentOpr = keyPress;
	str = " ";
}


void squareRoot() // This function is called to handle the square root function
{
	result = sqrt(result);
	cout << "This is the result of the S equation: " << result << endl;
	currentOpr = keyPress;
	str = " ";
}


void flipSign() // This function is called to handling fliping of the sign (convert from [+] -> [-] or [-] -> [+])
{
	// result *= -1; // https://stackoverflow.com/questions/15111466/fastest-way-to-negate-a-number is the link I used for this.
	result = result * (-1);
	cout << "This is the result of the ! equation: " << result << endl;
	currentOpr = keyPress;
	str = " ";
}


void storeMemory() //This function is called to store the memory
{
	if (memoryYes == true)
	{
		num2 = atof(str.c_str());
		num2 = keyPress;
		memoryMap[keyPress] = result;
		str = " ";
		map<char, double>::iterator iter;
		for (iter = memoryMap.begin(); iter != memoryMap.end(); ++iter)
		{
			cout << iter-> first << " => " << iter-> second << '\n';
		}
	}
}


void accessMemory()
{
	if (returnMemory == true)
	{
		map<char, double>::iterator iter;
		for (iter = memoryMap.begin(); iter != memoryMap.end(); ++iter)
		{
			cout << iter-> first << " => " << iter->second << '\n';
		}
		currentOpr = keyPress;
		str = (to_string(memoryMap.find(keyPress)->second));
		num2 = atof(str.c_str());
	}
}

void equalsSign()
{
	cout << "(" << currentOpr << ") :" << result << setprecision(5) << fixed << endl;
	cout << "+" << memoryStatus << "----------+ " << endl;
	cout << "|          " << result << setprecision(2) << fixed << "|" << endl;
	cout << "+-----------+" << '\n' << endl;
	cout << "The final algorithm has been calculated" << endl;
	num2 = 0;
	result = 0;
	currentOpr = ' ';
	str = " ";
}

void do_R()
{
	vector<string> readfile;

	ifstream inputFile;
	inputFile.open("Test3p2.txt");
	
	cout << "\nCurrent Directory :" << dir << endl;
	if (!getFileName()) return;
	if (getFileName)
	{
		if (!inputFile.is_open())
		{
			cout << "It failed to open the file" << endl;
		}
		
		while (getline(inputFile, str))
		{
			if (str.size() > 0)
			{
				readfile.push_back(str);
			}
				
		}

		for (vector<string>::iterator iter = readfile.begin(); iter != readfile.end(); iter++)
		{
			cout << "(" << currentOpr << ") :" << result << setprecision(5) << fixed << endl;
			cout << "+" << memoryStatus << "----------+ " << endl;
			cout << "|          " << str << "|" << endl;
			cout << "+-----------+" << endl;
			while (keyPress != 'E')
			{
				//c = _getch();
				//keyPress = _getch();
                keyPress = getchar();
				str = str + keyPress;
				cout << "(" << currentOpr << ") :" << result << setprecision(5) << fixed << endl;
				cout << "+" << memoryStatus << "----------+ " << endl;
				cout << "|          " << str << "|" << endl;
				cout << "+-----------+" << endl;
				cout << keyPress << '\n' << endl;
				/*cout << "Character is: " << keyPress << endl;
				cout << "string being built is: " << str << endl;
				linestr = linestr + keyPress;
				cout << "This is the line being made: " << linestr << endl;*/
				if (keyPress == 'E' || keyPress == 'e') // Case E, where E exits the whole program.
				{
					cout << "Thank you for using this calculator program." << endl;
					exit(0);
				}

				if (keyPress == ';') // Case ;, where the semicolon ends the mainCalculator program.
				{
					keyPress = ' ';
					str = " ";
					result = 0.0;
					num2 = 0.0;
					memoryMap.clear();
					break;
				}

				if (keyPress == '\t' || keyPress == '\n' || keyPress == '\r' || keyPress == ' ') continue;
				//If there is an empty line, ignore it.

				if (keyPress == '.') // if there is a fullstop, set a flag. If there are two fullstops, ignore the second.
				{
					fullStop = true;
					if (keyPress == '.' && fullStop == true) continue;
				}

				if (keyPress == '+' || keyPress == '-' || keyPress == '*' || keyPress == '/' || keyPress == 's' ||
					keyPress == '!' || keyPress == '=' || keyPress == 'm' || keyPress == 'c' || keyPress == 'k' ||
					keyPress == ';' || keyPress == 'q' || keyPress == 'M' || keyPress == 'R' || keyPress == 'K')
				{

					if (keyPress == 'c') // If c key is pressed, clear all inputs (and the map).
					{
						num2 = 0;
						result = 0;
						currentOpr = ' ';
						str = " ";
						memoryMap.clear();
						cout << "(" << currentOpr << ") :" << result << setprecision(5) << fixed << endl;
						cout << "(" << currentOpr << ") :" << result << endl;
						cout << "+" << memoryStatus << "----------+ " << endl;
						cout << "|          " << str << "|" << endl;
						cout << "+-----------+" << endl;
						continue;
					}

					if (keyPress == 'k') // If K is pressed, clear the last input. 
					{
						cout << "Pressed k so clear last input" << '\n' << endl;
						str = " ";
						cout << "(" << currentOpr << ") :" << result << setprecision(5) << fixed << endl;
						cout << "+" << memoryStatus << "----------+ " << endl;
						cout << "|          " << str << "|" << endl;
						cout << "+-----------+" << endl;
						continue;
					}


					if (currentOpr == ' ')
						// is this the first time that we have encountered an operator
					{
						result = atof(str.c_str());
						currentOpr = keyPress;
						str = " ";
						continue;
					}
					else
						// Execute the previous operator, and set the new operator to current
					{
						if (currentOpr == '+')
						{
							addition();
						}

						else if (currentOpr == '-')
						{
							subtraction();
						}
						else if (currentOpr == '*')
						{
							multiplication();
						}

						else if (currentOpr == '/')
						{
							division();
						}

						else if (currentOpr == 's')
						{
							squareRoot();
						}

						else if (currentOpr == '!')
						{
							flipSign();
						}

						else if (currentOpr == 'm' || currentOpr == 'M')
						{
							memoryStatus = 'M';
							memoryYes = true;
							storeMemory();
						}

						else if (currentOpr == 'r' || currentOpr == 'R')
						{
							memoryStatus = 'R';
							returnMemory = true;
							accessMemory();
						}

						else if (keyPress == 'q')
						{

						}

						if (keyPress == '=')
						{
							equalsSign();
						}

					}

				}
			}
			memoryMap.clear();
		}
	}
	// ………………. your code here…………………. 
}
// ----------------- End file name code --------------------------


int mainCalculator ()
{
	cout << "(" << currentOpr << ") :" << result << setprecision(5) << fixed << endl;
	cout << "+" << memoryStatus << "----------+ " << endl;
	cout << "|          " << str << "|" << endl;
	cout << "+-----------+" << endl;
	while (keyPress != 'E')
	{
		//c = _getch();
		//keyPress = _getch();
        keyPress = getchar();
		str = str + keyPress;
		cout << "(" << currentOpr << ") :" << result << setprecision(5) << fixed << endl;
		cout << "+" << memoryStatus << "----------+ " << endl;
		cout << "|          " << str << "|" << endl;
		cout << "+-----------+" << endl;
		cout << keyPress << '\n' << endl;
		/*cout << "Character is: " << keyPress << endl;
		cout << "string being built is: " << str << endl;
		linestr = linestr + keyPress;
		cout << "This is the line being made: " << linestr << endl;*/
		if (keyPress == 'E' || keyPress == 'e') // Case E, where E exits the whole program.
		{
			cout << "Thank you for using this calculator program." << endl;
			exit(0);
		}

		if (keyPress == ';') // Case ;, where the semicolon ends the mainCalculator program.
		{
			keyPress = ' ';
			str = " ";
			result = 0.0;
			num2 = 0.0;
			memoryMap.clear();
			break;
		}

		if (keyPress == '\t' || keyPress == '\n' || keyPress == '\r' || keyPress == ' ') continue; 
		//If there is an empty line, ignore it.
		
		if (keyPress == '.') // if there is a fullstop, set a flag. If there are two fullstops, ignore the second.
		{
			fullStop = true;
			if (keyPress == '.' && fullStop == true) continue;
		}

		if (keyPress == '+' || keyPress == '-' || keyPress == '*' || keyPress == '/' || keyPress == 's' || 
			keyPress == '!'|| keyPress == '=' || keyPress == 'm' || keyPress == 'c' || keyPress == 'k' || 
			keyPress == ';' || keyPress == 'q' || keyPress == 'M' || keyPress == 'R' || keyPress == 'K')
		{
			
			if (keyPress == 'c') // If c key is pressed, clear all inputs (and the map).
			{
				num2 = 0;
				result = 0;
				currentOpr = ' ';
				str = " ";
				memoryMap.clear();
				cout << "(" << currentOpr << ") :" << result << setprecision(5) << fixed << endl;
				cout << "(" << currentOpr << ") :" << result << endl;
				cout << "+" << memoryStatus << "----------+ " << endl;
				cout << "|          " << str << "|" << endl;
				cout << "+-----------+" << endl;
				continue;
			}

			if (keyPress == 'k') // If K is pressed, clear the last input. 
			{
				cout << "Pressed k so clear last input" << '\n' << endl;
				str = " ";
				cout << "(" << currentOpr << ") :" << result << setprecision(5) << fixed << endl;
				cout << "+" << memoryStatus << "----------+ " << endl;
				cout << "|          " << str << "|" << endl;
				cout << "+-----------+" << endl;
				continue;
			}


			if (currentOpr == ' ')
			// is this the first time that we have encountered an operator
			{
				result = atof(str.c_str());
				currentOpr = keyPress;
				str = " ";
				continue;
			}
			else
				// Execute the previous operator, and set the new operator to current
			{
				if (currentOpr == '+')
				{
					addition();
				}

				else if (currentOpr == '-')
				{
					subtraction();
				}
				else if (currentOpr == '*')
				{
					multiplication();
				}

				else if (currentOpr == '/')
				{
					division();
				}

				else if (currentOpr == 's')
				{
					squareRoot();
				}

				else if (currentOpr == '!')
				{
					flipSign();
				}

				else if (currentOpr == 'm' || currentOpr == 'M')
				{
					memoryStatus = 'M';
					memoryYes = true;
					storeMemory();
				}

				else if (currentOpr == 'r' || currentOpr == 'R')
				{
					memoryStatus = 'R';
					returnMemory = true;
					accessMemory();
				}

				else if (keyPress == 'q')
				{
					
				}

				if (keyPress == '=')
				{
					equalsSign();
				}

			}
		
		}
	}	
	memoryMap.clear();
	return 0;
}



int main()
{
	char input;
	cout << "ST2 Assignment 2 Menu" << endl;
	cout << "---------------------" << endl;
	cout << "E  - Exit" << endl;
	cout << "S  - Set Directory" << endl;
	cout << "4  - Run 4 function calculator from keyboard input" << endl;
	cout << "R  - Read single test file and run" << endl;
	cout << "D  - Read a test file and run test" << endl;
	cout << "Enter option: ";
	cin >> input; 
	switch (input)
	{
		case 'e':
		{
			cout << "Option selected: " << input << '\n' << endl;
			cout << "Thank you for using this calculator program!" << endl;
			exit(0);
		}
		case 's':
		{
			cout << "Option selected: " << input << '\n' << endl;
			do_S();
		}
		case '4':
		{
			cout << "Option selected: " << input << '\n' << endl;
			mainCalculator();
		}
		case 'r':
		{
			cout << "Option selected: " << input << '\n' << endl;
			getFileName();
			do_R();
		}
		case 'd':
		{
			cout << "Option selected: " << input << '\n' << endl;
			getFileName();
			do_R();
		}
		default:
		{
			cout << '\n';
			cout << "You did not enter a valid option. Please try again." << endl;
			cout << "Note that character inputs are CASE SENSITIVE." << '\n' << endl;
			main();
		}
	}
}

// Logic
// When we press an operator,
// store the first string value in an array or linked list.
// Then, call the getch function again and make the second number.
// When a new operator is pressed, push the string into the list.
// Then, perform the operators function, and set the output of 
// the program to the first number in the list (update the list). 

//if (keyPress == 's')
		//{
		//	// squareRoot()			
		//	/*double num1 = 0.0;
		//	double root = 0.0;
		//	root = sqrt(num1);
		//	cout << root << endl;*/
		//}
		//	
		//if (keyPress == '!')
		//{
		//	// flipSign
		//	num1 = stod(num);
		//	num1 *= -1; // https://stackoverflow.com/questions/15111466/fastest-way-to-negate-a-number is the link I used for this.
		//	cout << num1 << endl;
		//}


//if (keyPress == '+')
		//{
		//	add = true;
		//	if (readingNum1)
		//	{
		//		num1 = atof(str.c_str()); // This is the link that I got atof from.
		//		cout << "This is the first value of num1: " << num1 << endl;
		//		readingNum1 = false;
		//		readingNum2 = true;
		//		str = " ";
		//		continue;
		//	}
		//	if (add = true && readingNum2 == true)
		//	{
		//		num2 = atof(str.c_str());
		//		cout << "This is the value of num2: " << num2 << endl;
		//		result = num1 + num2;
		//		num1 = result;
		//		cout << "This is the result of the equation: " << num1 << endl;
		//		str = " ";
		//	}

		//}
		//if (keyPress == '-')
		//{
		//	subt = true;
		//	if (readingNum1)
		//	{
		//		num1 = atof(str.c_str());
		//		cout << "This is the first value of num1: " << num1 << endl;
		//		readingNum1 = false;
		//		readingNum2 = true;
		//		str = " ";
		//		continue;
		//	}
		//	if (subt = true && readingNum2 == true)
		//	{
		//		num2 = atof(str.c_str());
		//		cout << "This is the value of num2: " << num2 << endl;

		//		result = num1 - num2;
		//		num1 = result;
		//		cout << "This is the result of the equation: " << num1 << endl;
		//		str = " ";
		//	}
		//}
		//if (keyPress == '*')
		//{
		//	times = true;
		//	if (num1 == 0.0)
		//	{
		//		num1 = atof(str.c_str());
		//		cout << "This is the first value of num1: " << num1 << endl;
		//		continue;
		//	}
		//	if (times = true && num1 != 0.0)
		//	{
		//		num2 = atof(str.c_str());
		//		cout << "This is the value of num2: " << num2 << endl;
		//		result = num1 * num2;
		//		num1 = result;
		//		cout << "This is the result of the equation: " << num1 << endl;
		//	}
		//	str = " ";
		//}
		//if (keyPress == '/')
		//{
		//	divide = true;
		//	if (num1 == 0.0)
		//	{
		//		num1 = atof(str.c_str());
		//		cout << "This is the first value of num1: " << num1 << endl;
		//		continue;
		//	}
		//	if (divide = true && num1 != 0.0)
		//	{
		//		num2 = atof(str.c_str());
		//		cout << "This is the value of num2: " << num2 << endl;
		//		result = num1 / num2;
		//		num1 = result;
		//		cout << "This is the result of the equation: " << num1 << endl;
		//	}
		//	str = " ";
		//}
		//if (keyPress == 's')
		//{
		//	squareRoot = true;
		//	if (squareRoot = true && num1 == 0.0) 
		//	{
		//		num1 = atof(str.c_str()); 
		//		cout << "This is the first value of num1: " << num1 << endl;
		//		continue;
		//	}
		//		
		//	if (squareRoot = true && num1 != 0)
		//	{
		//		result = sqrt(num1);
		//		num1 = result;
		//		cout << num1 << endl;
		//	}
		//	str = " ";
		//}
		//if (keyPress == '!')
		//{
		//	flipSign = true;
		//	if (flipSign = true && num1 == 0.0)
		//	{
		//		num1 = atof(str.c_str()); 
		//		cout << "This is the first value of num1: " << num1 << endl;
		//		continue;
		//	}
		//	if (flipSign = true && num1 != 0)
		//	{
		//		result = num1 *= (-1); // https://stackoverflow.com/questions/15111466/fastest-way-to-negate-a-number is the link I used for this.
		//		num1 = result;
		//		cout << num1 << endl;
		//	}
		//	str = " ";
		//}
		//if (keyPress == '=')
		//{
		//	eql = true;
		//	if (eql = true && num1 != 0)
		//	{
		//		cout << result << endl;
		//	}
		//	
		//	str = " ";
		//}