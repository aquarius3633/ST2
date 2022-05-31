#include <iostream>
using namespace std;

void printArray(int arg[], int size){
    for(int i = 0; i < size; i++){
        cout << arg[i] << ' ';
    }
    cout << '\n';


}

int main() {

    int Array1[5] = {1,3,5,7,9};
    int Array2[6] = {2,4,6,8,10,12};

    printArray(Array1, 5);
    printArray(Array2,6);


}