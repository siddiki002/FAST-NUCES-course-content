#include <iostream>
#include <string>
using namespace std;

class stack
{
    int top;
    int* array;
    unsigned int size;
    public:
        stack(int n){
            array =  new int[n];
            top = -1;
            size = n;
        }
        bool is_full(){
            return (top==size-1);
        }
        bool is_empty(){
            return (top==-1);
        }
        void push(int val){
            if (is_full()){
                cout<<"Stack overflow"<<endl;
            }
            else
            {
                array[++top] = val;
            }
        }
        int pop(){
            if (is_empty()){
                cout<<"Stack underflow"<<endl;
            }
            else{
                return array[top--];
            }
        }
};
int evaluate_postfix(string str)
{
    stack obj(str.size());
    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
        {
            obj.push(str[i]-48);
        }
        else
        {
            switch (str[i]){
                int a,b,c;
                case '+':
                    a = obj.pop();
                    b = obj.pop();
                    c = a+b;
                    obj.push(c);
                    break;
                case '-':
                    a = obj.pop();
                    b = obj.pop();
                    c = a-b;
                    obj.push(c);
                    break;
                case '*':
                    a = obj.pop();
                    b = obj.pop();
                    c = a*b;
                    obj.push(c);
                    break;
                case '/':
                    a = obj.pop();
                    b = obj.pop();
                    c = b/a;
                    obj.push(c);
                    break;
            }
        }
    }
    return (obj.pop());
    
}
int main()
{
    string str;
    getline(cin,str);
    //stack obj(str.size());
    int ans = evaluate_postfix(str);
    cout<<"The answer is: "<<ans<<endl;
}