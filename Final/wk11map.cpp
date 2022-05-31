#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

int main1a()
{
    std::cout << "Hello World!\n";
    char c = ' ';
    while (c != 'E')
    {
        c = _getch();
        cout << "Character is=" << c << endl;
    }
    return 0;
}
void main1()
{
    map<char, int> val;
    val['a'] = 7;
    val['b'] = 70;
    val['c'] = 707;
    val['z'] = 77;
    std::cout << "val[a] is " << val['a'] << "\n";
    std::cout << "val[b] is " << val['b'] << "\n";
    std::cout << "val[c] is " << val['c'] << "\n";
    std::cout << "val[z] is " << val['z'] << "\n";
    // std::cout << "val[q] is " << val['q'] << "\n";
    // std::cout << "\n";
    //
    //// get its size
    // std::cout << "val.size() is:" << val.size() << "\n";
    //
    // std::cout << "\n";
    //// for (int j: val) { does not work }
    ////So how to iterate
    // map<char, int>::iterator iter;  // construct an iterator
    // for (iter = val.begin(); iter != val.end(); ++iter)
    //{
    //     cout << iter->first << " => " << iter->second << '\n';
    // }
}
void main2()
{
    map<string, int> vals = {{"Rob", 60}, {"Jane", 12}, {"Zix", 22}, {"Chen", 21}};
    // Iterate
    map<string, int>::iterator iter;                      // construct an iterator
    for (iter = vals.begin(); iter != vals.end(); ++iter) // these should be
        sorted
        {
            cout << iter->first << " => " << iter->second << '\n';
        }
    std::cout << "\n";
    // add one
    vals["Frodo"] = 102;
    // also add one
    vals.insert({"Dizzy", 55}); // you are kidding me I need a standard allocator !Wtf
    // also add one
    string boffin = "Boffin";
    int gaga = 21;
    vals.insert({boffin, gaga});                          // ok even more impressed with allocators now
    for (iter = vals.begin(); iter != vals.end(); ++iter) // these should be
        sorted
        {
            cout << iter->first << " => " << iter->second << '\n';
        }
}
void main3()
{
    map<string, int> vavoom = {{"Rob", 60}, {"Jane", 12}, {"Zix", 22}, {"Chen", 21}};
    // update one of them note no new record constructed
    vavoom["Rob"] = 61;                                       // he had a birthday
    map<string, int>::iterator iter;                          // construct an iterator
    for (iter = vavoom.begin(); iter != vavoom.end(); ++iter) // these should be sorted
        {
            cout << iter->first << " => " << iter->second << '\n';
        }
    std::cout << "\n";
    // lets go backwards  - this is how its supposed to be done
    std::map<string, int>::reverse_iterator iterR;
    for (iterR = vavoom.rbegin(); iterR != vavoom.rend(); iterR++) // these should be sorted
        {
            cout << iterR->first << " => " << iterR->second << '\n';
        }
    std::cout << "\n";
    // lets go backwards  
    //- this is not a good way  
    // its a forward iterator going backwards for (iter = --(vavoom.end()); iter != vavoom.begin(); --iter) 
    // this skips the first one
//     {
//         cout << iter->first << " => " << iter->second << '\n';
//     }
//     iter = vavoom.begin();
//     cout << iter->first << " => " << iter->second << '\n'; // do the first ome
// }
void main4()
{
    map<string, string> cat = {{"Rob", "A60"}, {"Jane", "B12"}, {"Zix", "JJ22"}, {"Chen", ""}, {"Elvis", "B52"}, {"Alice", "B99"}, {"Masood", "A2"}};
    // insert example
    cat.insert(make_pair("Kimbo", "one"));
    std::cout << "\n";
    for (auto iter = cat.begin(); iter != cat.end(); ++iter)
    {
        cout << iter->first << " => " << iter->second << '\n';
    }
    std::cout << "\n";
    // find example
    // string s = cat["Helfa"];
    if (cat.find("Rob") == cat.end())
    {
        std::cout << "Rob not found "
                  << "\n";
    }
    else
    {
        std::cout << "found Rob"
                  << "\n";
    }
    if (cat.find("Helfa") == cat.end())
    {
        std::cout << "Helfa not found "
                  << "\n";
    }
    else
    {
        std::cout << "Helfa found"
                  << "\n";
    }
}
void main5()
{
    map<int, string> map1 = {};
    map1[0] = "ST2";
    map1[2] = "ST1";
    string myValue = map1[0]; // --> ST2
    cout << map1[2] << endl;  // --> ST1
    map1.insert(pair<int, string>(4, "ST(n)"));
    map1.insert({6, "Alice Cooper"}); // standard allocator yay
    // erase
    map1.erase(2);
    map<int, string>::iterator miter;                        // construct an iterator
    for (miter = map1.begin(); miter != map1.end(); ++miter) // these should be
        sorted
        {
            cout << miter->first << " => " << miter->second << '\n';
        }
}
int main()
{
    std::cout << "Map example !\n";
    // main1();
    // main2();
    // main3();
    // main4();
    main5();
}
