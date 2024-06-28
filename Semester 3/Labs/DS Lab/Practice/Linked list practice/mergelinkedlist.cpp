#include <iostream>

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

class Singlylinkedlist
{
    Node* head;
    public:
        Singlylinkedlist()
        {
            head = NULL;
        }
        void push_back(int n)
        {
            Node* new_node = new Node(n);
            if (head==NULL)
            {
                head=  new_node;
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
        void traverse()
        {
            if(head==NULL)
            {
                cout<<"Linked list not found"<<endl;
            }
            else
            {
                Node* temp = head;
                while(temp!=NULL)
                {
                    cout<<temp->val<<" ";
                    temp = temp->next;
                }
            }
        }
        void set_head(Node* temp)
        {
            if (temp!=NULL)
            {
                head = temp;
            }
        }
        Node* get_head()
        {
            return head;
        }
};

Singlylinkedlist merge_list(Singlylinkedlist &obj1, Singlylinkedlist &obj2)
{
    Node* temp_1 = obj1.get_head();
    Node* temp_2 = obj2.get_head();
    if (temp_1==NULL && temp_2==NULL)
    {
        cout<<"Both linked list are empty"<<endl;
    }
    // else if(temp_1==NULL){
    //     return (obj2.get_head());
    // }
    // else if (temp_2==NULL)
    // {
    //     return (obj1.get_head());
    // }
    else
    {
        Node* iterator = temp_1;
        while(iterator->next!=NULL)
        {
            iterator = iterator->next;
        }
        iterator->next = temp_2;        //List merged.
        //iterator->next = nullptr;
    }
   
    
    Singlylinkedlist temp_obj;
    temp_obj.set_head(temp_1);
    return temp_obj;
    //return (obj1.get_head());
}
int main()
{
    Singlylinkedlist obj1,obj2;
    for (int i = 0; i <= 10; i++)
    {
        obj1.push_back(i+2);
        obj2.push_back(i+3);
    }
    // obj1.traverse();
    // obj2.traverse();
   Singlylinkedlist obj3 = merge_list(obj1,obj2);
    obj3.traverse();
    
}