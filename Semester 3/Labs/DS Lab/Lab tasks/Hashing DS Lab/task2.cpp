#include <iostream>
#include <math.h>
#define sizeoftable 50
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
        int division_method(int key){
            return (key%sizeoftable);
        }
        int mid_square(int key){
            int temp = key*key;
            if (temp>1000 && temp<9999){
                int d1 = (temp/10)%10;
                int d2 = (temp/100)%10;
                return (d1*10+d2)%sizeoftable;
            }
            else
            {
                for (int i = 1; temp>9 ; i*=10)
                {
                    temp/=i;
                }
                return temp;
            }
        }
        int folding(long int key){
            //consider the key is 123-456-789
            //therefore breaking it in even parts
            int val1 = key%1000;
            int val2 = (key/1000)%1000;
            int val3 = key/1000000;
            return (val1+val2+val3)%sizeoftable;
        }
        int radix(int key){
            //changing to base 9
            //counting number of elements
            int count = 0;
            int temp = key;
            for (int i = 1; temp>0 ; i*=10)
            {
                count++;
                temp/=i;
            }
            int *array = new int[count];
            temp = key;
            for (int i = 0,j=1; i < count; i++,j*=10)
            {
                array[i] = (temp/j)%10;
            }
            int ans = 0;
            for (int i=0,j=count-1;i<count;i++,j--)
            {
                ans+=(pow(9,j))*array[i];
            }
            return (ans%sizeoftable);
        }
        int multiply(int key)
        {
            float A = 0.098761;
            int ans = (sizeoftable)*((int)(key*A)%1);
            return ans;
        }
        void insert(int key, int val)
        {
            int temp = key;
            //int index = division_method(key);
            //int curr_index = index;
            if (table[division_method(key)]->key==-1){
                table[division_method(key)]->set_values(key,val);
            }
            else{
               while (table[division_method(temp)]->key!=-1 && division_method(temp)!=division_method(key-1)){
                   temp++;
               }
               if (table[division_method(temp)]->key==-1){
                   table[division_method(temp)]->set_values(key,val);
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
            int index = division_method(k);
            if(table[index]->key==k){
                //No need to probe
                delete table[index];
            }
            else
            {
                // we need to traverse
                int temp = k;
                while (table[division_method(temp)]->key!=k && division_method(temp)!=division_method(k-1))
                {
                    temp++;
                }
                if (table[division_method(temp)]->key==k){
                    delete table[division_method(temp)];
                }
                else
                {
                    cout<<"The key to delete is not found"<<endl;
                    return;
                }
            }
        }
        int Search(int key){
            int index = division_method(key);
            if (table[index]->key==key){
                return (table[index]->value);
            }
            else
            {
                int temp = key;
                while(table[division_method(temp)]->key!=key && division_method(temp)!=division_method(key-1)){
                    temp++;
                }
                if (table[division_method(temp)]->key==key){
                    return (table[division_method(temp)]->value);
                }  
            }
            //cout<<"Element not found"<<endl;
            return -1;
        }

};  

int main()
{
    hashtable obj;
    //obj.folding(123456789);
    // here we are using division hashing method but any of the above mentioned hashing function can be used
    obj.insert(11,45);
    obj.insert(13,99);
    obj.insert(16,15);
    obj.insert(54,11);
    if (obj.Search(54)==-1){
        cout<<"Element not found"<<endl;
    }
    else{
        cout<<obj.Search(54)<<endl;
    }
    return 0;

}