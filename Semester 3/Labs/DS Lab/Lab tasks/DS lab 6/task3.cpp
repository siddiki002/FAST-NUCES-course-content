#include <iostream>

using namespace std;

class Node
{
    public:
    int val;
    Node* next;
    Node(int n){
        val = n;
        next = NULL;
    }
};

class CirciularLinkedList
{
    Node* router;
    public:
        CirciularLinkedList(){
            router = NULL;
        }
        void push(int n){
            Node* new_node = new Node(n);
            if (router==NULL){
                router = new_node;
                router->next = router;
            }
            else{
                Node* temp = router;
                while(temp->next!=router){
                    temp = temp->next;
                }
                temp->next = new_node;
                new_node->next = router;
            }
        }
        void traverse(){
            Node* temp = router;
            if (router==NULL){
                cout<<"Linked list not found"<<endl;
            }
            else{
                while(temp->next!=router){
                    cout<<temp->val<<" ";
                    temp = temp->next;
                }
                cout<<temp->val<<endl;
            }
        }
        void connect_nodes(int x, int y){
            Node* temp = router;
            Node* f_node = NULL;
            Node* s_node = NULL;
            while(temp->next!=router){
                if (temp->val==x){
                    f_node = temp;
                }
                else if(temp->val==y){
                    s_node = temp;
                }
                temp = temp->next;
            }
            if (temp->val==x){
                f_node = temp;
            }
            else if(temp->val==y){
                s_node = temp;
            }
           if (s_node!=NULL && f_node!=NULL){
               cout<<s_node<<" is connected with "<<f_node<<" having values "<<s_node->val<<" & "<<f_node->val<<endl;
           }
            
        }
};

int main(){
    CirciularLinkedList obj;
    for (int i = 0; i < 6; i++)
    {
        obj.push(i+1);
    }
    //obj.traverse();
    obj.connect_nodes(3,5);
    
}
