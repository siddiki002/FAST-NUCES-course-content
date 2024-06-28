#include <iostream>
#define sizeoftable 20
using namespace std;

class hashentry
{
    public:
        int key,value;
        hashentry(){key = -1;}
        hashentry(int k, int v){
            key = k;
            value = v;
        }
        void set_values(int k, int v){
            key = k;
            value = v;
        }
};

class hashtable
{
    //declaring a 2d array of hashentry
    hashentry** table;
    public:
        hashtable(){
            table = new hashentry*[sizeoftable];
            for (int i = 0; i < sizeoftable; i++)
            {
                table[i] = new hashentry();
            }
            
        }
        int h(int key){
            return (key%sizeoftable);
        }
        void insert(int key, int val)
        {
            int temp = key;
            //int index = h(key);
            //int curr_index = index;
            if (table[h(key)]->key==-1){
                table[h(key)]->set_values(key,val);
            }
            else{
               while (table[h(temp)]->key!=-1 && h(temp)!=h(key-1)){
                   temp++;
               }
               if (table[h(temp)]->key==-1){
                   table[h(temp)]->set_values(key,val);
               }
               else
               {
                   cout<<"Table is full"<<endl;
               }
            }
        }
        void delete_entry(int k)
        {
            // searching for that particular key
            int index = h(k);
            if(table[index]->key==k){
                //No need to probe
                delete table[index];
            }
            else
            {
                // we need to traverse
                int temp = k;
                while (table[h(temp)]->key!=k && h(temp)!=h(k-1))
                {
                    temp++;
                }
                if (table[h(temp)]->key==k){
                    delete table[h(temp)];
                }
                else
                {
                    cout<<"The key to delete is not found"<<endl;
                    return;
                }
            }
        }
        int Search(int key){
            int index = h(key);
            if (table[index]->key==key){
                return (table[index]->value);
            }
            else
            {
                int temp = key;
                while(table[h(temp)]->key!=key && h(temp)!=h(key-1)){
                    temp++;
                }
                if (table[h(temp)]->key==key){
                    return (table[h(temp)]->value);
                }  
            }
            //cout<<"Element not found"<<endl;
            return -1;
        }

};  


int main()
{
    hashtable obj;
    obj.insert(11,45);
    obj.insert(15,40);
    obj.insert(20,33);
    obj.insert(40,11);
    //cout<<obj.Search(11)<<endl;
    //obj.delete_entry(40);
    if(obj.Search(40)==-1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<obj.Search(40)<<endl;
    }
}