#include <iostream>

using namespace std;

void selection_sort(int* array, int n)
{
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
        swap(array[i],array[min]);
        
    }
    
}

int main()
{
    int array[] = {2,4,1,5,7};
    int n = sizeof(array)/sizeof(array[0]);
    selection_sort(array,n);
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
}