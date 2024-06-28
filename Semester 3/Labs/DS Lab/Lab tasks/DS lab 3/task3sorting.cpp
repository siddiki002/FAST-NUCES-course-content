#include <iostream>

using namespace std;
void swap(int i, int j, int* arr)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}
void recursive_sort(int i, int j,int* arr,int n)
{
    if (i==n-1)
    {
        return;
    }
    if (arr[i]>arr[j])
    {
        swap(i,j,arr);
    }
    if (j==n-1)
    {
        j = i+2;
        //i+=1;
        return recursive_sort(i+1,j,arr,n);
    }
    else
    {
        return recursive_sort(i,j+1,arr,n);
    }
    
}
int main()
{
    int n;
    cout<<"Enter number of values"<<endl;
    cin>>n;
    int* arr = new int(n);
    cout<<"Enter values"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    recursive_sort(0,1,arr,n);
    cout<<endl<<"Sored array is: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    delete [] arr;
}
