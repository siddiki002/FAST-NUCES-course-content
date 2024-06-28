#include<iostream>

using namespace std;

class Node
{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int n){
        val = n;
        next = NULL;
        prev = NULL;
    }
};

class DoublyCircular
{
    Node* head;
    public:
        DoublyCircular(){
            head = NULL;
        }
        void push(int n){
            Node* new_node = new Node(n);
            if (head==NULL){
                head = new_node;
                head->next = head;
                head->prev = head;
                }
            else
            {
                Node* temp = head;
                while(temp->next!=head){
                    temp = temp->next;
                }
                temp->next = new_node;
                new_node->prev = temp;
                new_node->next = head;
            }
        }
        void traverse(){
            Node* temp = head;
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else
            {
                while (temp->next!=head)
                {
                    cout<<temp->val<<" ";
                    temp = temp->next;
                }
                cout<<temp->val<<endl;
            }
        }
        void delete_duplicates(){
            Node* temp = head;
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                while (temp->next!=head){
                    Node* iterator = temp->next;
                    while(iterator->next!=head){
                        if (iterator->val==temp->val){
                            Node* to_delete = iterator;
                            to_delete->prev->next = to_delete->next;
                            to_delete->next->prev = to_delete->prev;
                            iterator = iterator->next;
                            delete to_delete;
                        }
                        else
                        {
                            iterator = iterator->next;
                        }
                    }
                    if (iterator->val==temp->val)
                    {
                        Node* to_delete = iterator;
                        to_delete->prev->next = head;
                        delete to_delete;
                    }
                    temp = temp->next;
                   }
                    
                }
            }
        
};

int main()
{
    int n;
    cout<<"Enter number of values you will enter"<<endl;
    cin>>n;
    DoublyCircular obj;
    cout<<"Enter the pattern "<<endl;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        obj.push(temp);
    }
    obj.delete_duplicates();
    cout<<"According to the given pattern, the linked list is: "<<endl;
    obj.traverse();
    
}