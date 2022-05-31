#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;
string dir = "";
string filename;
string fullFileName;

enum {
	STATUS_NORMAL,
	STATUS_RESULT,
};

char op = ' ';
double operand1 = 0;
string display = "";
int status = STATUS_NORMAL;



void printCalculator()
{
	cout << endl;
	cout << "(" << op << ") :" << to_string(operand1) << endl;
	cout << " +-----------+" << endl;
	cout << " |" << setw(10) << display << " |" << endl;
	cout << " +-----------+" << endl;
}

void toDisplay(double n)
{
	ostringstream str;
	str << std::fixed << std::setprecision(2) << n;
	display = str.str();
}
void printInput(char c)
{

	cout << c << endl;

}

enum {
	CALCULATE_RESULT_SUCCESSED,
	CALCULATE_RESULT_COPY,
	CALCULATE_RESULT_FAILED,
};

int calculate(double& result)
{
	double operand2 = stod(display.c_str());
	result = operand2;
	if (op == '+') {
		result = operand1 + operand2;
	}
	else if (op == '-') {
		result = operand1 - operand2;
	}
	else if (op == '*') {
		result = operand1 * operand2;
	}
	else if (op == '/') {
		if (operand2 == 0) {
			return CALCULATE_RESULT_FAILED;
		}
		result = operand1 / operand2;
	}
	else {
		return CALCULATE_RESULT_COPY;
	}
	return CALCULATE_RESULT_SUCCESSED;
}

void do_C(string* file)
{
	if (!file) {
		printCalculator();
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
				file->erase(0, 1);
			}
		}
		else {
			c = getchar();
		}

		if (c == ';' || c == 'E' || c == 'e') {
			printInput(c);
			break;
		}

		else if (c >= '0' && c <= '9') {
			if (status == STATUS_RESULT) {
				display = "";
				status = STATUS_NORMAL;
			}
			int dotIndex = display.find('.');
			if (dotIndex >= 0 && display.size() - dotIndex - 1 >= 2) continue;
			display += c;
			if (op == ' ') op = '?';
		}

		else if (c == '.') {
			if (display.size() <= 0) continue;
			if ((int)display.find('.') >= 0) continue;
			display += c;
		}

		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (display.size() <= 0) continue;
			double result;
			if (calculate(result) == CALCULATE_RESULT_FAILED) continue;
			op = c;
			operand1 = result;
			display = "";
			if (status == STATUS_RESULT) {
				status = STATUS_NORMAL;
			}
		}

		else if (c == '=') {
			if (display.size() <= 0) continue;
			double result;
			if (calculate(result) != CALCULATE_RESULT_SUCCESSED) continue;
			op = ' ';
			toDisplay(result);
			status = STATUS_RESULT;
		}

		else {
			continue;
		}
		//printInput(c);
		printCalculator();
	}
}

int main()
{

	do_C(NULL);


	
	return 0;
}
