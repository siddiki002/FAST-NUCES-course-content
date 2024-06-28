#include <iostream>

using namespace std;
class base
{
    int x;
    public:
         void func(){
            cout<<"Base class function is called"<<endl;
        }
};
class derive : public base
{
    int y;
    public:
        virtual void func(){
            cout<<"Derived class function is called"<<endl;
        }
};
int main()
{
    // downcasting
    base obj;
    derive *dptr = (derive*)&obj;
    dptr->func();
    // upcasting
    base *bptr;
    derive dobj;
    bptr = &dobj;
    bptr->func();
    
}