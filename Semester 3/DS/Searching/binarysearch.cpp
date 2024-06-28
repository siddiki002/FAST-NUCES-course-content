#include <iostream>

using namespace std;

int binary_search(int array[],int low, int high, int x){
    if (high>=low){
        int mid = low +(high-low)/2;
        if (array[mid]==x){
            return mid;
        }
        if (array[mid]<x){
            return binary_search(array,mid+1,high,x);
        }
        return binary_search(array,low,mid-1,x);
    }
    return -1;
}


void insertion_sort(int *array, int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int key = array[i];
        while(j>=0 && array[j]>key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

int main(){
    int array[] = {11,2,34,51,7,8,10,3,44,16,90,76};
    int n = sizeof(array)/sizeof(array[0]);
    insertion_sort(array,n);
    int x = 44;
    int index = binary_search(array,0,n-1,x);
    if (index!=-1){
        cout<<"Element found at index "<<index<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    
}