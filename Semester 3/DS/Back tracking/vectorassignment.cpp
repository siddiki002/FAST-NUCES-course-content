#include <iostream>
#include <vector>
using namespace std;
void change_array(vector<int> &v1){
    v1[3] = 8;
}
int main(){
    vector<int> arr1= {1,2,3,4,5};
    change_array(arr1);
    for (int i = 0; i < arr1.size(); i++)
    {
        cout<<arr1[i]<<endl;
    }
    
    
}