#include <iostream>

using namespace std;

void merge(int* array, int left, int mid, int right)
{
    int sizeofleftarray = mid-left+1;
    int sizeofrightarray = right - mid;
    int* rightarray = new int[sizeofrightarray];
    int* leftarray = new int[sizeofleftarray];
    //copying elements
    for (int i = 0; i < sizeofleftarray; i++)
    {
        leftarray[i] = array[left+i];
    }
    for (int j = 0; j < sizeofrightarray; j++)
    {
        rightarray[j] = array[mid+1+j];
    }
    // initializing indexes

    int indexoffirstarray = 0;
    int indexofsecondarray = 0;
    int mergedindex = left;

    while (indexoffirstarray<sizeofleftarray && indexofsecondarray < sizeofrightarray)
    {
        if (leftarray[indexoffirstarray]<=rightarray[indexofsecondarray])
        {
            array[mergedindex] = leftarray[indexoffirstarray];
            indexoffirstarray++;
        }
        else
        {
            array[mergedindex] = rightarray[indexofsecondarray];
            indexofsecondarray++;
        }
        mergedindex++;
    }
    while (indexoffirstarray < sizeofleftarray)
    {
        array[mergedindex] = leftarray[indexoffirstarray];
        indexoffirstarray++;
        mergedindex++;
    }
    while (indexofsecondarray < sizeofrightarray)
    {
        array[mergedindex] = rightarray[indexofsecondarray];
        indexofsecondarray++;
        mergedindex++;
    }
    
    
}
void merge_sort(int* array, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high-low)/2;
        merge_sort(array,low,mid);
        merge_sort(array,mid+1,high);
        merge(array,low,mid,high);
    }
}

int main()
{
    int array[] = {3,4,1,2,7,8};
    int n = sizeof(array)/sizeof(array[0]);

    merge_sort(array,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
}