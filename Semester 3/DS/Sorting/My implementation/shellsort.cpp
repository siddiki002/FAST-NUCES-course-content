#include <iostream>

using namespace std;
int comparisons = 0;
void shell_sort(int* array, int n)
{
    for (int gap = n/2; gap > 0; gap/=2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = array[i];
            int j;
            for (j = i;j>=gap && array[j-gap]>temp; j-=gap)
            {
                comparisons++;
                array[j] = array[j-gap];
            }
            array[j] = temp;
        }
        
    }
    
}

int main()
{
    int array[] = {3,1,5,6,11,9};
    int n = sizeof(array)/sizeof(array[0]);
    shell_sort(array,n);
    cout<<"Sorted array is: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<"Number of comparisons are: "<<comparisons<<endl;
    
}