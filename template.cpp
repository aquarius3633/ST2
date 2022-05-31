#include <iostream>
#include <string>

using namespace std;

template<typename T>
void Swap(T&a, T&b){
    T temp = a;
    a = b;
    b = temp;
}
template<typename T>
T getMax(T *a, T *b){
    if(*a < *b)
        return *b;
    else
        return *a;
}
template<typename T, int N>
class Array{
private:
    T my_array[N];
public:
    int get_arraySize() const { return N;};
};
int main(){

int a = 5, b = 10;
int retvs;
Swap(a, b);
retvs = getMax(&a,&b);

cout << retvs << endl;
Array<int, 5> array;
cout << array.get_arraySize() << endl;

}