#include <iostream>

using namespace std;

int* fun()
{
    int *ptr = new int[5];
    for (int i = 0; i < 5; i++)
    {
        ptr[i] = i+1;
    }
    return(ptr);
    
}
int main()
{
    int *ptr;
    ptr = fun();
    for (int i = 0; i < 5; i++)
    {
        cout<<ptr[i]<<endl;
    }
    delete [] ptr;
    ptr = nullptr;
    
}