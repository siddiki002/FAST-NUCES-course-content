#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int *a, int low, int high){
	int pivot = a[high];
	int pivot_index = low;
	
	for (int j = low; j < high; j++){
		// Just move smaller than pivot numbers to left, 
		// larger than pivot will automatically be left 
		// on the right side of the pivot.
		if (a[j] < pivot){
			swap(&a[j], &a[pivot_index]);
			pivot_index++;
		}
	}
	
	swap(&a[pivot_index], &a[high]);
	return pivot_index;
}

void quicksort(int *a, int low, int high){
	if (low < high){
		int pivot_index = partition(a, low, high);
		
		quicksort(a, low, pivot_index - 1);
		quicksort(a, pivot_index + 1, high);
	}
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int main(){
	int a[6] = {3,9,8,2,5,6};
	int n = sizeof(a)/sizeof(a[0]);
	quicksort(a, 0, n-1);
	printArray(a, n);
	return 0;
}
