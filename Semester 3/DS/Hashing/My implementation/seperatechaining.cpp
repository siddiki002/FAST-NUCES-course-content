#include <iostream>
#define tablesize 20
using namespace std;

class Node
{
    public:
    int val,key;
    Node* next;
    Node(int v, int k){
        val = v;
        key = k;
        next = NULL;
    }
};

class LinkedList
{
    public:
        Node* head;
        LinkedList(){
            head = NULL;
        }
        void insert(int key, int val){
            if (head==NULL){
                Node* new_node = new Node(val,key);
                head = new_node;
            }
            else{
                Node* current = head;
                while (current->next!=NULL){
                    current = current->next;
                }
                Node* new_node = new Node(val,key);
                current->next = new_node;
            }
        }
        int search(int to_search){
            if (head!=NULL){
                Node* current = head;
                while (current!=NULL){
                    if (current->key==to_search){
                        return (current->val);
                    } 
                    current = current->next;
                }
            }
            //cout<<"Element not found"<<endl;
            return -1;
        }
};

class hashtable
{
    LinkedList* hash_t = new LinkedList[tablesize];
    public:
        int h(int k){
            return (k%tablesize);
        }
        void insert(int key, int val){
            int index = h(key);
            hash_t[index].insert(key,val);
            cout<<"Value inserted in table"<<endl;
        }
        int search(int key){
            int index = h(key);
            return(hash_t[index].search(key));
        }
};

int main(){
    hashtable obj;
    obj.insert(3,56);
    obj.insert(11,4);
    obj.insert(61,4);
    obj.insert(20,11);
    obj.insert(40,13);
    if (obj.search(40)!=-1){
        cout<<obj.search(40)<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
}