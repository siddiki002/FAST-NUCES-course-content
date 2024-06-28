#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool is_subsequence (string main, string sub, int index_main, int index_sub)
{
	if (main.size()==index_main)
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
	string main,sub;
	cout<<"Enter main string: "<<endl;
	getline(cin,main);
	cout<<"Enter sub string: "<<endl;
	getline(cin,sub);
	if (is_subsequence(main,sub,0,0))
	{
		cout<<"The given string is a subsequence"<<endl;
	}
	else
	{
		cout<<"The given string is not a subsequence"<<endl;
	}
}
