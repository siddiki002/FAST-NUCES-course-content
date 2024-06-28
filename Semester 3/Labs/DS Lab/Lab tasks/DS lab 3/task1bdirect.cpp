#include <iostream>

using namespace std;
void recursive(int n, int sum, int check)
{
    if (sum==0)
    {
        cout<<n<<" ";
    }
    if (sum>check-2)
    return;
    cout<<n+sum<<" ";
    n+=sum;
    recursive(n,sum+1,check);
}
int main()
{
    int count;
    cout<<"Enter the number of elements to print: "<<endl;
    cin>>count;
    recursive(1,0,count);
}