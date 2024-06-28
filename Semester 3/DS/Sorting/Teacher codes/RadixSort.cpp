#include <iostream>
using namespace std;

void countSort(int *arr, int size, int exp){
	
	// 1 -- make count array and set elements to zero
	int count[10] = {0};
	
	// 2 -- count occurances of elements in arr
	for (int i = 0; i < size; i++){
		count[(arr[i]/exp) % 10]++;
				
		// e.g. (4325/10)%10 = 5 
		// or  (4325/100)%10 = 2
	}
	
	// 3 -- cummulative count
	for (int i = 1; i < 10; i++){
		count[i] = count[i] + count[i-1];
	}
	
	// 4 -- place elements in arr to right position in an output array
	int output[size];
	for (int i = size-1; i >= 0; i--){
		output[count[(arr[i]/exp)%10] - 1] = arr[i];
		count[(arr[i]/exp)%10]--;
	}
	// Note, the above loop could be from 0 to size -1
	// but we want to keep the order in which two 
	// elements appear in the original array.
	// This is because we place subsequent occurances 
	// of an element to the left side
	// (as done by the last line of the above loop).
	// E.g. in {321,229,65,58,311,70} for exp=1, we 
	// want to keep 321 before 311 (both have 1 at ones).
	
	// 5 -- copy output to original
	for (int i = 0; i < size; i++){
		arr[i] = output[i];
	}
}

void radixSort(int *arr, int size){
	int max = arr[0];
	for (int i = 0; i < size; i++)
		if (arr[i] > max)
			max = arr[i];

	// when number of digits in exp are more
	// than number of digits in max then zero.
	for (int exp = 1; max/exp > 0  ; exp *= 10){
		countSort(arr, size, exp);
	}
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int main(){
	int s = 6;
	int a[s] = {321,229,65,58,311,70};
	radixSort(a, s);
	printArray(a, s);
	return 0;
}
