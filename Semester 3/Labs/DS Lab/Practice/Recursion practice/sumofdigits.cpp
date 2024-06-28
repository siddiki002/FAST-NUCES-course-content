#include <iostream>

using namespace std;
int ans = 0;
int sum_of_digits(int n)
{
    if (n==0)
    {
        return 0;
    }
    else
    {
        ans = n%10 + sum_of_digits(n/10); ;
        return ans;
    }
}
int main()
{
    cout<<sum_of_digits(102);
    // int n = 102;
    // int sum=0;
    // while (n!=0)
    // {
    //     sum+=n%10;
    //     n/=10;
    // }
    // cout<<sum;
    
}