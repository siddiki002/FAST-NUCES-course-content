#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class stack
{
	int top;
	int size;
	char* array;
	public:
		stack(int n)
		{
			size = n;
			top = -1;
			array = new char[n];
		}
		void push(char ch)
		{
			if (top<size)
			{
				array[++top] = ch;
			}
			else
			{
				cout<<"Stack overflow"<<endl;	
			}	
		}
		char peek()
		{
			if (top>-1)
			{
				return array[top];			
			}		
		}
		char pop()
		{
			if (top>-1)
			{
				return array[top--];		
			}		
		}	
		bool is_empty()
		{
			return (top==-1);
		}
};
int main()
{
	string input;
	cout<<"Enter string"<<endl;
	getline(cin,input);
	stack expression(input.size());
	for (int i=0;i<input.size();i++)
	{
		if (input[i]=='(' || input[i]==')')
		{
			expression.push(input[i]);	
		}	
	}	
	int count = 0;
	while (!expression.is_empty())
	{
		if (expression.peek()==')')
		{
			count++;
		}
		expression.pop();
	}
	if (count>1)
	{
		cout<<"Duplicate () found in sub-expression "<<input<<endl;
	}
	else
	{
		cout<<"No Duplicatre () is found"<<endl;
	}
}
