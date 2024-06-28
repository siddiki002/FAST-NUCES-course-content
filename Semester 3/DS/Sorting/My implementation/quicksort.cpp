#include <iostream>

using namespace std;

int partition(int* array, int low, int high)
{
    int pivot = array[high];
    int pivot_index = low;

    for (int i = low; i < high; i++)
    {
        if (array[i]<pivot)
        {
            swap(array[pivot_index],array[i]);
            pivot_index++;
        }
    }
    swap(array[high],array[pivot_index]);
    return pivot_index;
}

void quick_sort(int* array, int low, int high)
{
    if (low<high)
    {
        int pivot_index = partition(array,low,high);

        quick_sort(array,low,pivot_index-1);
        quick_sort(array,pivot_index+1,high);
    }
}

int main()
{
    int array[] = {33,1,5,7,8,10};
    int n = sizeof(array)/sizeof(array[0]);
    quick_sort(array,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
}