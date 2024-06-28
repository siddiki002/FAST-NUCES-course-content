#include <iostream>
#include <string>

using namespace std;
void print(int a, char b, int c)
{
    cout<<"Coeff is: "<<a<<endl<<"Var is: "<<b<<endl<<"Power is: "<<c<<endl;
}
int main()
{
    int pow,c;
    char ch;
   for (int i = 0; i < 3; i++)
   {
       cin>>c>>ch>>pow;
       print(c,ch,pow);
   }
   
}