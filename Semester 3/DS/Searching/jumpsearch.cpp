#include <iostream>

using namespace std;
int jump_search(int array[], int step, int n, int x){
    int i = 0,temp;
    while (i<n && array[i]<x){
        temp = i;
        i+=4;
    }
    if (i>n){return -1;}
    for (int j = temp; j < i; j++)
    {
        if (array[j]==x){
            return j;
        }
    }
    return -1;
    
    
}
int partition(int *array, int low, int high){
        int pivot_index = low;
        int pivot = array[high];
        for (int i=low;i<high;i++){
                if (array[i]<pivot){
                    swap(array[pivot_index],array[i]);
                    pivot_index++;
                }
        }
        swap(array[pivot_index],array[high]);
        return (pivot_index);
}

void quicksort(int *array, int low, int high){
    if (low<high){
        int pivot_index = partition(array,low,high);

        quicksort(array,low,pivot_index-1);
        quicksort(array,pivot_index+1,high);
    }
}

int main(){
    int array[] = {12,44,1,5,6,90,8,112};
    int n = sizeof(array)/sizeof(array[0]);
    quicksort(array,0,n-1);
    int x = 112;
    int index = jump_search(array,3,n,x);
    if (index!=-1){
        cout<<"Element found at index "<<index<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
    
}