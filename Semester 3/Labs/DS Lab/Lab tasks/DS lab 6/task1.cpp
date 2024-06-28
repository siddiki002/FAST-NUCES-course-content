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
        void insert_at_front(int n){
            size++;
            //Node* temp = head;
            Node* new_node = new Node(n);
            if (head==NULL){
                head = new_node;
                tail = new_node;
            }
            else{
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
        }
        void insert_at_end(int n){
            size++;
            Node* new_node = new Node(n);
            if (head==NULL){
                head = new_node;
                tail = new_node;
            }
            else{
                new_node->prev = tail;
                tail->next = new_node;
                tail = new_node;
            }
        }
        void insert_after_position(int n, int pos){
            Node* temp = head;
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else if(pos>size || pos<0 || pos==size-1){
                cout<<"The position doesn't exist within the list"<<endl;
            }
            // else if (pos==size-1){
            //     insert_at_end(n);
            // }
            else if (pos==0){
                insert_at_front(n);
            }
            else{
                size++;
                for (int i = 0; i <= pos; i++)
                {
                    temp = temp->next;
                }
                Node* new_node = new Node(n);
                new_node->next = temp;
                temp->prev->next = new_node;
                new_node->prev = temp->prev;
                temp->prev = new_node;
            }
        }
        void insert_before_position(int n, int pos){
            Node* temp = head;
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else if(pos>size || pos<0 || pos==0){
                cout<<"The position doesn't exist within the list"<<endl;
            }
            else if (pos==1){
                insert_at_front(n);
            }
            else{
                size++;
                for (int i = 0; i < pos; i++)
                {
                    temp = temp->next;
                }
                Node* new_node = new Node(n);
                new_node->next = temp;
                temp->prev->next = new_node;
                new_node->prev = temp->prev;
                temp->prev = new_node;
            }
        }
        void delete_from_start(){
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                size--;
                Node* temp = head;
                head = head->next;
                head->prev = NULL;
                delete temp;
            }
        }
        void delete_from_end(){
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                size--;
                Node* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
            }
        }
        void delete_from_position(int pos){
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else if(pos==size-1 || pos<0 || pos>size){
                cout<<"The position doesn't exist within the list"<<endl;
            }
           else{
               size--;
               Node* temp = head;
                for (int i = 0; i < pos; i++)
                {
                    temp=temp->next;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                
            }


        }
        void reverse(){
            if (head==NULL){
                cout<<"Linked list not found"<<endl;
            }
            else{
                Node* temp = head;
                head = tail;
                tail = temp;
                Node* next_node = temp->next;
                while(temp->next!=NULL){
                    temp->next = temp->prev;
                    temp->prev = next_node;
                    temp = next_node;
                    next_node = next_node->next;
                }
                temp->next = temp->prev;
                temp->prev = NULL;
            }
        }
        void sort(){
            Node *temp = head;
            if (head=NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                while(temp->next!=NULL){
                    Node* check = temp->next;
                    while(check!=NULL){
                        if (temp->val>check->val){
                            int x = temp->val;
                            temp->val = check->val;
                            check->val = x;
                        }
                        check = check->next;
                    }
                    temp = temp->next;
                }
            }
        }
        int maximum(){
            Node* temp = head;
            if(head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                int max = temp->val;
                while(temp!=NULL){
                    if (temp->val>max){
                        max = temp->val;
                    }
                    temp = temp->next;
                }
                return max;
            }
            return 0;
        }
        float mean(){
            Node* temp = head;
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                int sum = 0;
                while(temp!=NULL){
                    sum+=temp->val;
                    temp = temp->next;
                }
                float mean = (float)sum/size;
                return mean;
            }
            return 0;
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
    // In all functions, the list starting point is 0;
    doublylinkedlist obj;
    for (int i = 1; i <= 10; i++)
    {
        obj.push_back(i);
    }
    //obj.reverse();
    //obj.traverse();

    // obj.insert_at_front(-1);
     obj.insert_at_end(11);
     obj.insert_after_position(38,3);
    // obj.insert_before_position(41,9);
    // obj.delete_from_start();
    // obj.delete_from_end();
    // obj.delete_from_position(7);
    obj.traverse();
    cout<<endl;
    cout<<obj.maximum()<<endl;
    cout<<obj.mean();
}