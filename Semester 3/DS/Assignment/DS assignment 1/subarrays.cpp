#include <iostream>
#include <vector>
int max_sum = 0;
using namespace std;
bool is_arrayneg(vector<int> v1){
    int n=0;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i]<0){
            n++;
        }
    }
    if (n==v1.size()){
        return true;
    }
    else{
        return false;
    }
    
}
int find_sum(vector<int> temp){
    int sum = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        sum+=temp[i];
    }
    return sum;
    
}
void generate_subarrays(vector<int> &v1, int start, int end, vector<int> &ans){
    vector<int> temp;
    int sum;
    if (end==v1.size()){
        return;
    }
    else if (start>end){
        generate_subarrays(v1,0,end+1,ans);
    }
    else{
        for (int i = start; i < end; i++)
        {
            temp.push_back(v1[i]);
        }
        temp.push_back(v1[end]);
        sum = find_sum(temp);
        if (sum>max_sum){
            max_sum = sum;
            ans = temp;
        }
       generate_subarrays(v1,start+1,end,ans); 
    }
}
int main(){
    vector<int> v1;
    vector<int> ans;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        v1.push_back(temp);
    }
    // if(is_arrayneg(v1)){
    //     return 0;
    // }
    generate_subarrays(v1,0,0,ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<max_sum<<endl;
    
    
}