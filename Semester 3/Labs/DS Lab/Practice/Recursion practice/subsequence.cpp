#include <iostream>
#include <string>

using namespace std;
bool is_subsequence(string main, string sub, int index_main, int index_sub)
{
    if (index_main==main.size())
    {
        return false;
    }
    else if (main[index_main]==sub[index_sub])
    {
        if (index_sub==sub.size()-1)
        {
            return true;
        }
        return is_subsequence(main,sub,index_main+1,index_sub+1);
    }
    return is_subsequence(main,sub,index_main+1,index_sub);
    

}
int main()
{
    string main = "cathartic";
    string sub = "hacl";
    //cout<<main.size()<<endl<<sub.size();
    if (is_subsequence(main,sub,0,0))
    {
        cout<<"The given string is a subsequence"<<endl;
    }
    else{
        cout<<"It is not a subsequence"<<endl;
    }
}