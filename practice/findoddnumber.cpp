#include <iostream>
#include <vector>

using namespace std;

int main() {
    int l, k;
    vector<int> odd_list;
    cout <<"Please enter two numbers: " << endl;
    cin >> l >> k;
    if (l % 2 == 0) {
        l++;
        while(l <= k){
            odd_list.push_back(l);
            l += 2;
        }
    } else {
        while(l <= k){
            odd_list.push_back(l);
            l += 2;
        }
    }
    cout << "The odd numbers between these two numbers are: " << endl;
    for(int i = 0; i < odd_list.size(); i++){
        cout << odd_list[i] << endl;
    }
}