#include <iostream>

using namespace std;

void shell_sort(int* array, int n)
{
    for (int gap = n/2; gap > 0; gap/=2)
    {
        for (int i = gap ; i < n; i++)
        {
            int temp = array[i];
            int j;
            for (j=i;j>=gap && array[j-gap] > temp; j-=gap)
            {
                array[j] = array[j-gap];
            }
            array[j] = temp;
        }
        
    }
    
}

int main()
{
    int array[] = {4,1,2,9,11};
    int n = sizeof(array)/sizeof(array[0]);
    shell_sort(array,n);
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
}