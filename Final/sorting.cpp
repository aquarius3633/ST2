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
	for (i = 1; i < n-1; i++)
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

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, end);
}


// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

int main()
{
	//sort3(ua, SORTNUM);
	//sort1(ua2,SORTNUM2);

	//Qucik sort
	int arr[] = { 9, 3, 4, 2, 1, 8 };
	int n = 6;

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	//Merge Sort
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);

	return 0;

	/*sort2(ua, SORTNUM);*/


}


