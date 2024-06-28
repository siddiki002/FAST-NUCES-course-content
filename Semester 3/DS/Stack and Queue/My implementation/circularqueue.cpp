#include <iostream>
#define max_size 10
using namespace std;

template <class X>
class circularqueue
{
    int front,rear;
    unsigned int size;
    X* array;
    public:
        circularqueue()
        {
            front = rear = -1;
            array = new X[max_size];
            size = 0;
        }
        bool is_full(){
            return ((rear+1) % max_size == front);
        }
        bool is_empty()
        {
            return (front==-1 && rear==-1);
        }
        X dequeue()
        {
            if (is_empty()){
                cout<<"Queue is empty"<<endl;
                exit(0);
            }
            else if (rear==front)
            {
                size--;
                X temp = array[rear];
                front = rear = -1;
                return temp;
            }
            else
            {
                size--;
                X temp = array[front];
                front = (front + 1)%max_size;
                return temp;
            }
        }
        void enqueue(X val)
        {
            if (is_full()){
                cout<<"Queue is full"<<endl;
                return;
            }
            else if (is_empty())
            {
                size++;
                front = rear = 0;
                array[front] = val;
            }
            else
            {
                size++;
                rear = (rear+1) % max_size;
                array[rear] = val;
            }
        }
        int get_size(){return size;}
        void traverse(){
            if (is_empty()){
                cout<<"Queue is empty"<<endl;
                return;
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    cout<<array[i]<<" ";
                }
                
            }
        }
};

int main()
{
    circularqueue <int> obj;
    for (int i = 0; i < 10; i++)
    {
        obj.enqueue(i+1);
    }
    obj.traverse();
    obj.dequeue();
    obj.enqueue(15);
    obj.traverse();
    
}