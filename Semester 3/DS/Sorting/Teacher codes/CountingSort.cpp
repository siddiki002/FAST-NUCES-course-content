#include <iostream>
using namespace std;

void countSort(int *arr, int size){
	
	// 1 -- find max
	int max = arr[0];
	for (int i = 1; i<size; i++){
		if (arr[i]>max)
			max = arr[i];
	}
	
	// 2 -- make count array and set elements to zero
	int count[max+1]; // or = {0};
	for (int i = 0; i < max+1; i++){
		count[i] = 0;
	}
	
	// 3 -- count occurances of elements in arr
	for (int i = 0; i < size; i++){
		count[arr[i]]++;
	}
	
	// 4 -- cummulative count
	for (int i = 1; i < max+1; i++){
		count[i] = count[i] + count[i-1];
	}
	
	// 5 -- place elements in arr to right position in an output array
	int output[size];
	
	for (int i = size - 1; i >=0; i--){
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	// Note, the above loop could be from 0 to size -1
	// but we want to keep the order in which two same 
	// elements appear in the original array. 
	// This is because we place subsequent occurances 
	// of an element to the left side
	// (as done by the last line of the above loop).
	
	// 6 -- copy output to original
	for (int i = 0; i < size; i++){
		arr[i] = output[i];
	}
}


void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int main(){
	int s = 6;
	int a[s] = {3,2,6,5,3,7};
	countSort(a, s);
	printArray(a, s);
	return 0;
}
