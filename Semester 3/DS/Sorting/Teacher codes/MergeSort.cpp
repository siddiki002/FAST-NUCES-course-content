#include <iostream>
using namespace std;

void merge(int *array, int left, int mid, int right)
{
    int subArrayOneSize = mid - left + 1;
    int subArrayTwoSize = right - mid;
  
    // Create temp arrays
    int *leftArray = new int[subArrayOneSize],
         *rightArray = new int[subArrayTwoSize];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    // We can rightly assume these arrays are sorted.
    for (int i = 0; i < subArrayOneSize; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwoSize; j++)
        rightArray[j] = array[mid + 1 + j];
  
    int indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOneSize && indexOfSubArrayTwo < subArrayTwoSize) {
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
    while (indexOfSubArrayOne < subArrayOneSize) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwoSize) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergesort(int *a, int start, int end){
	if (start < end){
		int mid = start + (end-start)/2;
		
		mergesort(a, start, mid);
		mergesort(a, mid + 1, end);
		merge(a, start, mid, end);
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
	mergesort(a, 0, n-1);
	printArray(a, n);
	return 0;
}
