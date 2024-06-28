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
                        if(isupper(temp->value[0]))
                        {
                            
                            if (isupper(iterator->value[0]))
                            {
                                // cout<<"Temp is upper iterator is upper called: "<<endl;
                                // system("PAUSE");
                                if (temp->value[0]+32>iterator->value[0]+32)
                                {
                                    swap_string(temp->value,iterator->value);
                                }
                                else if (temp->value[0]+32==iterator->value[0]+32)
                                {
                                    
                                    for (int i = 1,j=1; i < temp->value.size(),j<iterator->value.size(); i++,j++)
                                    {
                                        if(temp->value[i]+32>iterator->value[j]+32)
                                        {
                                            swap_string(temp->value,iterator->value);
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (islower(iterator->value[0]))
                                {
                                    // cout<<"Temp is upper iterator not upper called: "<<endl;
                                    // system("PAUSE");
                                    if (temp->value[0]+32>iterator->value[0])
                                    {
                                        swap_string(temp->value,iterator->value);
                                    }
                                    else if (temp->value[0]+32==iterator->value[0])
                                    {
                                        for (int i = 1,j=1; i < temp->value.size(),j<iterator->value.size(); i++,j++)
                                        {
                                            if(temp->value[i]+32>iterator->value[j])
                                            {
                                                swap_string(temp->value,iterator->value);
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        //both are small
                        else if(islower(temp->value[0]) && islower(iterator->value[0]))
                        {
                            // cout<<"Temp is lower iterator is lower called: "<<endl;
                            // system("PAUSE");
                            if (temp->value[0]>iterator->value[0])
                            {
                                swap_string(temp->value,iterator->value);
                            }
                            else if (temp->value[0]==iterator->value[0])
                            {
                                if(temp->value.size()>iterator->value.size())
                                {
                                    swap(temp->value,iterator->value);
                                }
                                for (int i = 1,j=1; i < temp->value.size(),j<iterator->value.size(); i++,j++)
                                {
                                    if(temp->value[i]>iterator->value[j])
                                    {
                                        swap_string(temp->value,iterator->value);
                                        break;
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
void swap_string(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
} 
void make_upper(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        int temp = s[i];
        if (temp>96)
        {
            s[i] = s[i] - 32;
        }
    }
    
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
    obj1.sort_ascending();
    obj1.delete_repetition();
    obj1.traverse();
    system("PAUSE");
    obj1.sort_ascending();
    obj1.traverse();
}