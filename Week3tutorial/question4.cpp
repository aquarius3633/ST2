#include <iostream>


int main(){
    int rows = 9;
    int colls = 3;
    int r,c;
    for (c = 0; c < colls; c++){
        for(r = 0; r < rows; r++){
            printf("%d", r);
        }
        printf("\n");
    }
    return 0;
}