#include <iostream>
#include <iomanip>


using namespace std;

#define SIZE 5

double get_average(double a[], int size);

int main(void) {
    double x[SIZE], average;
    int i;
    cout << "Enter " << SIZE << " real numbers separated by blanks> " << endl;
    for (i = 0; i < SIZE; ++i)
    {
        cin >> x[i];
    }

    average = get_average(x, SIZE);//pass by reference

    cout << "The average of the elements in the array is: ";
    cout << fixed << setprecision(2) << average;
      
    return 0;
}

double get_average(double a[], int size) {
    int i;
    double sum = 0;

    for (i = 0; i < size; ++i)
        sum += a[i];

    return sum / size;
}
