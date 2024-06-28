#include  <iostream>
#define tablesize 20
using namespace std;

class Node
{
    public:
    string val;
    Node* next;
    Node(string v){
        val = v;
        next = NULL;
    }
};

class Linkedlist
{
    Node* head;
    unsigned int count;
    public:
        Linkedlist(){head = NULL;count = 0;}
        void insert(string v){
            count++;
            Node* temp = head;
            Node* new_node = new Node(v);
            if (head==NULL){
                head = new_node;
            }
            else{
                while (temp->next!=NULL)
                temp = temp->next;
                temp->next = new_node;
            }
        }
        bool search(string key){
            Node* temp = head;
            if (head==NULL){return false;}
            else{
                while(temp!=NULL){
                    if (temp->val==key){
                        return true;
                    }
                    temp = temp->next;
                }
            }
            return false;
        }
        int get_count(){return count;}
        void traverse(){
            Node* temp = head;
            if (head==NULL){
                cout<<"NULL";
            }
            else{
                while (temp!=NULL){
                    cout<<temp->val<<" ";
                    temp = temp->next;
                }
            }
        }
        
};

class hashtable
{
    Linkedlist* table;
    public:
        hashtable(){table = new Linkedlist[tablesize];}
        int h(string key){
            int sum = 0;
            for (int i = 0; i < key.size(); i++)
            {
                sum+=key[i];
            }
            sum+=17;            //because 20k-0177 = 2+0+0+1+7+7 = 17
            return (sum%tablesize);
        }
        void add_entry(string key){
            int index = h(key);
            table[index].insert(key);
            cout<<"Value is inserted"<<endl;
        }
        bool search(string key){
            int index = h(key);
            return (table[index].search(key));

        }
        void traverse(){
            for (int i = 0; i < tablesize; i++)
            {
                table[i].traverse();
                cout<<endl;
            }
            
        }
};

int main(){
        hashtable obj;
        string temp;
        for (int i = 0; i < 10; i++)
        {
            cin>>temp;
            obj.add_entry(temp);
        }
        string x = "Easy";
        if (obj.search(x)){
            cout<<"Element is present"<<endl;
        }
        else{
            cout<<"Element not found"<<endl;
        }
        obj.traverse();


        
        
}