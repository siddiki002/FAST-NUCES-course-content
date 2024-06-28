#include <iostream>

using namespace std;

class queue
{
    int front,rear,size;
    unsigned int capacity;
    int* array;
    public:
        queue(int c)
        {
            if (c>0)
            {
                size = -1;
                capacity = c;
                front = 0;
                rear = capacity - 1;
                array = new int[c]{0};
            }
            else
            {
                cout<<"Invalid capacity"<<endl;
            }
        }
        void insert(int n)
        {
            if(size==capacity)
            {
                cout<<"Capacity reached"<<endl;
            }
            else
            {
                size++;
                array[size] = n;
            }
        }
        bool Queuecapacity()
        {
            return (size>=capacity);
        }
        void remove_member()
        {
            if (size>-1)
            {
                cout<<endl<<"Element getting removed is: "<<array[front]<<endl;
                size--;
                for (int i = 0; i < capacity-1; i++)
                {
                    array[i] = array[i+1];
                }
                cout<<"Element removed"<<endl;
            }
            else
            {
                cout<<"Queue already empty"<<endl;
            }
        }
        void traverse()
        {
            if(size>-1)
            {
                for (int i = 0; i <= size; i++)
                {
                    cout<<array[i]<<" ";
                }
            }
            else
            {
                cout<<"Queue empty"<<endl;
            }
        }
        bool is_empty()
        {
            return (size==-1);
        }
        ~queue()
        {
            delete [] array;
            array = nullptr;
        }
};

int main()
{
    queue obj(10);
    for (int i = 0; i < 4; i++)
    {
        obj.insert(i+3);
    }
    obj.traverse();
    obj.remove_member();
    obj.remove_member();
    obj.remove_member();
    obj.remove_member();
    obj.remove_member();
    //obj.traverse();
    
}