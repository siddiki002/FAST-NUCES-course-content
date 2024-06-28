#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int n){
        val = n;
        next = NULL;
    }
};

class stack
{
    Node* top;
    Node* head;
    public:
        stack(){
            top=NULL;
            head=NULL;
        }
        void push(int n){
            Node* new_node = new Node(n);
            if (top==NULL){
                top = new_node;
                head = new_node;
            }
            else{
                Node* temp = head;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = new_node;
                top = new_node;
            }
       }
       void traverse_forward(){
           Node* temp = head;
           if (head==NULL){
               cout<<"no linked list found"<<endl;
           }
           else{
               while(temp!=NULL){
                   cout<<temp->val<<" ";
                   temp = temp->next;
               }
           }
       }
       void traverse_backward(){
           
           if (head==NULL){
               cout<<"Linked list not found"<<endl;
           }
           else{
               while(top!=head){
                   Node* temp = head;
                   while(temp->next!=top){
                       temp = temp->next;
               }
                cout<<top->val<<" ";
                top = temp;
               }
               cout<<top->val<<endl;
               top = NULL;
               cout<<"Stack is empty"<<endl;
               
           }
       }
       int pop(){
           //int x = 0;
           Node* temp = head;
           if (head==NULL){
               cout<<"Linked list not found"<<endl;
               //return 0;
           }
           else{
               while(temp->next!=top){
                   temp = temp->next;
               }
               int x = top->val;
               top = temp;
               temp = temp->next;
               delete temp;
              cout<<"Integer popped"<<endl;
              return x;
           }
           //return x;
       }
};

int main(){
    stack obj;
    for (int i = 0; i < 5; i++)
    {
        obj.push(i*2);
    }
    //obj.traverse_forward();
    //obj.traverse_backward();
    cout<<obj.pop();
    
}