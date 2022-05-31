// Parseme.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <map>
using namespace std;
string testlines[7] = {"show intro", "show bye", "show 'hi there'", "show 'hi I am happy ': bye",
                       "show 'Hi, ':intro:' Happy Happy'", "show intro:' Jamie are you happy ' : ' what no' :bye",
                       "show 'Hi, ':intro :' wake up':' Chen ': bye:' oh sorry' "};
string inputLine = "";
string inputLineErr3 = "show";
string inputLineErr2 = "show 'X':'Y'+'Z'";
string inputLineErr1 = "show 'Hi':jim";
string intro = "hello"; // contains the string “hello”
string bye = "kthxbye"; //  contains the string “kthxbye”
bool debug1 = true;
bool debug2 = true;
std::string trim(const std::string &str,
                 const std::string &whitespace = " \t")
{
    // from h ttps://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string//
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content
    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;
    return str.substr(strBegin, strRange);
}
string thingToShow = "";
string removeQuotes(string val)
{
    string retv = "";
    int ccount = 0;
    for (char c : val)
    {
        if (c != '\'')
            retv = retv + c;
        else
            ccount++;
    }
    if (ccount != 2)
        cout << "ERROR missing quote "
             << "\n";
    return retv;
    //return retv;
}
void processToken(string t)
{
    if (debug1)
        cout << "processing token " << t << endl;
    if (trim(t) == "")
        return; // its nothing ignore it just whitespace
    t = trim(t);
    // a token can be ' string ' or a variable
    if (t[0] == '\'')
    {
        // its a string
        string val = removeQuotes(t);
        thingToShow = thingToShow + val;
    }
    else
    {
        // its a variable
        if (t == "bye")
        {
            thingToShow = thingToShow + bye;
        }
        else if (t == "intro")
        {
            thingToShow = thingToShow + intro;
        }
        else
        {
            cout << "ERROR variable is wrong " << t << "\n";
            return;
        }
    }
}
void processRightLoop(string str) // remember str is a rightBit
{
    if (debug1)
        cout << "processing right side " << str << endl;
    //thingToShow = "";
    // now advance the character pointer called cp
    int cp = 0;
    string tok = "";
    while (cp < str.size())
    {
        char c = str[cp];
        if (c == ':')
        {
            processToken(tok);
            tok = "";
        }
        else
        {
            // build token
            tok = tok + c;
        }
        cp = cp + 1;
    }
    if (trim(tok) != "")
        processToken(tok);
}
string evaluateToken(string t)
{
    if (debug2)
        cout << "evaluating token " << t << endl;
    if (trim(t) == "")
        return ""; // its nothing ignore it just whitespace
    t = trim(t);
    // a token can be ' string ' or a variable
    if (t[0] == '\'')
    {
        // its a string
        string val = removeQuotes(t);
        return val;
    }
    else
    {
        // its a variable
        if (t == "bye")
        {
            return bye;
        }
        else if (t == "intro")
        {
            return intro;
        }
        else
        {
            cout << "ERROR variable is wrong " << t << "\n";
            return "";
        }
    }
}
string processRightRecursive(string bitToProcess)
{
    string retv = "";
    if (debug2)
        cout << "now Recursing " << bitToProcess << endl;
    // search for :
    int cp = -1; // will point to last :
    for (int i = 0; i < bitToProcess.size(); i++)
    {
        char c = bitToProcess[i];
        if (c == ':')
        {
            cp = i;
        }
    }
    if (cp == -1)
    {
        // no :
        return evaluateToken(bitToProcess);
    }
    else
    {
        string leftBit = trim(bitToProcess.substr(0, cp));
        string rightBit = trim(bitToProcess.substr(cp + 1, bitToProcess.size() - cp));
        retv = processRightRecursive(leftBit) + processRightRecursive(rightBit);
        return retv;
    }
}
void parse(string str)
{
    string leftBit = "";
    string rightBit = "";
    // advance a counter to white space to split out the show command in leftBit
    // then put the rest in
    cout << "now parsing " << str << endl;
    if (str.size() < 6)
    {
        cout << "ERROR Line is to short "
             << "\n";
        return;
    }
    int count = 0;
    int place = -1;
    while (count < str.size())
    {
        if (iswspace(str[count]))
        {
            place = count;
            break;
        }
        count++;
    }
    cout << "count=" << count << endl;
    leftBit = str.substr(0, count);
    rightBit = str.substr(count, str.size() - count);
    rightBit = trim(rightBit);
    if (leftBit != "show")
    {
        cout << "ERROR missing -show- keyword "
             << "\n";
        return;
    }
    cout << "leftBit =" << leftBit << endl;
    cout << "rightBit =" << rightBit << endl;
    processRightLoop(rightBit);
    cout << "\n ----------------- \n";
    cout << thingToShow << "\n";
    cout << "\n ----------------- \n";
    thingToShow = processRightRecursive(rightBit);
    cout << "\n ---- Recursive ------------- \n";
    cout << thingToShow << "\n";
    cout << "\n ----------------- \n";
}
int main()
{
    std::cout << "START Parse me\n";
    inputLine = testlines[3]; // set up test data
    parse(inputLine);
    std::cout << "END Parse me\n";
}