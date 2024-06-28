#include <iostream>

using namespace std;
void recursive_func(int x, int n,int check)
{
    if (n>check)
    {
        return;
    }
    cout<<x+n<<" ";
    x+=n;
    recursive_func(x,n+1,check);
}
void indirect_recursion(int check)
{
    recursive_func(0,1,check);
}
int main()
{
    indirect_recursion(4);
}