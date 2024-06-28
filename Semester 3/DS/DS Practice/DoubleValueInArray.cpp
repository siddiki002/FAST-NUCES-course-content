#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {4,4,9,6,8,5,9,8,11,5};
    for (int i = 0; i < 10; i++)
    {
        for (int j = i+1; j < 10; j++)
        {
            if (arr[i]==arr[j])
            {
                cout<<arr[i]<<"\t";
            }
        }
        
    }
    
}