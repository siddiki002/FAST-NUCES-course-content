#include <iostream>
#include <vector>
using namespace std;

class minheap
{
    vector <int> v;
    
        int getleft(int i){return (2*i+1);}
        int getright(int i){return (2*i+2);}
        int getparent(int i){return (i-1)/2;}

        void sift_up(int i)
        {
            while(i>0)
            {
                if (v[i] < v[getparent(i)])
                {
                    swap(v[i],v[getparent(i)]);
                }
                i = getparent(i);
            }
        }

        void sift_down(int i)
        {
            int left = getleft(i);
            int right = getright(i);
            int min = i;
            if (left < v.size() && v[i] > v[left])
            {
                min = left;
            }
            if (right < v.size() && v[right] < v[min])
            {
                min  = right;
            }
            if (i!=min)
            {
                swap(v[i],v[min]);
                sift_down(min);
            }

        }
        public:
        void push_back(int n)
        {
            v.push_back(n);
            int index = v.size()-1;
            sift_up(index);
        }
        void traverse()
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout<<v[i]<<" ";
            }
        }
        int get_min()
        {
            int temp = v[0];
            v[0] = v[v.size()-1];
            v.pop_back();
            sift_down(0);
            return temp;
        }
};

int main()
{
    minheap obj;
    obj.push_back(3);
    obj.push_back(1);
    obj.push_back(14);
    obj.push_back(2);
    obj.push_back(5);
    obj.get_min();
    obj.traverse();
}