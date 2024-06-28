#include <iostream>

using namespace std;
int& fun(int arr[],int i)
{
    return arr[i];
}
int main()
{
    int *array = new int[5];
    for (int i = 0; i < 5; i++)
    {
        array[i] = i+1;
    }
    fun(array,3) = 7;
    cout<<"Elements of array are:"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<array[i]<<endl;
    }
    delete [] array;
    array = nullptr;
}