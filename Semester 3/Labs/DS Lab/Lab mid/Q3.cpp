#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Node
{
	public:
		int val;
		Node* next;
		Node(int n)
		{
			val = n;
			next = NULL;
		}
};	

class Singlylist 
{
	Node* head;
	public:
		Singlylist()
		{
			head = NULL;
		}
		void push(int n)
		{
			Node* new_node = new Node(n);
			if (head==NULL)
			{
				head = new_node;
			}
				else
			{
			Node* temp = head;
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			}
		}	
		void re_arrange()
		{
			Node* temp = head;
			Node* prev = NULL;
			if (head==NULL)
			{
				cout<<"Linked list not started"<<endl;
			}
			else
			{
				prev = temp;
				temp = temp->next;
				while(temp->next!=NULL)
				{
					if (prev->val>temp->val)
					{
						int x = prev->val;
						prev->val = temp->val;
						temp->val = x;
					}
					if (temp->val<temp->next->val)
					{
						int x = temp->val;
						temp->val = temp->next->val;
						temp->next->val = x;
					}
					prev = temp->next;
					if (temp->next->next!=NULL)
					{
						temp = temp->next->next;
					}
					else
					{
						break;
					}
				}
				
			}
		}
		void traverse()
		{
			Node* temp = head;
			if (head==NULL)
			{
				cout<<"Linked list not started"<<endl;
			}
			else
			{
				while(temp!=NULL)
				{
					cout<<temp->val<<" ";
					temp = temp->next;
				}
			}
		}
};
int main()
{
	int n;
	Singlylist obj;
	cout<<"Enter number of values you wish to enter"<<endl;
	cin>>n;
	int x;
	cout<<"Enter values"<<endl;
	for (int i=0;i<n;i++)
	{
		cin>>x;
		obj.push(x);
	}
	obj.re_arrange();
	cout<<"After arranging"<<endl;
	obj.traverse();
}
