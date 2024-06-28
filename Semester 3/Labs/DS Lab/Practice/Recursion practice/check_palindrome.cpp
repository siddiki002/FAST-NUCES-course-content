#include <iostream>
#include <string>
using namespace std;

bool check_palindrome(string str, int low, int high)
{
    if (high==0)
    {
        return true;
    }
    else if (str[high]!=str[low])
    {
        return false;
    }
    else if (high==low && str[high]==str[low])
    {
        return true;
    }
    return check_palindrome(str,low+1,high-1);
}
int main()
{
    //string str= "civic";
    string str;
    getline(cin,str);
    if (check_palindrome(str,0,str.size()-1))
    {
        cout<<"string is palindrome"<<endl;
    }
    else{
        cout<<"string is not palindrome"<<endl;
    }
}