#include <iostream>
#include <stack>
using namespace std;


stack<int> sort_stacks(stack<int> stack1, stack<int> stack2){
    stack<int> temp_stack;
    while (!stack1.empty() && !stack2.empty()){
        int min = stack1.top();
        if (min>stack2.top()){
            temp_stack.push(stack2.top());
            stack2.pop();
        }
        else{
            temp_stack.push(min);
            stack1.pop();
        }
    }
    if (!stack1.empty()){
        while (!stack1.empty()){
            temp_stack.push(stack1.top());
            stack1.pop();
        }
    }
    else if (!stack2.empty()){
        while(!stack2.empty()){
            temp_stack.push(stack2.top());
            stack2.pop();
        }
    }
    stack<int> stack3;
    while(!temp_stack.empty()){
        stack3.push(temp_stack.top());
        temp_stack.pop();
    }
    return (stack3);
}

int main(){
    stack<int> stack1;
    stack<int> stack2;
    for (int i = 20; i > 0; i-=2)
    {
        stack1.push(i);
    }
    for (int i = 40; i > 20; i-=2)
    {
        stack2.push(i);
    }
    stack<int> ans_stack = sort_stacks(stack1,stack2);
    while(!ans_stack.empty()){
        cout<<ans_stack.top()<<" ";
        ans_stack.pop();
    }
    
}