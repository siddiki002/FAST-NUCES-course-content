#include <iostream>
#include <vector>
using namespace std;

class max_heap
{
    int getparent(int i){return (i-1)/2;}
    int getleft(int i){return (2*i)+1;}
    int getright(int i){return (2*i)+2;}

    void sift_up(vector<int> v, int i)
    {
        while(i>0){
            if (v[getparent(i)]< v[i]){
                swap(v[getparent(i)],v[i]);
            }
            i = getparent(i);
        }
    }

    void sift_down(int* v,int i, int n)
    {
        int left = getleft(i);
        int right = getright(i);
        int largest = i;
        if(left<n && v[i] < v[left])
        {
            largest = left;
        }
        if (right<n && v[right] > v[largest])
        {
            largest = right;
        }
        if (i!=largest){
            swap(v[i],v[largest]);
            sift_down(v,largest,n);
        }
    }
    public:
        max_heap(int* array, int n)
        {
            int i = (n-2)/2;
            while(i>=0)
            {
                sift_down(array,i--,n);
            }
        }
        int extract_max(int* array, int n)
        {
            int temp = array[0];
            array[0] = array[n-1];
            sift_down(array,0,n);
            return temp;
        }
};

void heap_sort(int* array, int n)
{
    max_heap obj(array,n);
    while(n>0)
    {
        array[n-1] = obj.extract_max(array,n);
        n--;
    }

}

int main()
{
    int array[] = {3,4,1,7,8,10};
    int n = sizeof(array)/sizeof(array[0]);
    heap_sort(array,n);
    for (int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    
}