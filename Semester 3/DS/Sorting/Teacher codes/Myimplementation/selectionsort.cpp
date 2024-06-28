#include <iostream>

using namespace std;

void selection_sort(int* array, int n)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if(array[j]<array[min]){
                min = j;
            }
        }
        swap(array[i],array[min]);
        
    }
    
}

int main()
{
    int array[] = {4,5,1,8,9};
    int n = sizeof(array)/sizeof(array[0]);
    selection_sort(array,n);
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
}