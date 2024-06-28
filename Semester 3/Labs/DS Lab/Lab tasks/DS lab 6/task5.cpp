#include <iostream>

using namespace std;

class Node{
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

class doublylinkedlist
{
    Node* head;
    Node* tail;
    int size;
    public:
        doublylinkedlist(){
            head = NULL;
            tail = NULL;
            size = 0;
        }
        void push_back(int n){
            size++;
            Node* temp = head;
            Node* new_node = new Node(n);
            if (head==NULL){
                head = new_node;
                tail = new_node;
            }
            else{
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = new_node;
                new_node->prev = temp;
                tail = new_node;
            }
        }
        void delete_repetition(){
            Node* temp = head;
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                while(temp->next!=NULL){
                    Node* iterator = temp->next;
                    while (iterator!=NULL)
                    {
                        if (temp->val==iterator->val){
                        Node* to_delete = iterator;
                        to_delete->prev->next = to_delete->next;
                        to_delete->next->prev = to_delete->prev;
                        iterator = iterator->next;
                        delete to_delete;
                        }
                        else{
                            iterator = iterator->next;    
                        }
                        
                    }
                    temp = temp->next;
                }
            }
        }
         void traverse(){
            Node* temp = head;
            if(head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                while(temp!=NULL){
                    cout<<temp->val<<" ";
                    temp = temp->next;
                }
            }
        }
};

int main(){
    doublylinkedlist obj;
    for (int i = 0; i < 10; i++)
    {
        int n;
        cin>>n;
        obj.push_back(n);
    }
    cout<<"Elements before deleting repetition"<<endl;
    obj.traverse();
    cout<<endl;
    cout<<"Elements after deleting repetition"<<endl;
    obj.delete_repetition();
    obj.traverse();
}