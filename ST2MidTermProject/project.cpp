#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>

#define dir "/Users/WEN/projects/ST2MidTermProject/"

using namespace std;
//function declaration
void displayloadedFile();
void doFilenames();
void loadMenu();
void check();
void list();
void fraud();
void audit();
void duplicates();
void sort();
void exit();

string FNAME1 = "NamesdataA1Txttst.txt";
string FNAME2 = "NamesdataA1Txt.txt";
string FNAME3 = "NamesdataA2Txt.txt";
string FNAME4 = "NamesdataA1txtbaddata.txt";
string FNAME5 = "NamesdataA1Txtdupid.txt";
string FNAME6 = "NamesdataA1TxtFraud.txt";
string salesStaff[] = {"Brad", "Janet", "Dr Scott", "Rifraf", "Eddie"};
string ffname = "";

bool loadedFile = false;
template<class C, typename T>
bool contains(C& c, T t) { return find(begin(c), end(c), t) != end(c); };

string trim(const string& str, const string& whitespace = " \t\n\r")
{
	const auto strBegin = str.find_first_not_of(whitespace);
	if (strBegin == string::npos)
		return ""; // no content

	const auto strEnd = str.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return str.substr(strBegin, strRange);
}

class EmployeeAccount{        
private:
//member variable
    string accountNumber;
    string title;
    string firstname;
    string lastname;
    string currentSalesperson;
    string company;
    double purchaseValue = 0;
    string prev_salestaff;
    double commission = 0;
public:
//overload constructor
    EmployeeAccount(string employeeAccountInfo)
    {
        string str;
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

};
class EmployeeAccountList{
private:
    vector<EmployeeAccount> employeeAccounts;
public:
//overload constructor
    EmployeeAccountList(string filePath)
    {
        ifstream employeeAccountFile(filePath);
        string lineContents;
        
        //read the file line by line until reach to EOF
        while (!employeeAccountFile.eof())
        {   
            //read file and store each line to lineContents
            getline(employeeAccountFile,lineContents);
                lineContents = trim(lineContents);
                if(lineContents.empty()) break;
                //create new EmployeeAccount object
                EmployeeAccount emp(lineContents);
                //add new object to the vector
                employeeAccounts.push_back(emp);
                //lineContents.clear();
            //}
        }
        //employeeAccounts.pop_back();
        employeeAccountFile.close();
    };
//check
    void getNumberOfAccount(){
        double totalValue;
        double totalCommissions;
        int counter;
        
        counter = employeeAccounts.size();
        for(int i = 0; i < employeeAccounts.size(); i++){
            totalValue += employeeAccounts[i].getPurchaseValue();
        }
        for(int i = 0; i <employeeAccounts.size(); i++){
            totalCommissions += employeeAccounts[i].getCommission();
        }

        cout << endl;
        cout << "Checking report" << endl;
        cout << "---------------" << endl;
        cout << setw(17) << left << "Count of records "  << ": " <<  counter << endl;
        cout << setw(17) << left << "Total value "       << ": " <<  fixed << setprecision(2) << totalValue       << endl;
        cout << setw(17) << left << "Total commission "  << ": " <<  fixed << setprecision(2) << totalCommissions << endl;
    };
//Duplicates
    void getDuplicateAccount(){
         vector<EmployeeAccount> duplicates;
         int count = 0;
            for(int i = 0; i < employeeAccounts.size(); i++){
                for(int j = i+1; j < employeeAccounts.size(); j++){
                    if(employeeAccounts[i].getAccountNumber() == 
                            employeeAccounts[j].getAccountNumber())
                    {   
                        count++;
                        duplicates.push_back(employeeAccounts[i]);
                        duplicates.push_back(employeeAccounts[j]);
                    }
                }
            }
        cout << "Duplicate report"      << endl;
        cout << "---------------------" << endl;
        cout << ffname << endl;
        cout << "Count of records :"    << employeeAccounts.size() << endl;
        
        for(int i = 0; i < duplicates.size(); i++){
            if(duplicates[i-1].getAccountNumber() == duplicates[i].getAccountNumber()){
                cout << "Duplicate Account Found: Account number is:" << setw(10) << right 
                            << duplicates[i].getAccountNumber() << endl;
            }
        }
        for(int i = 0; i < duplicates.size(); i++){
            cout << "Details " << i+1 << ": " << duplicates[i].getAccountDetail() << endl;
        }
        cout << endl;
        cout << "Total count of duplicate ID's found:" << count << endl;
    };
//Fraud
    void getSalesFraudAccount(){
        cout << "Fraud report" << endl;
        vector<EmployeeAccount> fradulents;
        cout << "------------" << endl;
        cout << "Count of records : " << employeeAccounts.size() << endl;
        for(int i = 0; i < employeeAccounts.size(); i++){
            if(employeeAccounts[i].getCommission() > employeeAccounts[i].getPurchaseValue() * 0.11){
                fradulents.push_back(employeeAccounts[i]);
                cout << "Fradulent Account: "  << employeeAccounts[i].getAccountDetail() << endl;
                cout << "Account   Value is :" << setw(15) << right << employeeAccounts[i].getPurchaseValue()        << endl;
                cout << "Comission Value is :" << setw(15) << right << employeeAccounts[i].getCommission()           << endl;
                cout << "Reasonable Value is:" << setw(15) << right << employeeAccounts[i].getPurchaseValue() * 0.11 << endl;
            }
        }
        cout << endl;
        cout << "Total count of fradulent Transactions is:" << fradulents.size() << endl;
    };
//Audit
    void getrubishEntryAccount(){
        string str;
        vector<EmployeeAccount> errorAccount;
        for(int i = 0; i < employeeAccounts.size(); i++){
            if(!employeeAccounts[i].getPrev_salesstaff().empty()){
                stringstream staffStream(employeeAccounts[i].getPrev_salesstaff());
                while(getline(staffStream, str, ':')){
                    //for(int i = 0; i < sizeof(salesStaff); i++)
                    if(!contains(salesStaff, str))
                    {
                        errorAccount.push_back(employeeAccounts[i]);
                    }
                }
            }
        }
        cout << "Bad data account: " << endl;
        for(int i = 0; i < errorAccount.size(); i++) {
            cout << "Accout detail: " << errorAccount[i].getAccountDetail()   << endl;
            cout << "Detail       : " << errorAccount[i].getPrev_salesstaff() << endl;
            cout << endl;
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
                if(employeeAccounts[j].getAccountNumber() > employeeAccounts[j+1].getAccountNumber()){
                    //swap
                    swaps++;
                    EmployeeAccount temp  = employeeAccounts[j+1];
                    employeeAccounts[j+1] = employeeAccounts[j];
                    employeeAccounts[j]   = temp;
                }
            }
        }
        cout << "''''''''' sorting starting''''''''''''''"<< endl;
        cout << "Number of comparisons: " << comparisons  << endl;
        cout << "Number of Swaps: "       <<       swaps  << endl;
        cout << "''''''''' sorting ending''''''''''''''''"<< endl;
        cout << "sorting Testing"                         << endl;
        cout << setw(24) << "Sort Testing First[0] : "  << employeeAccounts.front().getAccountDetail() << endl;
        cout << setw(24) << "Sort Testing First[9] : "  << employeeAccounts[9].getAccountDetail()      << endl;
        if(employeeAccounts.size() > 499)
        cout << setw(24) << "Sort Testing First[499] : "<< employeeAccounts[499].getAccountDetail()    << endl;
        cout << setw(24) << "Sort Testing Last : "      << employeeAccounts.back().getAccountDetail()  << endl; 
        cout << endl;
    };
//list - display sorted list in short form
    void displaysortedList(){
        for(int i = 0; i < employeeAccounts.size(); i++){
            for(int j = 0; j < employeeAccounts.size() - i - 1; j++){
                 //comparison
                if(employeeAccounts[j].getAccountNumber() > employeeAccounts[j+1].getAccountNumber()){
                    //swap
                    EmployeeAccount temp = employeeAccounts[j+1];
                    employeeAccounts[j+1] = employeeAccounts[j];
                    employeeAccounts[j] = temp;
                }
            }
        }
        cout << "Sorted full list" << endl;
        cout << endl;
        for(int i = 0; i < employeeAccounts.size(); i++){
            cout <<"[" << i << "] = " << employeeAccounts[i].getAccountDetail() << endl;
        }
    }
};

void doFilenames()
{
	FNAME1 = string(dir) + FNAME1;
	FNAME2 = string(dir) + FNAME2;
	FNAME3 = string(dir) + FNAME3;
	FNAME4 = string(dir) + FNAME4;
	FNAME5 = string(dir) + FNAME5;
	FNAME6 = string(dir) + FNAME6;
}
void displayloadedFile()
{
    cout << "......................................." << endl;
    cout << endl;
    cout << "(File Loaded):" << endl;
    cout << ffname << endl;
    cout << endl;
    cout << "......................................." << endl;
    cout << endl;
}
void loadMenu()
{
    if(!loadedFile){cout <<".... no file loaded ..." << endl;} else { displayloadedFile();  }
    cout << endl;
    cout << "Assign1 2022 Menu\n";
    cout << "---------------------\n";
    cout << setw(9) << left << "E(xit) "       << setw(4) << left << "-" << "Exit\n";
    cout << setw(9) << left << "R(ead) "       << setw(4) << left << "-" << "Read File\n";
    cout << setw(9) << left << "C(Check) "     << setw(4) << left << "-" << "Check File details\n";
    cout << setw(9) << left << "L(ist) "       << setw(4) << left << "-" << "List in short form for checking\n";
    cout << setw(9) << left << "F(raud) "      << setw(4) << left << "-" << "Search for sales fraud\n";
    cout << setw(9) << left << "A(udit) "      << setw(4) << left << "-" << "Audit for rubish entries in previous sales people\n";
    cout << setw(9) << left << "D(uplicates) " << setw(4) << left << "-" << "Find and list duplicate id numbers\n";
    cout << setw(9) << left << "SO(rt) "       << setw(4) << left << "-" << "Sort on account number\n";
}
void read()
{
    if(!loadedFile) doFilenames();
    int option;
    cout << "Select file to process" << endl;
    cout << "1-" << FNAME1 << endl;
    cout << "2-" << FNAME2 << endl;
    cout << "3-" << FNAME3 << endl;
    cout << "4-" << FNAME4 << endl;
    cout << "5-" << FNAME5 << endl;
    cout << "6-" << FNAME6 << endl;
    
    while(!(cin  >> option) || (option < 1 || option > 7)){
        cout << "Invalid entry. Please re-enter: " << endl;
        cin.clear();
        cin.ignore(200,'\n');
    };
    
    if(option == 1) ffname = FNAME1;
    if(option == 2) ffname = FNAME2;
    if(option == 3) ffname = FNAME3;
    if(option == 4) ffname = FNAME4;
    if(option == 5) ffname = FNAME5;
    if(option == 6) ffname = FNAME6;
    cout << endl << "Processing " << ffname << endl;
    loadedFile = true;
    check();
    
    
}
void check()
{
    if (loadedFile == true){
        EmployeeAccountList list(ffname);
        list.getNumberOfAccount();
        loadMenu();
    }  
    else 
    { 
        cout <<".... no file loaded ..." << endl << endl;
        read(); 
    }
}
void list()
{
    if(loadedFile == true )
    { 
        EmployeeAccountList list(ffname); 
        list.displaysortedList(); 
        loadMenu();
    } 
    else 
    { 
        cout <<".... no file loaded ..." << endl;
        read(); 
    }
}
void fraud()
{
    if(loadedFile == true )
    {
        EmployeeAccountList list(ffname);
        list.getSalesFraudAccount();
        loadMenu();
    }
    else
    { 
        cout <<".... no file loaded ..." << endl;
        read(); 
    }
}
void audit()
{
    if(loadedFile == true )
    {
        EmployeeAccountList list(ffname);
        list.getrubishEntryAccount();
        loadMenu();
    }
    else 
    { 
        cout <<".... no file loaded ..." << endl;
        read(); 
    }
}
void duplicates()
{
    if(loadedFile == true )
    {
        EmployeeAccountList list(ffname);
        list.getDuplicateAccount();
        loadMenu();
    }
    else 
    { 
        cout <<".... no file loaded ..." << endl;
        read(); 
    }

}
void sort()
{
     if(loadedFile == true )
    { 
        EmployeeAccountList list(ffname);
        list.getSortedAccountList();
        loadMenu();
    }
    else 
    { 
        cout <<".... no file loaded ..." << endl;
        read(); 
    }

}
void exit()
{
    exit(0);
}
int main() 
{
    cout << "Assign1 2022!" << " - " << "START RUN" << " - " << endl;
    //cout << endl;
    loadMenu();
    char choice;
    
    while(toupper(choice) != 'E'){
        cin >> choice;
        loadMenu();
        cout << "Option selected: " << choice << endl;
        cout << endl;
        
        switch(toupper(choice))
        {
            case 'E':
                    exit();
                    break;
                case 'R':
                    read();
                    break;
                case 'C':
                    check();
                    break;
                case 'L':
                    list();
                    break;
                case 'F':
                    fraud();
                    break;
                case'A':
                    audit();
                    break;
                case 'D':
                    duplicates();
                    break;
                case 'S':
                    sort();
                    break;
                default:
                    cout << "Invalid! Please re-enter: \n";
                    break;
        }
    }
    
}