#include <iostream>
#include <string>
using namespace std;
class Node
{
    public:
    string value;
    Node* next;
    Node* prev;
    Node(string s)
    {
        value = s;
        next =  NULL;
        prev = NULL;
    }
};
void swap_string(string &a, string &b);
string make_lower(string s);
bool is_subsequence(string temp, string itr);
class doublylinkedlist
{
    Node* head;
    public:
        doublylinkedlist()
        {
            head = NULL;
        }
        void add_node(string s)
        {
            Node* temp = head;
            Node* new_node = new Node(s);
            if (head==NULL)
            {
                head = new_node;
                new_node->prev = head;
            }
            else
            {
                while(temp->next!=NULL)
                {
                    temp = temp->next;
                }
                new_node->prev = temp;
                temp->next = new_node;
            }
        }
        void delete_repetition()
        {
            Node* temp = head;
            if (head==NULL)
            {
                cout<<"Linked list not started"<<endl;
            }
            else
            {
                while(temp->next!=NULL)
                {
                    Node* iterator = temp->next;
                    while(iterator!=NULL)
                    {
                        // cout<<"Temp: "<<temp->value<<endl<<"iterator: "<<iterator->value<<endl;
                        // system("PAUSE");
                        if(temp->value==iterator->value)
                        {
                            Node* to_delete = iterator;
                            if (iterator->next!=NULL)
                            {
                                iterator->prev->next = iterator->next;
                                iterator->next->prev = iterator->prev;
                            }
                            else
                            {
                                iterator->prev->next = iterator->next;
                            }
                            iterator = iterator->next;
                            delete to_delete;
                        }
                        else
                        {
                            iterator = iterator->next;
                        }
                    }
                    if(temp->next!=NULL)
                    {
                        temp = temp->next;
                    }
                    
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
                        // cout<<"Temp: "<<temp->value<<endl<<"Iterator: "<<iterator->value<<endl;
                        // system("PAUSE");
                        string str_temp = make_lower(temp->value);
                        string str_itr = make_lower(iterator->value);
                        // checking if first is greater than second
                        if (str_temp[0]>str_itr[0])
                        {
                            swap_string(temp->value,iterator->value);
                        }
                        else if (str_temp.size()>str_itr.size() && is_subsequence(temp->value,iterator->value))
                        {
                            swap_string(temp->value,iterator->value);
                        }
                        else if(str_temp[0]==str_itr[0])
                        {
                            int flag = 0;
                            for (int i = 1, j = 1; i < str_temp.size()-1, j< str_itr.size()-1; i++,j++)
                            {
                                if (str_temp[i]>str_itr[i])
                                {
                                    if (flag==0)
                                    {
                                        // cout<<"Swap string called: "<<endl;
                                        // system("PAUSE");
                                        swap_string(temp->value,iterator->value);
                                        flag = 1;
                                    }
                                }
                            }
                            
                        }
                        
                        iterator = iterator->next;
                    }
                    temp = temp->next;
                    
                }
                
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
                    cout<<temp->value<<endl;
                    temp = temp->next;     
                }
               
            }
        }
};
bool is_subsequence(string temp, string itr)
{
    for (int i = 0; i < itr.size(); i++)
    {
        if (temp[i]!=itr[i])
        {
            return false;
        }
    }
    return true;
    
}
void swap_string(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
} 
string make_lower(string s)
{
    string temp = s;
    for (int i = 0; i < temp.size(); i++)
    {
        if (isupper(temp[i]))
        {
            temp[i]+=32;
        }
    }
    return temp;
    
} 
int main()
{
    doublylinkedlist obj1;
    string str;
    getline(cin,str);
    
    for (int i = 0; i < str.size(); i++)
    {
        string temp = "";
        if (str[i]!=' ')
        {
            int j = i;
            while(str[j]!=' ')
            {
                if (j==str.size()-1)
                {
                    temp+=str[j];
                    break;
                }
                temp+= str[j];
                j++;
            }
            i = j;
            //make_upper(temp);
            obj1.add_node(temp);
        }
    }
    //obj1.sort_ascending();
    obj1.delete_repetition();
    obj1.traverse();
    // obj1.traverse();
    // system("PAUSE");
    //obj1.sort_ascending();
    obj1.sort_ascending();
    obj1.traverse();
}