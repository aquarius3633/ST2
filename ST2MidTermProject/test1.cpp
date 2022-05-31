#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

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
    string salesperson;
    double purchaseValue;
    string prev_salestaff;
    double commission;
public:
//overload constructor
    EmployeeAccount(string employeeAccountInfo)
    {
        string str;
        int index = 0;
        //vector<string> v;
        vector<double> ValueOfPurchase;
        vector<double> ValueOfCommission;
        stringstream employeeAccountStream(employeeAccountInfo);
        while(getline(employeeAccountStream, str, ','))
        { 
            //v.push_back(str); 
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
                break;
                case 7:
                prev_salestaff = str;
                break;
                case 8:
                commission = stod(str);
                break;
                default:
                ;
            }
            index++;
        };
        //ugly hard coding here....
        //accountNumber      = v[0];
        //title              = v[1];
        //firstname          = v[2];
        //lastname           = v[3];
        //company            = v[4];
        //currentSalesperson = v[5];
        //purchaseValue      = stod(v[6]);
        //prev_salestaff     = v[7];
        //commission         = stod(v[8]);      
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

/*class EmployeeAccountList{
public:
    vector<EmployeeAccount> employeeAccounts;
    double total;
//Create EmployeeAccount list 
    EmployeeAccountList(string filePath)
    {
        ifstream employeeAccountFile(filePath);

        string lineContents;
        while (!employeeAccountFile.eof())//read the file line by line until reach to EOF
        {
            //read file and store each line to lineContents
            getline(employeeAccountFile, lineContents);
            //create new EmployeeAccount object
            EmployeeAccount emp(lineContents);
            //add new object to the vector
            employeeAccounts.push_back(emp);
        }
        employeeAccounts.pop_back();
        employeeAccountFile.close();
    };

//read and count
    int getNumberOfAccount(){
        return employeeAccounts.size();
    };
//check
    double getTotalValueOfPurchase(){
        for(int i = 0; i < employeeAccounts.size(); i++){
            total += employeeAccounts[i].getPurchaseValue();
            return total;
        }
    };
    double getTotalValueOfCommission();//check
    vector<EmployeeAccount> getDuplicateAccount();//Duplicates
    vector<EmployeeAccount> getSalesFraudAccount();//Fraud
    vector<EmployeeAccount> getrubishEntryAccount();//Audit
    vector<EmployeeAccount> getSortedAccountList();//Sort

};*/


int main(){
    int counter;
    double totalValue;
    double totalCommissions;
    
    //EmployeeAccountList list("/Users/WEN/projects/ST2MidTermProject/NamesdataA1Txttst.txt");
    //counter = list.getNumberOfAccount();
    ifstream employeeAccountFile("/Users/WEN/projects/ST2MidTermProject/NamesdataA1TxtFraud.txt");
    string lineContents;
    vector<EmployeeAccount> employeeAccounts;
    while(!employeeAccountFile.eof()){
        getline(employeeAccountFile,lineContents);
        EmployeeAccount emp(lineContents);
        employeeAccounts.push_back(emp);
    }
    employeeAccounts.pop_back();
    employeeAccountFile.close();
    
    

    //cout << setw(17) << left << "Count of records "  << ": " <<  counter << endl;
    //cout << setw(17) << left << "Total Value of Purchase "  << ": " <<  totalValue << endl;
    //cout << setw(17) << left << "Total Value of Commission "  << ": " <<  totalCommissions << endl;





}
