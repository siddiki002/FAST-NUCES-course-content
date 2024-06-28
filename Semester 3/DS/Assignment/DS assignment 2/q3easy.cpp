#include <iostream>

using namespace std;

class Node
{
    public:
    int quota,time;
    string id;
    Node* next;
    Node(int q, int t, string i)
    {
        quota = q;
        time = t;
        id = i;
        next = NULL;
    }
};

class circularlinkedlist
{
    Node* head;
    Node* tail;
    public:
        circularlinkedlist(){head = NULL;}
        void push_back(int q, int t, string i)
        {
            Node* new_node = new Node(q,t,i);
            if(head==NULL)
            {
               tail = new_node;
               head = new_node;
               new_node->next = head; 
            }
            else
            {
                Node* temp = head;
                while(temp->next!=head)
                {
                    temp = temp->next;
                }
                temp->next = new_node;
                new_node->next = head;
                tail = new_node;
            }
        }
        void traverse(){
            Node* temp=head;
            if (head==NULL)
            {
                cout<<"Linked list not found"<<endl;
            }
            else{
                while(temp->next!=head)
                {
                    cout<<temp->id<<endl;
                    temp = temp->next;
                }
                cout<<temp->id<<endl;
            }
        }
        void OS_operation()
        {
            while(head!=NULL)
            {
                traverse();
                Node* temp = head;
                Node* prev = tail;
                while(temp->next!=head)
                {
                    
                        temp->time-=temp->quota;
                        //Node* to_delete = NULL;
                        if(temp->time==0)
                        {
                            Node* to_delete = temp;
                            prev->next = temp->next;
                            if(temp==head)
                            {
                            	head = head->next;
							}
                            temp = temp->next;
                            delete to_delete;

                        }
                        //prev = temp;
                        else
                        {
                            prev = temp;
                            temp = temp->next;
                        }
                        
                    
                    
                }
                
                temp->time-=temp->quota;
                //Node* to_delete = NULL;
                if(temp->time==0)
                {
                    Node* to_delete = temp;
                    prev->next = temp->next;
                    if(head==temp)
                    {
                        head=NULL;
                    }
                    delete to_delete;
                }
                
                    
                    
        }
    }
};

int main()
{
    circularlinkedlist obj;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string str;
        int t,q;
        cin>>str>>t>>q;
        obj.push_back(q,t,str);
    }
    //obj.traverse();
    obj.OS_operation();
}
