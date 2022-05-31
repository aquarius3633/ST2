#include <iostream>
#include <string>

using namespace std;
std::string trim(const std::string &str,
                 const std::string &whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content
    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;
    return str.substr(strBegin, strRange);
}
int main(){
    string txt = "The slow yellow, fox failed to jump the lazy dog";
    string leftBit = "";
    string rightBit = "";
    
    if (txt.size() <= 0)
    {
        cout << "ERROR Line "
             << "\n";
        
    }
    int count = 0;
    int place = -1;
    while (count < txt.size())
    {
        if (txt[count] == ',')
        {
            place = count;
            break;
        }
        count++;
    }
    //cout << "count=" << count << endl;
    leftBit = txt.substr(0, count);
    rightBit = txt.substr(count + 1, txt.size() - count);
    rightBit = trim(rightBit);
    //cout << "Debugger line" << endl << endl;
    cout << leftBit << endl;
    cout << rightBit << endl;
}