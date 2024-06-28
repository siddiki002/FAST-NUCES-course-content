#include <iostream>

using namespace std;

void sort_arrays(int* array, int* indexes, int n)
{
    //implying selection sort
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (array[j]<array[min])
            {
                min = j;
            }
        }
        swap(indexes[min],indexes[i]);
        
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int array[] = {3,1,5,10,16,10};
    int indexes[] = {0,1,2,3,4,5};
    sort_arrays(array,indexes,6);
    for (int i = 0; i < 6; i++)
    {
        cout<<"array [i] "<<array[i]<<" indexes[i] "<<indexes[i]<<endl;
    }
    
}