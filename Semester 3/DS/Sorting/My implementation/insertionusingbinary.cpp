#include <iostream>

using namespace std;
int binarysearch(int* array, int low, int high, int key);
void insertionusingbinary(int* array, int n)
{
    for (int i = 1; i < n; i++)
    {
        int ins = binarysearch(array,0,i,array[i]);
        int temp = array[i];
        for (int j = i-1; j >= ins ; j--)
        {
            array[j+1] = array[j];
        }
        array[ins] = temp;
        
    }
    
}

int binarysearch(int* array, int low, int high, int key)
{
    if (low==high){
        return low;
    }
    int mid = low + (high-low)/2;
    if (array[mid]>key)
    {
        return binarysearch(array,low,mid,key);
    }
    else if (array[mid]<key)
    {
        return binarysearch(array,mid+1,high,key);
    }
    //return mid;
        
    
    
}

int main()
{
    int array[] = {1,3,4,5,2,9,8};
    int n = sizeof(array)/sizeof(array[0]);
    insertionusingbinary(array,n);
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
}