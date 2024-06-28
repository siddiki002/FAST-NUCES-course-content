#include <iostream>
#include <string>
using namespace std;
class Node
{
    public:
        int coefficient,power;
        char variable;
        Node* next;
        Node(int coeff, char var, int pow)
        {
            coefficient = coeff;
            variable = var;
            power = pow;
            next = NULL;
        }
};

class Linkedlist
{
    Node* head;
    public:
        Linkedlist()
        {
            head = NULL;
        }
        void add_node(int c, char v, int p)
        {
            Node* new_node = new Node(c,v,p);
            if (head==NULL)
            {
                head = new_node;
            }
            else
            {
                Node* temp =  head;
                while(temp->next!=NULL)
                {
                    temp = temp->next;
                }
                temp->next = new_node;
            }
        }
        void traverse()
        {
            if (head==NULL)
            {
                cout<<"Linked list not started"<<endl;
            }
            else
            {
                Node* temp = head;
                while(temp!=NULL)
                {
                    cout<<temp->coefficient<<" "<<temp->variable<<" "<<temp->power<<endl;
                    temp=temp->next;
                }
            }
        }
        void sort_alphabetically()
        {
            Node* temp = head;
            if (head==NULL)
            {
                cout<<"Linked list not found"<<endl;
            }
            else
            {
                while(temp->next!=NULL)
                {
                    Node* iterator = temp->next;
                    while (iterator!=NULL)
                    {
                        if(temp->variable>iterator->variable)
                        {
                            swap(temp->coefficient,iterator->coefficient);
                            swap(temp->variable,iterator->variable);
                            swap(temp->power,iterator->power);
                        }
                        iterator = iterator->next;
                    }
                    temp = temp->next;
                }
            }
        }
        void sort_ascending()
        {
            Node* temp = head;
            if (head==NULL)
            {
                cout<<"Linked list not found"<<endl;
            }
            else
            {
                while(temp->next!=NULL)
                {
                    Node* iterator = temp->next;
                    while(iterator!=NULL)
                    {
                        if(temp->power>iterator->power && temp->variable ==  iterator->variable)
                        {
                            swap(temp->coefficient,iterator->coefficient);
                            swap(temp->variable,iterator->variable);
                            swap(temp->power,iterator->power);
                        }
                        iterator = iterator->next;
                    }
                    temp = temp->next;
                }
            }
        }
        void delete_repetition()
        {
            Node* temp = head;
            if (head==NULL)
            {
                cout<<"Linked list not started"<<endl;
            }
            else{
                while(temp!=NULL)
                {
                    Node* iterator = temp->next;
                    Node* prev = temp;
                    while (iterator!=NULL)
                    {
                        if(temp->power==iterator->power && temp->variable==iterator->variable)
                        {
                            Node* to_delete = iterator;
                            prev->next = iterator->next;
                            iterator = iterator->next;
                            delete to_delete;
                        }
                        else{
                            prev = iterator;
                            iterator = iterator->next;
                        }
                    }
                    temp = temp->next;   
                }
            }
        }
        int count_nodes()
        {
            int count = 0;
            Node* temp = head;
            if(head==NULL){
                cout<<"Linked list not found"<<endl;
            }
            else{
                
                while(temp!=NULL)
                {
                    count++;
                    temp = temp->next;
                }
            }
            return count;
        }
        void add_nodes()
        {
            Node* temp = head;
            if (head==NULL)
            {
                cout<<"Linked list is empty"<<endl;
            }
            else
            {
                while(temp->next!=NULL)
                {
                    Node* iterator = temp->next;
                    while(iterator!=NULL)
                    {
                        if (temp->power==iterator->power && temp->variable==iterator->variable)
                        {
                            temp->coefficient+=iterator->coefficient;
                        }
                        iterator = iterator->next;
                    }
                    temp = temp->next;
                }
            }
        }
};

int main(){
    int coeff,pow;
    char var;
    Linkedlist obj;
    int n1;
    cin>>n1;
    int n2;
    for (int i = 0; i < n1; i++){
        cin>>coeff>>var>>pow;
        obj.add_node(coeff,var,pow);
    }
    cin>>n2;
    for (int i = 0; i < n2; i++){
        cin>>coeff>>var>>pow;
        obj.add_node(coeff,var,pow);
    }
    obj.add_nodes();
    obj.delete_repetition();
    obj.sort_alphabetically();
    obj.sort_ascending();
    cout<<obj.count_nodes()<<endl;
    obj.traverse();
}