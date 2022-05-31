#include <iostream>
#include <string>
using namespace std;

int main(){
    int mat[3][5], row, col ;
    cout << "Enter value: ";
    for (row = 0; row < 3; row++)
        for (col = 0; col < 5; col++)
            cin >> mat[row][col];
    for (int i = 0; i < 3; i++)
        for(int j = 0; j < 5; j++)
            cout << mat[i][j]<<' ';
}