#include <iostream>

using namespace std;

int main()
{
    int n = 12;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            cout<<" ";
        }
        for (int k = i+1; k < n-i; k++)
        {
            cout<<"*";
        }
        cout<<endl;
        
        
    }
    
}