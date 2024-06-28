#include <iostream>

using namespace std;
void merge(int *array, int left, int mid, int right)
{
    int sizeofleftarray = mid+1-left;
    int sizeofrightarray = right-mid;
    int *leftarray = new int[sizeofleftarray];
    int *rightarray = new int[sizeofrightarray];
    // copying values;
    for (int i = 0; i < sizeofleftarray; i++)
    {
        leftarray[i] = array[left+i];
    }
    for (int j = 0; j < sizeofrightarray; j++)
    {
        rightarray[j] = array[mid+1+j];
    }
    // intitializing indexes
    int indexofleftarray = 0;
    int indexofrightarray = 0;
    int mergedarrayindex = left;

    while (indexofleftarray<sizeofleftarray && indexofrightarray<sizeofrightarray)
    {
        if (leftarray[indexofleftarray]<=rightarray[indexofrightarray])
        {
            array[mergedarrayindex] = leftarray[indexofleftarray];
            indexofleftarray++;
        }
        else
        {
            array[mergedarrayindex] = rightarray[indexofrightarray];
            indexofrightarray++;
        }
        mergedarrayindex++;
    }
    while (indexofleftarray<sizeofleftarray)
    {
        array[mergedarrayindex] = leftarray[indexofleftarray];
        indexofleftarray++;
        mergedarrayindex++;
    }
    while (indexofrightarray < sizeofrightarray)
    {
        array[mergedarrayindex] = rightarray[indexofrightarray];
        indexofrightarray++;
        mergedarrayindex++;
    }
    
    
    
}
void merge_sort(int* array, int low, int high)
{
    if(low < high)
    {
        int mid = low +(high-low)/2;

        merge_sort(array,low,mid);
        merge_sort(array,mid+1,high);
        merge(array,low,mid,high);
    }
}

int main()
{
    int array[] = {3,5,1,2,9,10,4};
    int n = sizeof(array)/sizeof(array[0]);
    merge_sort(array,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
}