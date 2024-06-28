#include <iostream>
#define size 100
using namespace std;

class doublequeue
{
    int* array;
    int Lptr,Rptr,Lrear,Rrear;
    public:
        doublequeue(){
            array = new int[size];
            Lrear = Lptr = (size/2)-1;
            Rrear = Rptr = (size/2);
        }
        void enqueue(int Qnum, int val)     //Qnum = 0 is Left , Qnum = 1 is right
        {
            if (Qnum){
                //right queue
                if (Rrear==Rptr){
                    array[Rrear] = val;
                    Rrear++;
                }
                else{
                    array[Rrear++] = val;
                }
            }
            else{
                if (Lrear==Lptr){
                    array[Lrear] = val;
                    Lrear--;
                }
                else{
                    array[Lrear--] = val;
                }
            }
        }
        int dequeue (int Qnum){
            if (Qnum){
                return(array[Rptr++]);
            }
            else{
                return (array[Lptr--]);
            }
        }
        int top(int Qnum){
            if (Qnum){
                return(array[Rptr]);
            }
            else{
                return (array[Lptr]);
            }
        }
        bool is_full(){
            if (Lrear==-1 && Rrear==size){
                return true;
            }
            return false;
        }
        bool is_empty(){
            return(Lrear==Lptr && Rrear==Rptr);
        }
};

int main()
{
    doublequeue obj;
    for (int i = 0; i < 50; i++)
    {
        obj.enqueue(0,i+1);
    }
    for (int i = 0; i < 50; i++)
    {
        obj.enqueue(1,i+2);
    }
    cout<<obj.dequeue(0)<<endl<<obj.dequeue(1)<<endl;
    // if(obj.is_full()){
    //     cout<<"Full"<<endl;
    // }
    
    
}