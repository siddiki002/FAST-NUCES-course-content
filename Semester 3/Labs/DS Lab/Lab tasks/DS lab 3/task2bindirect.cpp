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
void indirect_recur(int check)
{
    recursive(1,0,check);
}

int main()
{
    indirect_recur(10);
    return 0;
}