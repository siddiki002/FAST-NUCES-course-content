#include <iostream>

using namespace std;

class priority_queue
{
    int front,end,size;
    unsigned int capacity;
    int* array;
    public:
        priority_queue(int c)
        {
            if (c>0)
            {
                capacity = c;
                front = 0;
                end = capacity-1;
                size = -1;
                array = new int[c];
            }
            else
            {
                cout<<"Invalid capacity"<<endl;
            }
        }
        void add(int n)
        {
            if (size==capacity)
            {
                cout<<"Capacity reached"<<endl;
            }
            else
            {
                
                size++;
                //cout<<size<<endl;
                if (size==0)
                {
                    array[size] = n;
                }
                else if (array[front]>n)
                {
                    //int key = n;
                    for (int i = size; i >= front; i--)
                    {
                        array[i+1] = array[i];
                    }
                    array[front] = n;
                }
                else
                {
                    
                    for (int i = 0; i < size; i++)
                    {
                        if (array[i]>n)
                        {
                            //cout<<"if worked"<<endl;
                            //int key = array[i];
                            for (int j = size-1; j >= i; j--)
                            {
                                array[j+1] = array[j];
                            }
                            array[i] = n;
                            break; 
                        }
                        else if (i==size-1)
                        {
                            array[size] = n;
                        }
                    }
                }
            }
        }
        void pop()
        {
            if(size>-1)
            {
                cout<<"Element popped is: "<<array[size--]<<endl;
            }
            else
            {
                cout<<"Queue empty"<<endl;
            }
        }
        void traverse()
        {
            if (size>-1)
            {
                for (int i = 0; i <= size; i++)
                {
                    cout<<array[i]<<endl;
                }
            }
            else{
                cout<<"Queue empty"<<endl;
            }
        }
};

int main()
{
    priority_queue obj(8);
    obj.add(13);
    obj.add(12);
    obj.add(1);
    obj.add(0);
    obj.add(17);
    obj.add(11);
    obj.add(10);
    obj.pop();
    obj.traverse();
}