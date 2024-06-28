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
    Node(int val){
        this->val = val;
        next = NULL;
    }
};
class Linkedlist{
    Node* head;
    public:
    Linkedlist(){
        head = NULL;
    }
    void push_back(int val){
        Node* new_node = new Node(val);
        if (head==NULL){
            head=  new_node;
        }
        else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    void delete_repetition(){
        Node* temp = head;
        Node* prev=NULL;
        Node* current =NULL;
        while(temp->next!=NULL){
            current = temp->next;
            prev = temp;
            
            while(current!=NULL){
                if (temp->val==current->val){
                    Node* to_delete = NULL;
                    prev->next = current->next;
                    to_delete = current;
                    current = current->next;
                    delete to_delete;
                }
                else
                {
                    prev = current;
                    current = current->next;
                }
                
            }
            temp = temp->next;

        }
    }
    void traverse(){
        Node* temp = head;
        if (head==NULL){
            cout<<"Linked list not found"<<endl;
        }
        while(temp!=NULL){
            cout<<temp->val<<endl;
            temp=temp->next;
        }
    }
    
};
int main(){
    Linkedlist obj;
    obj.push_back(1);
    obj.push_back(2);
    obj.push_back(3);
    obj.push_back(4);
    obj.push_back(1);
    obj.push_back(2);
    obj.push_back(1);
    obj.traverse();
    system("PAUSE");
    cout<<"After deletion"<<endl;
    //system("PAUSE");
    obj.delete_repetition();
    obj.traverse();
}