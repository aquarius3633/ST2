#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> vec{
                                {2,4},
                                {4,6},
                                {3,5}
                            };
    // for(int i = 0; i < vec.size(); i++){
    //     for(int j = 0; j < vec[i].size(); j++){
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(vector v : vec){
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
