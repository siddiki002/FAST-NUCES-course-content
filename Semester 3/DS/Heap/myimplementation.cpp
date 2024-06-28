#include <iostream>
#include <vector>
using namespace std;

class maxheap
{
    vector<int> v;
    int getparent(int i){return (i-1)/2;}
    int getleft(int i){return (2*i)+1;}
    int getright(int i){return (2*i)+2;}

    void sift_up(int i)
    {
        while(i>0){
            if (v[getparent(i)]< v[i]){
                swap(v[getparent(i)],v[i]);
            }
            i = getparent(i);
        }
    }

    void sift_down(int i)
    {
        int left = getleft(i);
        int right = getright(i);
        int largest = i;
        if(left<v.size() && v[i] < v[left])
        {
            largest = left;
        }
        if (right<v.size() && v[right] > v[largest])
        {
            largest = right;
        }
        if (i!=largest){
            swap(v[i],v[largest]);
            sift_down(largest);
        }
    }
    public:
    void insert(int val)
    {
        v.push_back(val);
        int index = v.size()-1;
        sift_up(index);
    }
    int get_max()
    {
        int max = v[0];
        v[0] = v[v.size()-1];
        v.pop_back();
        sift_down(0);
        return max;
    }
    void traverse(){
        for (int i = 0; i < v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
        
    }
    void remove(int i)
    {
        v[i] = INT_MAX;
        sift_up(i);
        get_max();
    }
   
};

int main()
{
    maxheap obj;
    obj.insert(11);
    obj.insert(15);
    obj.insert(17);
    obj.insert(25);
    obj.insert(35);
    obj.insert(5);
    obj.insert(40);
    // cout<<obj.get_max()<<endl;
    //cout<<obj.get_max();
    //obj.traverse();
    //cout<<obj.get_max()<<endl<<endl<<endl;
    obj.remove(6);
    obj.remove(1);
    obj.traverse();
    //cout<<obj.get_max()<<endl;
}