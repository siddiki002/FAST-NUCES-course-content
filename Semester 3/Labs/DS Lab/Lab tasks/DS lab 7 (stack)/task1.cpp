#include <iostream>

using namespace std;

class stack
{
    int top;
    int *array;
    int size;
    public:
        stack(int n){
            size = n;
            array = new int[n];
            top = -1;
        }
        void push(int n)
        {
            if (top<size-1){
                array[++top] = n;
            }
            else
            {
                cout<<"Stack overflow"<<endl;
            }
        }
        int pop()
        {
            if (top>-1){
                return (array[top--]);
            }
            else
            {
                cout<<"Stack underflow"<<endl;
            }
            return -1;
        }
        int peek()
        {
            if (top>-1){
                return (array[top]);
            }
            else
            {
                cout<<"Stack underflow"<<endl;
            }
        }

};

int main()
{
    stack obj(5);
    for (int i = 0; i < 5; i++)
    {
        obj.push(i+2);
    }
    // obj.push(12);
    // obj.push(14);
    // obj.push(11);
    for (int i = 0; i < 5; i++)
    {
        obj.pop();
    }
    obj.pop();
    
    
}