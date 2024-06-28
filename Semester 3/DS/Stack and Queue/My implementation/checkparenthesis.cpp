#include <iostream>

using namespace std;

class stack
{
    int top;
    char* array;
    public:
        stack(){top = -1;}
        stack(int n)
        {
            top = -1;
            array = new char[n];
        }
        bool is_empty(){
            return (top==-1);
        }
        bool is_full(){
            return (top==sizeof(array)-1);
        }
        void push(char ch){
            if (is_full()){
                cout<<"Stack overflow"<<endl;
            }
            else
            {
                array[++top] = ch;
            }
        }
        char pop()
        {
            if (is_empty()){
                cout<<"Stack underflow"<<endl;
                return CHAR_MIN;
            }
            else
            {
                return (array[top--]);
            }
        }
};

bool isbalance(stack &obj, string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i]=='(' || str[i]=='[' || str[i]=='{')
        {
            obj.push(str[i]);
        }
        else if (str[i]==')' || str[i]==']' || str[i]=='}')
        {
            if (obj.is_empty()){return false;}
            switch(str[i]){
                case ')':
                    if (obj.pop() != '('){
                      return false;  
                    }
                    else
                    break;
                case ']':
                    if (obj.pop() != '[')
                    return false;
                    else
                    break;
                case '}':
                    if (obj.pop() != '{')
                    return false;
                    else
                    break;
            }
        }
    }
    if (!obj.is_empty()){
        return false;
    }
    return true;
    
}

int main()
{
    string str = "(a+b) + (c+d))";
    stack obj(str.size());
    if (isbalance(obj,str)){
        cout<<"Balanced"<<endl;
    }
    else
    {
        cout<<"Not balanced"<<endl;
    }
}