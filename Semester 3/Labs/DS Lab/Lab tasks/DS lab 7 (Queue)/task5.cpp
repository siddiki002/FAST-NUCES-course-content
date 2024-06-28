#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(){
        val = 0;
        next = NULL;
    }
};
class QueueOfSinglyLinkedlist
{
    Node* front;
    Node* rear;
    Node* head;
    int size;
    public:
        QueueOfSinglyLinkedlist(){
            front = rear = NULL;
            head = NULL;
            size = 0;
        }
        void push_back(int n){
            size++;
            Node* new_node = new Node;
            new_node->val = n;
            new_node->next = NULL;
            if (head==NULL){
                rear = front = head = new_node;
            }
            else{
                Node* temp;
                temp = head;
                while (temp->next!=NULL){
                    temp=temp->next;
                }
                rear = new_node;
                temp->next = new_node;
            }
        }
        void pop(){
            Node* temp;
            temp = head;
            if (head==NULL){
                cout<<"Linked list not found"<<endl;
            }
            else{
                size--;
                front = head = head->next;
                delete temp;
            }
        }
        bool is_empty(){
            return(front==NULL);
        }
        void traverse(){
            Node* temp;
            temp = front;
            if (front==NULL){
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
    QueueOfSinglyLinkedlist obj;
    for (int i = 0; i < 5; i++){
        obj.push_back(i+5);
    }
    obj.traverse();
    if(obj.is_empty()){
        cout<<"Queue empty";
    }
    else{
        cout<<"Queue not empty";
    }
}