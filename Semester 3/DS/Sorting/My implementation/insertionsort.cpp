#include <iostream>

using namespace std;

void insertion_sort(int* array, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = array[i];
        int j = i-1;
        while(j>=0 && array[j]>key)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
    
}

int main()
{
    int array[] = {4,5,1,2,8};
    int n = sizeof(array)/sizeof(array[0]);
    insertion_sort(array,n);
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
}