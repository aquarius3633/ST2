
//Complete the above program so that it displays a table showing each array element
//value and what percentage each value is of the total of ten values as shown below.
//It also displays the maximum and minimum values of the array elements. 


#include <iostream>
#include <iomanip> 

using namespace std;
int smallest = INT_MAX;
int largest = INT_MIN;
int counter = 0;

double sum(int arg[], int length ) {
    int total = 0;
    int i;
    for (i = 0; i < length; i++){
        total += arg[i];
        counter++;
    }
    return total;
}
int minValue(int arg[], int length){
    
    for(int i = 0; i < length; i++){
        if(arg[i] < smallest)
            smallest = arg[i];
    }
    return smallest;
}

int maxValue(int arg[], int length){
    
    for(int i = 0; i < length; i++){
        if(arg[i] > largest)
            largest = arg[i];
    }
    return largest;
}
int main()
{
  
	int numbs[10] = {8, 12, 18, 24, 25, 30, 28, 22, 23, 10};

	// Add your code here
    
    cout << "N" << "\t\t" << "% of total" << endl;
    for(int i = 0; i < 10; i++){
        cout << numbs[i] << "\t\t" << fixed << setprecision(2) << numbs[i]/sum(numbs, 10) * 100 << endl;
        counter++;
    }
    cout <<"The maximum value = " << maxValue(numbs, 10) << endl;
    cout <<"The minimum value = " << minValue(numbs, 10) << endl;
    cout << counter << endl;

}
