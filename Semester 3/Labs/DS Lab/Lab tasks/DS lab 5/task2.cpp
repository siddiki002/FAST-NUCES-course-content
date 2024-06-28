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
};

class singlylinkedlist
{
    Node* head;
    int size;
    public:
        singlylinkedlist()
        {
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
        void push_back(int n)
        {
            size++;
            Node* new_node = new Node;
            new_node->val = n;
            new_node->next = NULL;
            if (head==NULL)
            {
                head = new_node;
            }
            else
            {
                Node* temp;
                temp = head;
                while (temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next = new_node;
            }
        }
        void insert_at_start(int n)
        {
            size++;
            Node* temp;
            temp = head;
            Node* new_node = new Node;
            new_node->val = n;
            new_node->next = NULL;
            if (head==NULL)
            {
                head = new_node;
            }
            else
            {
                new_node->next = head;
                head = new_node;
            }
        }
        void insert_at_end(int n)
        {
            size++;
            Node* temp;
            Node* new_node = new Node;
            new_node->val = n;
            new_node->next = NULL;
            temp = head;
            if (head==NULL)
            {
                cout<<"Linked not started"<<endl;
            }
            else
            {
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next = new_node;
            }
        }
        void delete_from_start()
        {
            Node* temp;
            temp = head;
            if (head==NULL)
            {
                cout<<"Linked list not found"<<endl;
            }
            else
            {
                size--;
                head=head->next;
                delete temp;
            }
        }
        void delete_from_last()
        {
            Node* temp = head;
            Node* prev = NULL;
            if (head==NULL)
            {
                cout<<"Linked list not started"<<endl;
            }
            else
            {
                size--;
                while(temp->next!=NULL)
                {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = NULL;
                delete temp;
            }
        }
        void insert_after_position(int pos, int n) //considering '0' is the first index
        {
            if (pos>size)
            {
                cout<<"The indicated position doesn't exist within the linked list "<<endl;
            }
            else if (head==NULL)
            {
                push_back(n);
            }
            else if (pos==0)
            {
                insert_at_start(n);
            }
            else
            {
                Node* new_node = new Node;
                Node* temp = head;
                new_node->next = NULL;
                new_node->val = n;
                for (int i = 0; i < pos; i++)
                {
                    temp = temp->next;
                }
                if (temp->next==NULL)
                {
                    push_back(n);
                }
                else
                {
                    size++;
                    new_node->next = temp->next;
                    temp->next = new_node;
                }
            }
        }
        void insert_before_position(int pos, int n)
        {
            Node* temp = head;
            Node* prev = NULL;
            if (pos>size){
                cout<<"The given position doesn't exist within linked list"<<endl;
            }
            else if (head==NULL){
                cout<<"The linked list has not started"<<endl;
            }
            else if (pos==0){
                insert_at_start(n);
            }
            else{
                size++;
                Node* new_node = new Node;
                new_node->next = NULL;
                new_node->val = n;
                for(int i = 0 ; i< pos;i++)
                {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = new_node;
                new_node->next = temp;
            }
        }
        void delete_from_position(int pos)// Assuming that pos = 0 is the first element of list
        {
            Node* temp = head;
            Node* prev = NULL;
            if (pos>size)
            {
                cout<<"The entered position doesn't exist in linked list"<<endl;
            }
            //Node* temp = head;
            else if (head==NULL)
            {
                cout<<"Linked list not found"<<endl;
            }
            else if (pos==0)
            {
                delete_from_start();
            }
            else{
                for (int i=0;i<pos;i++)
                {
                    prev = temp;
                    temp = temp->next;
                }
                if (temp->next==NULL)
                {
                    delete_from_last();
                }
                else
                {
                    size--;
                    prev->next = temp->next;
                    delete temp;
                }
            }
        }
        void reverse()
        {
            if (head==NULL)
            {
                cout<<"Linked list doesn't exist"<<endl;
            }
            else{
                Node* temp = head;
                Node* next_node;
                head = head->next;
                next_node = head->next;
                temp->next = NULL;
                while(head->next!=NULL){
                    head->next = temp;
                    temp = head;
                    head = next_node;
                    next_node = next_node->next;
                }
                head->next = temp;
            }
        }
        void traverse()
        {
            Node* temp;
            temp = head;
            if (head==NULL)
            {
                cout<<"Linked list not started"<<endl;
            }
            else
            {
                while(temp!=NULL)
                {
                    cout<<temp->val<<endl;
                    temp = temp->next;
                }
            }

        }
        void sorting(){
            Node *temp = head;
            if (head=NULL){
                cout<<"Linked list not started"<<endl;
            }
            else
            {
                Node *current = NULL;
                while(temp->next!=NULL){
                    current = temp->next;
                    while(current!=NULL){
                        if (current->val<temp->val){
                            int x = current->val;
                            current->val = temp->val;
                            temp->val = x;
                        }
                        current = current->next;
                    }
                }
                temp = temp->next;
            }
        }
        int max(){
            int max = 0;
            Node *temp = head;
            if (head==NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                 max = temp->val;
                while(temp!=NULL){
                    if (temp->val>max){
                        max = temp->val;
                    }
                    temp = temp->next;
                }
                
            }
            return max;
        }
        float mean(){
            Node* temp = head;
            if (head=NULL){
                cout<<"Linked list not started"<<endl;
            }
            else{
                int sum = 0;
                while(temp!=NULL){
                    sum+= temp->val;
                    temp = temp->next;
                }
                float mean = sum/size;
                return mean;
                }
                return 0;
        }
        
};

int main()
{
    singlylinkedlist obj;
    obj.push_back(10);
    obj.insert_at_start(11);
    obj.insert_at_end(13);
    obj.insert_after_position(1,30);
    obj.insert_before_position(1,45);
    obj.insert_at_start(8);
    obj.traverse();
    //system("PAUSE");
    //obj.reverse();
   // singlylinkedlist obj2(obj);
    //obj.delete_from_position(2);
    cout<<"Max value is: "<<endl;
    cout<<obj.max()<<endl;
    cout<<"Mean value is: "<<endl;
    cout<<obj.mean()<<endl;
    
}
