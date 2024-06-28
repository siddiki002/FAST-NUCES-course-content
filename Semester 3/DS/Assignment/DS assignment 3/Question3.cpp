#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
    public:
        int val;
        Node* right;
        Node* left;
        Node(int v){
            val = v;
            right=left=NULL;
        }
};
class BSTree
{
    Node* root;
    public:
         BSTree(){
            root = NULL;
        }
        void input(int val){
            if (root==NULL){
                root = new Node (val);
                return;
            }
            else{
                Node *current = root;
                Node *parent = NULL;
                while(current!=NULL){
                    if (val < current->val)
                    {
                        parent = current;
                        current = current->left;
                    }
                    else
                    {
                        parent = current;
                        current = current->right;
                    }
                }
                if (val < parent->val){
                    parent->left = new Node (val);
                }
                else
                {
                    parent->right = new Node (val);
                }
            }
        }
        int find_min(queue<Node*> q){
            if (!q.empty()){
                Node* temp = q.front();
                int min = temp->val;
                q.pop();
                while(!q.empty()){
                    temp = q.front();
                    if (min>temp->val){
                        min = temp->val;
                    }
                    q.pop();
                }
                return min;
            }
            
        }
        int find_max(queue<Node*> q){
            if (!q.empty()){
                Node* temp = q.front();
                int max = temp->val;
                q.pop();
                while(!q.empty()){
                    temp = q.front();
                    if (max<temp->val){
                        max = temp->val;
                    }
                    q.pop();
                }
                return max;
            }
        }
        void bfs_min_max(vector <int> &min, vector<int> &max){
            if (root==NULL){
                return;
            }
            else{
                queue<Node*> q;
                q.push(root);
                min.push_back(root->val);
                max.push_back(root->val);
                while(!q.empty()){
                    Node* temp = q.front();
                    int min_val = find_min(q);
                    int max_val = find_max(q);
                    if (min.back()!=min_val){
                        min.push_back(min_val);
                    }
                    if (max.back()!=max_val){
                        max.push_back(max_val);
                    }
                    q.pop();
                    if (temp->left!=NULL){
                        q.push(temp->left);
                    }
                    if (temp->right!=NULL){
                        q.push(temp->right);
                    }
                    
                }
            }
        }
        
        int get_height(Node* root){
            if (root==NULL){
                return 0;
            }
            else{
                int l_height = get_height(root->left);
                int r_height = get_height(root->right);

                if (l_height>r_height){
                    return l_height + 1;
                }
                else{
                    return r_height + 1;
                }
            }
        }
        int find_height(){
            return get_height(root);
        }
        
       
        
};

int main(){
    BSTree obj;
    int num,iter;
    cin>>iter;
    vector<int> max;
    vector<int> min;
    for (int i = 0; i < iter; i++)
    {
        cin>>num;
        obj.input(num);
    }
    obj.bfs_min_max(min,max);
    for (int i = 0;  i<obj.find_height(); i++)
    {
        cout<<min[i]<<" "<<max[i]<<endl;
    }
    max.erase(max.begin(),max.end());
    min.erase(min.begin(),min.end());
    
}