#pragma once

class TaxPayer
{
public:
	std::string taxpayerId;
	std::string name;
	std::string address;
	std::string postcode;
	int salary = 0;
	int deductions = 0;
	double taxDue = 0;

	TaxPayer(std::string taxpayerId, std::string name, std::string address, std::string postcode,
		int salary, int deductions); //Constructor
	~TaxPayer(); //Destructor - could use default one but deliberatly being explicit
	TaxPayer(TaxPayer& tp); //Copy Constructor - there is a default one - but we will be explicit
	void showFull();
	void show();
	void setGrossSalary(int salary, int deductions);
	void setName(std::string name);
	void setAddress(std::string address, std::string postcode); //(which will include postcode)
	double calcTax(); //calculate tax(simple version assuming the tax rate is 33 % - updates the taxDue var)

};

