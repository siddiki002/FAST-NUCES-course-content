#include <iostream>
#include <math.h>
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
            size++;
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
        void pushback_array(int *arr){
            int n = sizeof(arr)/sizeof(int);
            for (int i = 0; i < n; i++)
            {
                //size++;
                pushback(arr[i]);
            }
            
        }
        float mean_odd(){
            Node* temp = head;
            float mean = 0;
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                float sum = 0;
                float count = 0;
                while(temp!=NULL){
                    if (temp->val%2!=0){
                        sum+=(float)temp->val;
                        count++;
                    }
                    temp = temp->next;
                }
                mean = sum/count;
            }
            return mean;

        }
        void traverse(){
            Node* temp = head;
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                while (temp!=NULL){
                    cout<<temp->val<<endl;
                    temp = temp->next;
                }
            }
        }
        void traverse_odd(){
            Node* temp = head;
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                int count = 0;
                while (temp!=NULL){
                    if (temp->val%2!=0){
                        cout<<temp->val<<endl;
                        count++;
                    }
                    temp = temp->next;
                }
                cout<<"Number of odd nodes "<<count<<endl;
            
            }
        }
};
bool is_square(int x){
    int temp = sqrt(x);
    if (temp*temp == x){
        return true;
    }
    return false;
}
bool is_fabonacci(int n){
    if (is_square(5*n*n - 4) || is_square(5*n*n + 4)){
        return true;
    }
    return false;
}
int main(){
    singlylinkedlist obj;
    cout<<"Enter how many numbers you want to enter"<<endl;
    int n;
    cin>>n;
    int *array = new int[n];
    cout<<"Enter values"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    //int *f_array = new int[n];
    for (int i = 0; i < n; i++)
    {
        int n = array[i];
        if (is_fabonacci(n)){
           obj.pushback(n);
        }
    }
    cout<<"Fabonacci numbers in list"<<endl;
    obj.traverse();
    cout<<"Odd numbers"<<endl;
    obj.traverse_odd();
    cout<<"Mean of odd number nodes"<<endl;
    float mean = obj.mean_odd();
    cout<<mean<<endl;
    
    
}