#include <iostream>

using namespace std;

template <class X>
class stack
{
    X* array;
    int top;
    public:
        stack(){
            top = -1;
        }
        stack (int n){
            top = -1;
            array = new X[n];
        }
        bool is_empty(){
            return (top==-1);
        }
        bool is_full(){
            return (top==sizeof(array)-1);
        }
        void push(X n){
            if (is_full()){
                cout<<"Stack overflow"<<endl;
            }
            else
            {
                array[++top] = n;
            }
        }
        X peek(){
            if (!is_empty()){
                return (array[top]);
            }
           exit(0);
        }
        X pop(){
            if (is_empty()){
                cout<<"Stack underflow"<<endl;
                exit(0);
            }
            else
            {
                return array[top--];
            }
        }
        void print_stack(){
            if (is_empty()){
                cout<<"Stack empty"<<endl;
            }
            else
            {
                for(int i=top;i>-1;i--){
                    cout<<array[i]<<" ";
                }
            }
        }
};
stack <int> sort_stack(stack <int> rhs)
{
    stack <int> stack1(8);
    stack <int> stack2(8);
    while(!rhs.is_empty()){
        stack2.push(rhs.pop());
        while(!rhs.is_empty()){
            int a = rhs.pop();
            if (a<stack2.peek()){
                int b = stack2.pop();
                stack1.push(b);
                stack2.push(a);
            }
            else{
                stack1.push(a);
            }
        }
        while(!stack1.is_empty()){
            int x = stack1.pop();
            rhs.push(x);
        }
    }
    rhs.print_stack();
    system("PAUSE");
    stack1.print_stack();
    system("PAUSE");
    stack2.print_stack();
    system("PAUSE");
    return stack2;
}
int main()
{
    stack <int> obj(8);
    
    obj.push(3);
    obj.push(1);
    obj.push(5);
    obj.push(10);
    obj.push(11);
    obj.push(15);
    stack<int> temp(8);
    temp = sort_stack(obj);
    while(!temp.is_empty()){
        cout<<temp.pop()<<" ";
    }
}