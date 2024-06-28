#include <iostream>
#include <string>
#include <vector>
using namespace std;
class LLNode
{
    public:
        string val;
        LLNode* next;
        LLNode(string v){
            val = v;
            next = NULL;
        }
};



class LinkedList
{
    LLNode* head;
    public:
        LinkedList(){
            head = NULL;
        }
        void insert(string T){
            if (head==NULL){
                LLNode* new_node = new LLNode(T);
                head = new_node;
            }
            else{
                LLNode* temp = head;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                
                if (temp->val!=T){
                    LLNode* new_node = new LLNode(T);
                    temp->next = new_node;
                }
                
            }
        }
        string get_head(){
            return(head->val);
        }
        void traverse(){
            LLNode* temp = head;
            while(temp!=NULL){
                cout<<temp->val<<" ";
                temp=temp->next;
            }
        }
        void delete_repetition(){
            LLNode* temp = head;
            LLNode* iterator = NULL;
            LLNode* prev=NULL;
            while(temp->next!=NULL){
                prev = temp;
                iterator = temp->next;
                while (iterator!=NULL){
                    if (temp->val==iterator->val){
                        prev->next = iterator->next;
                        LLNode* to_delete = iterator;
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
};
class BTNode
{
    public:
        string val;
        BTNode* right;
        BTNode* left;
        LinkedList l_number;
        BTNode(string v){
            val = v;
            right=left=NULL;
        }
};


class BSTree
{
        BTNode* root;
        bool is_same(int index,string str1,string str2){
            //str1 is the Tree value
            for (int i=0,j=index;i<str1.size();i++,j++){
                if (str1[i]!=str2[j]){
                    return false;
                }
            }
            return true;
        }
    public: 
        BSTree(){
            root = NULL;
        }
        void push(string T){
            BTNode* new_node = new BTNode(T);
            if (root==NULL){
                root = new_node;
            }
            else{
                BTNode* current = root;
                BTNode* parent = NULL;
                while (current!=NULL){
                    if (current->val>T){
                        parent = current;
                        current = current->left;
                    }
                    else{
                        parent = current;
                        current = current->right;
                    }
                }
                if (parent->val>T){
                    parent->left = new_node;
                }
                else{
                    parent->right = new_node;
                }
            }
        }
        void search(BTNode* root, string str, string line){
            if (root==NULL){
                return;
            }
            else{
                for (int i = 0; i < str.size(); i++)
                {
                    if (root->val[0]==str[i]){
                        if (is_same(i,root->val,str)){
                            root->l_number.insert(line);
                        }
                    }
                }
                search(root->left,str,line);
                search(root->right,str,line);
            }
            
            
        }
        void search_tree(string str, string line){
            search(root,str,line);
        }
       
        void inorder(BTNode* root){
            if (root==NULL){
                return;
            }
            inorder(root->left);
            cout<<root->val<<" ";
            root->l_number.traverse();
            cout<<endl;
            inorder(root->right);
        }
        void traverse_inorder(){
            inorder(root);
        }
};

int main(){
    BSTree obj;
    int n,n1;
    cin>>n;
    n+=1;
    vector<string> v1;
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin,s);
        v1.push_back(s);
    }
    v1.erase(v1.begin(),v1.begin()+1);
    for (int i = 0; i < v1.size(); i++)
    {
        obj.push(v1[i]);
    }
    fflush(stdin);
    vector <string> v;
    cin>>n1;
    n1+=1;
    for (int i = 0; i < n1; i++)
    {
        string s;
        getline(cin,s);
        v.push_back(s);
    }
    v.erase(v.begin(),v.begin()+1);
    for (int i = 0; i < v.size(); i++)
    {
        string s = v[i];
        string line="";
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j]==' '){
                break;
            }
            line += s[j];
        }
        obj.search_tree(s,line);
        
    }
    obj.traverse_inorder();
}