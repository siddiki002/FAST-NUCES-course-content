#include <iostream>

using namespace std;

void count_sort(int* array, int n)
{
    int max = array[0];
    for (int i = 0; i < n; i++)
    {
        if (array[i]>max){
            max = array[i];
        }
    }
    int* count = new int[max+1];
    for (int i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        count[array[i]]++;
    }
    for (int i = 1; i < max+1; i++)
    {
        count[i] = count[i] + count[i-1];
    }
    int* output = new int[n];
    for (int i = 0; i < n; i++)
    {
        output[count[array[i]]-1] = array[i];
        count[array[i]]--;
    }
    for (int i = n-1; i >= 0; i--)
    {
        array[i] = output[i];
    }
}

int main()
{
    int array[] = {3,4,5,1,0,9};
    int n = sizeof(array)/sizeof(array[0]);
    count_sort(array,n);
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
}