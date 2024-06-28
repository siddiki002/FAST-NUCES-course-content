#include <iostream>
#include <stack>
using namespace std;

class Node{
    public:
        char val;
        Node* right;
        Node* left;
        Node(){
            right = NULL;
            left = NULL;
        }
        Node(char v){
            val = v;
            right = NULL;
            left = NULL;
        }
        void insert_childs(char rc, char lc){
            right->val = rc;
            left->val = lc;
        }
};

class expressiontree
{
    Node* root;
    public:
        expressiontree(){root=NULL;}
        void insert_root(Node* r){
            root = r;
        }
        void inorder(Node* root){
            if (root==NULL){
                return;
            }
            inorder(root->left);
            cout<<root->val<<" ";
            inorder(root->right);
        }
        void call_inorder(){
            inorder(root);
        }
};

int main(){
    stack<Node*> s;
    string str = "ABC*+D/";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
            Node *temp = new Node(str[i]);
            Node* rc = s.top();
            s.pop();
            Node* lc = s.top();
            s.pop();
            temp->left = lc;
            temp->right = rc;
            s.push(temp);

        }
        else{
            Node* temp = new Node(str[i]);
            s.push(temp);
        }
    }
    Node* temp = s.top();
    s.pop();
    expressiontree obj;
    obj.insert_root(temp);
    obj.call_inorder();

}