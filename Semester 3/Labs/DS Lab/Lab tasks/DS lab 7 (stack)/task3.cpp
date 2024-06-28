#include <iostream>
#include <string>

using namespace std;
class stack{
    int top;
    int size;
    char *array;
    public:
        stack(int n){
            top = -1;
            array = new char[n];
            size = n;
        }
        void push(char ch){
            if (top<size){
                array[++top] = ch;
            }
        }
        char pop(){
            char temp;
            if (top>-1){
                return array[top--];
            }
        }
        char peek(){
            if (top>-1){
                return array[top];
            }
            else{
                cout<< "Stack empty"<<endl;
            }
        }
        bool isempty(){
            return(top==-1);
        }
};
int precidence(char ch)
{
    if (ch=='^'){
        return 3;
    }
    else if(ch=='*'||ch=='/'){
        return 2;
    }
    else if(ch=='+'||ch=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infixtopostfix(string input){
    stack expression(input.length());
    string output = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (isalpha(input[i])){
            output+= input[i];
        }
        else if(input[i]=='('){
            expression.push(input[i]);
        }
        else if (input[i]=='^'){
            expression.push(input[i]);
        }
        else if (input[i]==')'){
            while(expression.peek()!='('){
                output+=expression.pop();
            }
            expression.pop();
        }
        else
        {
           while(!expression.isempty() && precidence(input[i])<=precidence(expression.peek())){
               output+=expression.pop();
           }
        expression.push(input[i]);
        }
   
    }
    while (!expression.isempty())  
    {
            output+=expression.pop();
    }
    return output;
    
}
int main()
{
    string input;
    getline(cin,input);
    string output = infixtopostfix(input);
    cout<<output<<endl;
}