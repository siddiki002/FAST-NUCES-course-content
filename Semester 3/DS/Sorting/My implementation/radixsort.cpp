#include <iostream>

using namespace std;

void count_sort(int *array, int n, int exp)
{
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(array[i]/exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i-1];
    }
    int* output = new int[n];
    for (int i = n-1; i >= 0; i--)
    {
        output[count[(array[i]/exp) %10]-1] = array[i];
        count[(array[i]/exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        array[i] = output[i];
    }
}

void radix_sort(int* array, int n)
{
    int max = array[0];
    for (int i = 0; i < n; i++)
    {
        if (array[i]>max)
        {
            max = array[i];
        }
    }
    for (int i = 1; max/i > 0; i*=10)
    {
        count_sort(array,n,i);
    }
    
}

int main()
{
    int array[] = {345,123,678,100,131,780,900,876};
    int n = sizeof(array)/sizeof(array[0]);
    radix_sort(array,n);
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
}