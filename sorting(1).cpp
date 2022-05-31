#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm> 

using namespace std;

# define SORTNUM 10

int ua[SORTNUM] = { 1,3,5,1,2,7,2,4,9,0 }; // unsorted 

int oa[SORTNUM] = { 0,1,1,2,2,3,4,5,7,9 };  // sorted 

# define SORTNUM2 20

int ua2[SORTNUM2] = { 1,3,5,1,2,7,2,4,9,0,10,3,5,1,20,7,21,4,9,0 };

int comparisons = 0;
int swaps = 0;

void zeroCounters()
{
	comparisons = 0;
	swaps = 0;
}

void report()
{
	cout << "comparisons: " << comparisons << endl;
	cout << "swaps      : " << swaps << endl;
}

void showArray(int a[], int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "a[" << i << "]=" << a[i] << " ";
		if (i % 10 == 9) cout << endl;
	}
	cout << endl;
}

void sort1(int a[], int num) // selection sort
{
	zeroCounters();
	cout << "unsorted: ";
	showArray(a, num);
	// -------------- do sort now -----------------------------

	for (int i = 0; i < num; i++) // loop every item
	{
		int low = i;
		for (int k = i + 1; k < num; k++) // Find lowest 
		{
			comparisons++;
			if (a[k] < a[low])
			{
				//new lowest
				low = k;
			}
		}
		if (i != low)
		{
			// do swap
			swaps++;
			int temp = a[i];
			a[i] = a[low];
			a[low] = temp;
		}
	}
	report();
	cout << "sorted: ";
	showArray(a, num);

}

void sort3(int a[], int num) // bubble sort
{
	zeroCounters();
	cout << "unsorted: ";
	showArray(a, num);
	// -------------- do sort now -----------------------------

	for (int i = 0; i < num; i++) // loop every item
	{
		bool f = true;
		for (int k = 0; k < num - 1; k++)
		{
			comparisons++;
			if (a[k] > a[k + 1])
			{
				// swap
				swaps++;
				int temp = a[k + 1]; //preserve K + 1
				a[k + 1] = a[k]; // update K+1
				a[k] = temp; // update k (swap)
				f = false;
			}
		}
		if (f) break;
	}

	// ---------------- end sort ----------
	report();
	cout << "sorted: ";
	showArray(a, num);

}



void sort2(int a[], int num) // insersion sort
{
	zeroCounters();
	cout << "unsorted: ";
	showArray(a, num);
	// -------------- do sort now -----------------------------

	int i, j, n = num;
	int target;
	// place array[i] into the sublist array[0] ...                   
	// so it is in the correct position                              
	for (i = 1; i < n; i++)
	{

		// index j scans down list from array[i]       array[j-1] = 20 -> target > array[j-2]
		// correct position to locate target           array[j] = 50
		j = i;
		// assigns it to array[j]
		target = a[j];
		// locate insertion point by scanning downward as long as target < array[j-1] 
		// and we have not encountered the beginning of the list
		while (j > 0 && target < a[j - 1])
		{
			// shift elements up to make room for insertion
			a[j] = a[j - 1];
			j--;
			swaps++;
			comparisons++;
		}
		// the location is found; insert target
		a[j] = target;
		swaps++;
	}
	// -------------- end sort --------------------------------
	report();
	cout << "sorted: ";
	showArray(a, num);
}

int main()
{
	//sort3(ua, SORTNUM);
	sort1(ua2,SORTNUM2);

	/*sort2(ua, SORTNUM);*/


}


