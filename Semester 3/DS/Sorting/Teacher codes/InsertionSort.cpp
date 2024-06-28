// C++ program for insertion sort
#include <iostream>
using namespace std;

/* Function to sort an array using insertion sort*/
void insertionSort2(int arr[], int n){
	int i, j;
	for (i = 1; i < n; i++){
		int key = arr[i]; //create hole at i
		j=i-1;
		while (j>=0 && arr[j]>key){
			arr[j+1] = arr[j]; //create hole at j
			j--;
		}
		arr[j+1] = key;
	}
}

void insertionSort(int arr[], int n){
	int i, j;
	for (i = 1; i < n; i++){
		int key = arr[i];
		for (j = i; j > 0 && arr[j-1] > key; j--){
			arr[j] = arr[j-1];
		}
		arr[j] = key;
	}
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

/* Driver code */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}

