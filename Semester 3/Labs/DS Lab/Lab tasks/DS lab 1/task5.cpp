#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
int return_max(int *arr)
{
    int max=arr[0];
    for (int i = 0; i < 10; i++)
    {
        if (max<arr[i])
        {
            max = arr[i];
        }
    }
    return (max);
}
int return_min(int *arr)
{
    int min=arr[0];
    for (int i = 0; i < 10; i++)
    {
        if (min>arr[i])
        {
            min = arr[i];
        }
    }
    return (min);
}
void changevalues(int *max, int *min)
{
    *max = 10;
    *min = 5;
}
int main()
{
    int *arr = new int[10];
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand();
    }
    // cout<<"Elements in array are: "<<endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
    // system("PAUSE");
    int max,min;
    max = return_max(arr);
    min = return_min(arr);
    cout<<"Max is: "<<max<<endl<<"Min is: "<<min<<endl;
    changevalues(&max, &min);
    cout<<"After change"<<endl<<"Max is: "<<max<<endl<<"Min is: "<<min<<endl;
    delete [] arr;
    arr = nullptr;
}