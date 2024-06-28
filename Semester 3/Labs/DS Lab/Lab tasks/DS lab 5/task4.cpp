#include <iostream>

using namespace std;

class Node
{
    public:
    int val;
    Node* next;
    Node()
    {
        val = 0;
        next = NULL;
    }
    Node(int n){
        val = n;
        next = NULL;
    }
};

class singlylinkedlist{
    Node* head;
    int size;
    public:
        singlylinkedlist(){
            head = NULL;
            size = 0;
        }
        void pushback(int n){
            Node* new_node = new Node(n);
            if (head==NULL){
                head = new_node;
            }
            else{
                Node* temp = head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next = new_node;
            }
        }
        void swap_even_odd(){
            Node* temp = head;
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                Node* even_node = temp;
                Node* odd_node = temp;
                while(temp!=NULL){
                    if (temp->val%2==1){
                        odd_node = temp;
                        break;
                    }
                    temp = temp->next;
                }
                while (temp!=NULL)
                {
                    if (temp->val%2==0){
                        even_node = temp;
                    }
                    temp = temp->next;
                }
                int temp = even_node->val;
                even_node->val = odd_node->val;
                odd_node->val = temp;
                
            }
        }
        void traverse(){
            Node* temp = head;
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                while (temp!=NULL)
                {
                    cout<<temp->val<<endl;
                    temp = temp->next;
                }
                
            }
        }
};

// driver program
int main(){
    singlylinkedlist obj;
    obj.pushback(4);
    obj.pushback(3);
    obj.pushback(5);
    obj.pushback(2);
    obj.pushback(3);
    obj.traverse();
    system("PAUSE");
    obj.swap_even_odd();
    obj.traverse();


}