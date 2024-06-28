#include <iostream>

using namespace std;

void check_friend(bool *arr1,bool *arr2,int r1, int r2)
{
    for (int i = 0; i < 5; i++)
    {
        if (arr1[i]==true && arr2[i]==true)
        {
            cout<<r1<<" and "<<r2<<" are friends with "<<i<<endl;
        }
    }
    
    
}
int main()
{
    bool arr[5][5] = {{false,true,false,true,true},
                       {true,false,true,false,true},
                       {false, true, false,false,false},
                       {true,false,false,false,true},
                       {true,true,false,true,false}
                                                 };
   for (int i = 0; i < 4; i++)
   {
       for (int j = i+1; j < 5; j++)
       {
           check_friend(arr[i],arr[j],i,j);
       }
       
   }
   
    
}

