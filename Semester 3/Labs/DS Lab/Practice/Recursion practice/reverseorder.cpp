#include <iostream>
#include <string>

using namespace std;

void print_reverse(string str, int index)
{
    if(index==-1){
        return;
    }
    else
    {
        cout<<str[index];
        print_reverse(str,index-1);
    }
}

int main()
{
    string str = "Ammar";
    print_reverse(str,str.size()-1);
}