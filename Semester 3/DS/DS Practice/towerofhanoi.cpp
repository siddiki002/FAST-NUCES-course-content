#include <iostream>

using namespace std;

void Towerofhanoi(int N, char Beg, char Aux, char End){
    if (N==1){
        cout<<"Move "<<Beg<<" to "<<End<<endl;
    }
    else{
        Towerofhanoi(N-1,Beg,End,Aux);
        Towerofhanoi(1,Beg,Aux,End);
        Towerofhanoi(N-1,Aux,Beg,End);
    }
}
int main()
{
    Towerofhanoi(6,'A','B','C');
    return 0;
}