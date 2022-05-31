#include <iostream>
#include <iomanip> 
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void checkDepulicates()
{
 ifstream myFile;
 myFile.open("NamesdataA1TxtDupId.txt");

 // Vectors to store ID, name and company
 vector<int> id;
 vector<string> name, work;

 string line;

 // Get input while EOF
 while (getline(myFile, line, '\n'))
 {
  stringstream row(line);
  string split;
  string fullName = "";

  int column = 0;

  // Split input row by comma and read
  while (getline(row, split, ','))
  {
   // Get First Column (ID)
   if (column == 0)
   {
    // Push into vector
    int getId = stoi(split);
    id.push_back(getId);
   }
   // Get Second Third and Fourth Column (Name)
   else if (column == 1) { fullName = split; }
   else if (column == 2) { fullName += (" " + split + " "); }
   else if (column == 3)
   {
    // Push to vector
    fullName += split;
    name.push_back(fullName);
   }
   // Get Fifth Column (Company)
   else if (column == 4) { work.push_back(split); }
   column++;
  }
 }
 // Print total size of records
 cout << "\nCount of record: " << id.size() << "\n\n";

 // Variable to count duplicates
 int countDuplicates = 0;
 for (int i = 0; i < id.size() - 1; i++)
 {
  for (int j = i + 1; j < id.size(); j++)
  {
   // Nested loop to find duplicates
   if (id[i] == id[j])
   {
    cout << "Duplicated account found, account number is " << id[i] << endl;
    cout << "Detail 1: " << id[i] << " " << name[i] << " " << work[i] << endl;
    cout << "Detail 2: " << id[j] << " " << name[j] << " " << work[j] << endl << endl;
    countDuplicates++;
   }
  }
 }

 // Print total duplicates
 cout << "Total count of duplicate ID's: " << countDuplicates << endl;
}

int main()
{
 checkDepulicates();
}