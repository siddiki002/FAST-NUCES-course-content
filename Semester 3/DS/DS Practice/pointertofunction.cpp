#include <iostream>
using namespace std;
void fun()
{
    cout<<"Hello world"<<endl;
}
int sum(void(*fun)(),int &x, int &y)
{
    x = 5;
    y = 10;
    return (x+y);
}
int main()
{
    //(*fun)();
    int x=4, y=3;
    cout<<"The sum is: "<<sum(fun,x,y)<<endl;
    return 0;
}
