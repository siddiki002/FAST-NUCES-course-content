#include <iostream>
#include <vector>
using namespace std;
void factorize(int);
int main()
{
    int n;
    cout<<"Enter a positive integer"<<endl;
    cin>>n;
    if (n<=0)
    {
        cout<<"Wrong number entered"<<endl;
    }
    else
    {
        factorize(n);
    }
    
}

void factorize(int n)
{
    vector <int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (n%i == 0)
        {
            ans.push_back(i);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
       cout<<ans[i]<<" ";
    }
    cout<<endl<<"The sum of factors is"<<endl;
    int sum=0;
    for (int i = 0; i < ans.size(); i++)
    {
        sum+=ans[i];
    }
    cout<<sum;
    
    
    
}