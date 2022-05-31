#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
string ffname = "";
class EmployeeAccount{        
private:
//member variable
    string accountNumber;
    string title;
    string firstname;
    string lastname;
    string currentSalesperson;
    string company;
    string salesperson;
    double purchaseValue;
    string prev_salestaff;
    double commission;
public:
//default constructor
    EmployeeAccount(string accountNumber, string title, string firstname, string lastname,
                    string currentSalesperson, string company, string salesperson,
                    double purchaseValue, string prev_salesstaff, double commission)
                    {
                        this->accountNumber      = accountNumber;
                        this->title              = title;
                        this->firstname          = firstname;
                        this->lastname           = lastname;
                        this->currentSalesperson = currentSalesperson;
                        this->company            = company;
                        this->salesperson        = purchaseValue;
                        this->prev_salestaff     = prev_salesstaff;
                        this->commission         = commission;
                    }
//overload constructor
    EmployeeAccount(string employeeAccountInfo)
    {
        string str;
        int index = 0;
        vector<string> v;
        vector<double> ValueOfPurchase;
        vector<double> ValueOfCommission;
        stringstream employeeAccountStream(employeeAccountInfo);
        while(getline(employeeAccountStream, str, ','))
        { 
           //Warning!!! hard coding here.... 
            switch(index){
                case 0: accountNumber = str;
                    break;
                case 1: title = str;
                    break;
                case 2: firstname = str;
                    break;
                case 3: lastname = str;
                    break;
                case 4: company = str;
                    break;
                case 5: currentSalesperson = str;
                    break;
                case 6: purchaseValue = stod(str);
                    break;
                case 7: prev_salestaff = str;
                    break;
                case 8: commission = stod(str);
                    break;
                default: ;
            }
            index++;
        };    
    }
//Access methods
    string getAccountNumber()  { return accountNumber;      };
    string getTitle()          { return title;              };
    string getFirstname()      { return firstname;          };
    string getLastname()       { return lastname;           };
    string getCurrentsales()   { return currentSalesperson; };
    string getCompany()        { return company;            };
    double getPurchaseValue()  { return purchaseValue;      };
    string getPrev_salesstaff(){ return prev_salestaff;     };
    double getCommission()     { return commission;         };

    string getAccountDetail()  { return accountNumber + " " 
                                        + title + " " 
                                        + firstname + " " 
                                        + lastname + " " 
                                        + company; };


//Destructor
    ~EmployeeAccount(){};
};

class EmployeeAccountList{
public:
    vector<EmployeeAccount> employeeAccounts;
//Create EmployeeAccount list 
    EmployeeAccountList(string filePath)
    {
        ifstream employeeAccountFile(filePath);

        string lineContents;
        //read the file line by line until reach to EOF
        while (!employeeAccountFile.eof())
        {
            //read file and store each line to lineContents
            getline(employeeAccountFile, lineContents);
            //create new EmployeeAccount object
            EmployeeAccount emp(lineContents);
            //add new object to the vector
            employeeAccounts.push_back(emp);
        }
        employeeAccountFile.close();
    };

//count
    int getNumberOfAccount(){
        return employeeAccounts.size();
    };
//check
    double checkTotalPurchaseValue(){
        double totalValue;
        for(int i = 0; i < employeeAccounts.size(); i++)
        {
            EmployeeAccount e = employeeAccounts.at(i);
            totalValue += e.getPurchaseValue();
        }
        return totalValue;
    };
    double checkTotalCommissionValue(){
        double totalCommissions;
        for(int i = 0; i < employeeAccounts.size(); i++)
        {
            EmployeeAccount e = employeeAccounts.at(i);
            totalCommissions += e.getCommission();
        }
        return totalCommissions;
    };
//Duplicates
    vector<EmployeeAccount> getDuplicateAccount(){
        vector<EmployeeAccount> duplicates;
        for(int i = 0; i < employeeAccounts.size(); i++){
            for(int j = i+1; j < employeeAccounts.size(); j++){
                if(employeeAccounts[i].getAccountNumber() == 
                        employeeAccounts[j].getAccountNumber())
                {
                    duplicates.push_back(employeeAccounts[i]);
                    duplicates.push_back(employeeAccounts[j]);
                }
            }
        }
        return duplicates;
    };

//Fraud
    vector<EmployeeAccount> getSalesFraudAccount(){
        vector<EmployeeAccount> fraudAccounts;
        for(int i = 0; i < employeeAccounts.size(); i++){
            if(employeeAccounts[i].getCommission() > 
                    employeeAccounts[i].getPurchaseValue() * 0.11)
                fraudAccounts.push_back(employeeAccounts[i]);
        }
        return fraudAccounts;
    };

//Audit
    void getrubishEntryAccount(){
        string str;
        vector<EmployeeAccount> errorAccount;
        string salesStaff[] = {"Brad", "Janet", "Dr Scott", "Rifraf", "Eddie"};
        for(int i = 0; i < employeeAccounts.size(); i++){
            if(!employeeAccounts[i].getPrev_salesstaff().empty()){
                stringstream staffStream(employeeAccounts[i].getPrev_salesstaff());
                while(getline(staffStream, str, ':'))
                {
                    for(int i = 0; i < sizeof(salesStaff); i++){
                        if(salesStaff[i] != str)
                            errorAccount.push_back(employeeAccounts[i].getPrev_salesstaff());
                    }
                }
            }
        }
        cout << "Bad data account: " << endl;
        for(int i = 0; i < errorAccount.size(); i++) {
            cout << errorAccount[i].getAccountDetail() << endl;
        }  
    };

//Sort
    void getSortedAccountList(){
        int swaps = 0;
        int comparisons = 0;
        for(int i = 0; i < employeeAccounts.size(); i++){
            for(int j = 0; j < employeeAccounts.size() - i - 1; j++){
                 //comparison
                comparisons++;
                if(employeeAccounts[j].getAccountNumber() > 
                    employeeAccounts[j+1].getAccountNumber())
                {
                    //swap
                    swaps++;
                    EmployeeAccount temp = employeeAccounts[j+1];
                    employeeAccounts[j+1] = employeeAccounts[j];
                    employeeAccounts[j] = temp;
                }
            }
    };

};
//show sorted list in short form
    void displaysortedList(){
            for(int i = 0; i < employeeAccounts.size(); i++){
                for(int j = 0; j < employeeAccounts.size() - i - 1; j++){
                    //comparison
                    if(employeeAccounts[j].getAccountNumber() > 
                        employeeAccounts[j+1].getAccountNumber())
                    {
                        //swap
                        EmployeeAccount temp = employeeAccounts[j+1];
                        employeeAccounts[j+1] = employeeAccounts[j];
                        employeeAccounts[j] = temp;
                    }
                }
            }
            cout << "Sorted full list" << endl;
            cout << endl;
            for(int i = 0; i < employeeAccounts.size(); i++)
            {
                cout <<"[" << i << "] = " << employeeAccounts[i].getAccountDetail() << endl;
            }
        }
};

int main()
{   
    int counter;
    double totalValue;
    double totalCommissions;

    EmployeeAccountList list("/Users/WEN/projects/ST2MidTermProject/NamesdataA1txtbaddata.txt");
    //calculate total number of accounts in that file
    //counter = list.getNumberOfAccount();

    //totalValue = list.checkTotalPurchaseValue();
    //totalCommissions = list.checkTotalCommissionValue();

    //cout << setw(17) << left << "Count of records "  << ": " <<  counter << endl;
    //cout << setw(17) << left << "Total value "       << ": " <<  fixed << setprecision(2) << totalValue << endl;
    //cout << setw(17) << left << "Total commission "  << ": " <<  fixed << setprecision(2) << totalCommissions << endl;

    list.getrubishEntryAccount();
}