#include <iostream>

using namespace std;

template <class X>
class DynamicSafeInt
{
    X *arr;
    int size;
    public:
        DynamicSafeInt(){}
        DynamicSafeInt(int size)
        {
            arr = new X[size];
            this->size = size;
        }
        void input()
        {
            cout<<"Enter values"<<endl;
            for (int i = 0; i < size; i++)
            {
                cin>>arr[i];
            }
            
        }
        bool operator ==(DynamicSafeInt &obj)
        {
            if (size==obj.size)
            {
                for (int i = 0; i < size; i++)
                {
                    if (arr[i]!=obj.arr[i])
                    {
                        return false;
                    }
                }
                
            }
            else
            {
                return false;
            }
            return true;
        }
};

int main()
{
    DynamicSafeInt <int>obj1(5),obj2(5);
    obj1.input();
    obj2.input();
    if (obj1==obj2)
    {
        cout<<"Both arrays are equal"<<endl;
    }
    else
    {
        cout<<"Arrys are not equal"<<endl;
    }
}