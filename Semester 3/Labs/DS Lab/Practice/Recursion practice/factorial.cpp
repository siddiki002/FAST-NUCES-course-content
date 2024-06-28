#include <iostream>

using namespace std;
int ans = 1;
int factorial(int n)
{
    if (n==0)
    {
        return 1;
    }
    else
    {
         ans = factorial(n-1);
        return (ans*=n);
    }
}
int main(){
    cout<<factorial(10);
}