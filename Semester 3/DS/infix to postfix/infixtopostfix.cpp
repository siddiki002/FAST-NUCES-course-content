#include <iostream>
#include <string>

using namespace std;

int precedence(char ch){
    if (ch=='+' || ch=='-'){
        return 1;
    }
    else if (ch=='*' || ch=='/'){
        return 2;
    }
    return -1;
}
class stack
{
    int top;
    char* array;
    unsigned int size;
    public:
        stack (int n){
            size = n;
            array = new char[n];
            top = -1;
        }
        bool is_full(){
            return (top==size-1);
        }
        bool is_empty(){
            return (top==-1);
        }
        void push(char ch){
            if (is_full()){
                cout<<"Stack overflow"<<endl;
            }
            else{
                array[++top] = ch;
            }
        }
        char peek(){
            if(is_empty()){
                cout<<"Stack underflow"<<endl;
                exit(0);
            }
            else{
                return array[top];
            }
        }
        char pop(){
            if(is_empty()){
                cout<<"Stack underflow"<<endl;
               exit(0);
            }
            else{
                return array[top--];
            }
        }
};

string infixtopostfix(string infix)
{
    string postfix = "";
    stack obj(infix.size());
    for (int i = 0; i < infix.size(); i++)
    {
        if(isalpha(infix[i]) || isdigit(infix[i]))
        {
            postfix+=infix[i];
        }
        else if(infix[i]=='('){
            obj.push(infix[i]);
        }
        else if (infix[i]==')'){
            while(obj.peek()!='('){
                postfix+=obj.pop();
            }
            obj.pop();
        }
        else
        {
            while (!obj.is_empty() && precedence(obj.peek())>=precedence(infix[i]))
            {
                postfix+=obj.pop();
            }
            obj.push(infix[i]);
        }
    }
    while(!obj.is_empty()){
        postfix+=obj.pop();
    }
    return postfix;
}

int main()
{
    string str;
    getline (cin,str);
    string ans = infixtopostfix(str);
    cout<<ans<<endl;
}