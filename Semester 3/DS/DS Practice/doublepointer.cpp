#include <iostream>

using namespace std;

void cal(int *x, int *y, int **z)
{
    //int sum = (*x) + (*y);
    cout<<"Before transfer: "<<**z<<endl;
    *z = y;
    cout<<"After transfer: "<<**z<<endl;
}
int main()
{
    int x=0,y=8;
    int *p = &x;
    int &z = x;
    int *pz = &z;
    cal(&x,&y,&pz);

}