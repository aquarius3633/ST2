#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
class EmployeeAccount{        
private:
//member variable
    string accountNumber;
    string title;
    string firstname;
    string lastname;
    string currentSalesperson;
    string company;
    double purchaseValue;
    string prev_salestaff;
    double commission;
    
public:
   
//overload constructor
    EmployeeAccount(string employeeAccountInfo)
    {
        string str;
        vector<string> v;
        int index = 0;
        stringstream employeeAccountStream(employeeAccountInfo);
        while(getline(employeeAccountStream, str, ','))
        { 
            //Warning!!! hard coding here.... 
            switch(index){
                case 0:
                accountNumber = str;
                break;
                case 1:
                title = str;
                break;
                case 2:
                firstname = str;
                break;
                case 3:
                lastname = str;
                break;
                case 4:
                company = str;
                break;
                case 5:
                currentSalesperson = str;
                break;
                case 6:
                purchaseValue = stod(str);
                //purchaseValue = atof(str.c_str());
                break;
                case 7:
                prev_salestaff = str;
                break;
                case 8:
                commission = stod(str);
                //purchaseValue = atof(str.c_str());
                break;
                default:
                ;
            }
            index++;
        };
        
    }

//Access methods
    string getAccountNumber()  { return accountNumber;       };
    string getTitle()          { return title;               };
    string getFirstname()      { return firstname;           };
    string getLastname()       { return lastname;            };
    string getCurrentsales()   { return currentSalesperson;  };
    string getCompany()        { return company;             };
    double getPurchaseValue()  { return purchaseValue;       };
    string getPrev_salesstaff(){ return prev_salestaff;      };
    double getCommission()     { return commission;          };

    string getAccountDetail()  { return accountNumber 
                                + " " + title 
                                + " " + firstname 
                                + " " + lastname 
                                + " " + company; };
    void displayEmployeeAccountslist() {
        
    }

};
int main()
{    
    vector<EmployeeAccount> employeeAccounts;
    
    ifstream employeeAccountFile("/Users/WEN/projects/ST2MidTermProject/NamesdataA1TxtFraud.txt");
    string lineContents;
    //read the file line by line until reach to EOF
    while (!employeeAccountFile.eof())
    {
        //read file and store each line to lineContents
        getline(employeeAccountFile, lineContents);
            // cout << lineContents << endl;
            
            if(lineContents.empty()) break;
            //create new EmployeeAccount object
            EmployeeAccount emp(lineContents);
            //add new object to the vector
            employeeAccounts.push_back(emp);
            // lineContents.clear();
            
    }
    employeeAccounts.pop_back();
    
    employeeAccountFile.close();

    for(int i = 0; i < employeeAccounts.size(); i++){
        cout << employeeAccounts[i].getAccountDetail() << endl;
        // cout << employeeAccounts[i].accountNumber << endl;
        // cout << employeeAccounts[i].title << endl;
        // cout << employeeAccounts[i].firstname << endl;
        // cout << employeeAccounts[i].lastname << endl;
        // cout << employeeAccounts[i].currentSalesperson << endl;
        // cout << employeeAccounts[i].company << endl;
        // cout << employeeAccounts[i].purchaseValue << endl;
        // cout << employeeAccounts[i].prev_salestaff << endl;
        // cout << employeeAccounts[i].commission << endl;
        cout << endl;
    }    
}