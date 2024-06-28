#include <iostream>
#define max_size 10
using namespace std;
template <class X>
class queue
{
    int front,rear;
    //unsigned int size;
    X* array;
    public:
        queue(){
            front = rear = -1;
            //size = 0;
            array = new X[max_size];
        }
        bool is_full(){
            return (rear==max_size-1);
        }
        bool is_empty(){
            return (front==-1 && rear==-1);
        }
        void enqueue(X val){
            if (is_full()){
                cout<<"Queue is full"<<endl;
                return;
            }
            else
            {
                //size++;
                if (is_empty()){
                    front = rear = 0;
                    array[rear] = val;
                }
                else
                {
                    array[++rear] = val;
                }
            }
        }
        X dequeue(){
            if (is_empty()){
                cout<<"Queue is empty";
                exit(0);
            }
            // checking if there is only 1 element in the queue then we need to reset the queue
            else if (rear==front){
                X temp = array[front];
                rear = front = -1;
                return temp;
            }
            else
            {
                return array[front++];
            }
        }
        int get_size()
        {
            if (is_empty()){
                return 0;
            }
            return (rear-front + 1);
        }
};

int main()
{
    queue <int> obj;
    obj.enqueue(1);
    obj.enqueue(3);
    obj.enqueue(15);
    cout<<obj.get_size()<<endl;
    cout<<obj.dequeue()<<" "<<obj.dequeue()<<" "<<obj.dequeue()<<endl;
    cout<<obj.get_size();
}