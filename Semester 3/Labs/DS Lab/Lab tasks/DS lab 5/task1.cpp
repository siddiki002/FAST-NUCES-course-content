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
        void pushback_array(int *arr,int n){
            //int n = sizeof(arr)/sizeof(int);
            for (int i = 0; i < n; i++)
            {
                pushback(arr[i]);
            }
            
        }
        int count(int n){
            int count = 0;
            Node* temp = head;
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                
                while(temp!=NULL){
                    if (temp->val==n){
                        count++;
                    }
                    temp= temp->next;
                }
            }
            return count;
        }
};

int main(){
    singlylinkedlist obj;
    int arr[] = {1,2,3,4,5,6,2,1,1,3};
    obj.pushback_array(arr,10);
    cout<<obj.count(1)<<endl;

}