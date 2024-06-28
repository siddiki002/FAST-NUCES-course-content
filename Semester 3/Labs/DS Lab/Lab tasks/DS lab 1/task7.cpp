#include <iostream>

using namespace std;

class Numbers
{
    private:
        int *ptr;
    public:
    Numbers()
    {
        ptr = new int;
    }
    void set_value(int n)
    {
        *ptr = n;
    }
    Numbers(const Numbers &obj)
    {
        ptr = new int;
        *ptr = *(obj.ptr);
    }
    ~Numbers()
    {
        delete ptr;
        ptr = nullptr;
    }
    void show()
    {
        cout<<"The value saved is "<<*ptr<<endl;
    }
};

int main()
{
    Numbers n1,n2;
    n1.set_value(4);
    n2 = n1;
    n2.show();
}