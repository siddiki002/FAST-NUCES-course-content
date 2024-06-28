#include <iostream>

using namespace std;

int main()
{
    int arr[10]={3,4,5,6,1,7,8,10,2,9};
    int max=arr[0],max2=arr[0];
    for (int i = 0; i < 10; i++)
    {
        if (max<arr[i])
        {
            max = arr[i];
        }
    }
    cout<<max<<endl;
    for (int i = 0; i < 10; i++)
    {
        if(arr[i]!=max)
        {
            if(max2<arr[i])
            {
                max2 = arr[i];
            }
        }
    }
    cout<<max2<<endl;
    max = max2;
    int k=0;
    while(k<8)
    {
        max2 = 0;
        for (int i = 0; i < 10; i++)
        {
            if(arr[i]<max)
            {
                if (max2<arr[i])
                {
                    max2 = arr[i];
                }
            }
        }
        cout<<max2<<endl;
        max = max2;
        k++;
    }
    
    
}