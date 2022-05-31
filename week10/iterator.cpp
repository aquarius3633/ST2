#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v{1,4,5,6,8,7};

    auto it = find(v.begin(), v.end(), 7);
    cout << "First element: " << *(v.begin()) << endl;//return the first element
    cout << "Next element: " << *(++v.begin()) << endl;//return the next element
    
    cout << "The last element " << *(v.end()) << endl; // why the last element show 0
    cout << "The second last element: " << *(--v.end()) << endl;// why the second last element 7
    cout << v.size() << endl;
    if(it != v.end()){
        cout << "Index " << it - v.begin() << " found matching element " << *it << endl;
    }
    else{
        cout << "Elements no found" << endl;
    }
    return 0;
}