#include <iostream>

using namespace std;
void sort_ascending(int *arr, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j=i+1; j < n; j++)
        {
            if(arr[j]<arr[i])
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
    
}
void sort_descending(int *arr, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j=i+1; j < n; j++)
        {
            if(arr[j]>arr[i])
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
    
}
int main()
{
    int *arr;
    int elem;
    cout<<"Enter number of elements in the array: "<<endl;
    cin>>elem;
    arr = new(nothrow) int[elem];
    cout<<"enter values"<<endl;
    for (int i = 0; i < elem; i++)
    {
        cin>>arr[i];
    }
    
    int *max_arr,*min_arr;
    max_arr = new(nothrow) int[elem];
    min_arr = new(nothrow) int[elem];
    for (int i = 0; i < elem; i++)
    {
        min_arr[i] = arr[i];
        max_arr[i] = arr[i];
    }
    
    // bubble sorting;
    sort_ascending(min_arr,elem);
    sort_descending(max_arr,elem);
    for (int i = 0; i < elem; i++)
    {
        if (max_arr[i]!=min_arr[i])
        {
            cout<<max_arr[i]<<'\t'<<min_arr[i]<<'\t';
        }
        if (max_arr[i]==min_arr[i] || max_arr[i]==min_arr[i+1])
        {
            cout<<'\t'<<max_arr[i];
            break;
        }
    }
    

}