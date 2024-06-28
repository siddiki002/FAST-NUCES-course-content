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
        singlylinkedlist (const  singlylinkedlist &obj)
        {
            Node* temp = head;
            Node* src_temp = obj.head;
            if (obj.head==NULL)
            {
                cout<<"The linked list doesn't exist"<<endl;
            }
            else{
                temp = new Node;
                head = temp;
                while(src_temp->next != NULL){
                    //temp = new(nothrow) Node;
                    temp->val = src_temp->val;
                    temp->next = new Node;
                    temp = temp->next;
                    src_temp = src_temp->next;
                }
                temp->val = src_temp->val;
                temp->next = NULL;
            }
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
        void pushback_array(int *arr, int n){
            //int n = sizeof(arr)/sizeof(int);
            for (int i = 0; i < n; i++)
            {
                pushback(arr[i]);
            }
            
        }
        void traverse(){
            Node* temp = head;
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                while(temp!=NULL){
                    cout<<temp->val<<endl;
                    temp = temp->next;
                }
            }
        }
        Node* get_head(){
            return head;
        }
        int get_size(){return size;}
};
void calculate_average(singlylinkedlist &number, singlylinkedlist &average){
    //number.traverse();
    Node* current=number.get_head();
    Node* temp=NULL;
    while(current->next!=NULL){
        int sum = 0;
        temp = current;
        for (int i = 0; i < 4 && temp->next!=NULL; i++)
        {   
            sum+=temp->val;
            temp = temp->next;
        }
        int avg = sum/number.get_size();
        average.pushback(avg);
        current = current->next;
        
    }
}
int main(){
    singlylinkedlist numberslist,averagelist;
    int arr[12];
    cout<<"Enter values"<<endl;
    for (int i = 0; i < 12; i++)
    {
            cin>>arr[i];
            numberslist.pushback(arr[i]);
    }
    
    //numberslist.pushback_array(arr);
    calculate_average(numberslist,averagelist);
    averagelist.traverse();
}