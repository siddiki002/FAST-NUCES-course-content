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
        void print_mid(){
            // size is maintained therefore not taking it as parameter
            Node* temp = head;
            if (head==NULL){
                cout<<"Linked list not found"<<endl;
            }
            else{
                int mid = (size/2);
                for (int i = 0; i < mid; i++)
                {
                    temp = temp->next;
                }
                cout<<"The value of middle node is: "<<temp->val<<endl;
                
            }
        }
};

int main(){
    doublylinkedlist obj;
    for (int i = 0; i < 6; i++)
    {
        obj.push_back(i+1);
    }
    obj.print_mid();
    
}