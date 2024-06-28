#include <iostream>
#define tablesize 20
using namespace std;

class Node
{
    public:
    int val;
    Node* next;
    Node(int v){
        val = v;
        next = NULL;
    }
};

class Linkedlist
{
    Node* head;
    public:
    Linkedlist(){head = NULL;}
    void insert(int val){
        Node* temp = head;
        Node* new_node = new Node(val);
        if (head==NULL){
            head = new_node;
        }
        else{
            while (temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    void traverse(){
        Node* temp = head;
        if (head==NULL){
            cout<<"Linked list is empty"<<endl;
            return;
        }
        else{
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp = temp->next;
            }
        }
    }
    bool search(int val){
        Node* temp = head;
        if (head==NULL){
            return false; 
        }
        else{
            while (temp!=NULL){
                if (temp->val==val){
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
    }
};

class hashtable
{
    Linkedlist *table;
    public:
        hashtable(){
            table = new Linkedlist[tablesize];
        }
        int h(int k){
            return (k%tablesize);
        }
        void add_entry(int val){
            int index = h(val);
            table[index].insert(val);
            cout<<"Value inserted"<<endl;
        }
        void search(int val){
            int index = h(val);
            if (table[index].search(val)){
                cout<<"Value is found at index "<<index<<" of the table"<<endl;
            }
            else{
                cout<<"Value not found"<<endl;
            }
        }
};

int main(){
    hashtable obj;
    obj.add_entry(45);
    obj.add_entry(11);
    obj.add_entry(65);
    obj.search(75);
}