#include <iostream>

using namespace std;
class safe2darray{
    int size;
    int **array;
    public:
        safe2darray(int n){
            size = n;
            array = new int*[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = new int[n];
                for (int j = 0; j < n; j++)
                {
                    array[i][j]=0;
                }
                
            }
            
        }
        void input(){
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    cin>>array[i][j];
                }
                
            }
            
        }
        bool is_sudoku(){
            for (int i = 0; i < size; i++)
            {
                int temp = array[i][0];
                for (int j = 1; j < size; j++)
                {
                    if (temp==array[i][j]){
                        return false;
                    }
                }
                
            }
            return true;
            
        }
        void append_array(int n){
            n+=size;
            int **temp = new int*[n];
            for (int i = 0; i < n; i++)
            {
                temp[i] = new int[n];
                for (int j = 0; j < n; j++)
                {
                    temp[i][j] = 0;
                }
                
            }
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    temp[i][j] = array[i][j];
                }
                
            }
            // deleting original array
            for (int i = 0; i < size; i++)
            {
                delete [] array[i];
            }
            delete [] array;
            array = temp;   // making the new array being pointed by the same old pointer of 'array'
            size = n;
        }
        void fill_lastcol(){
            for (int i = 0; i < size-1;i++)
            {
                int sum = 0;
                int j;
                for ( j = 0; j < size; j++)
                {
                    sum+=array[i][j];
                }
                array[i][j-1] = 45-sum;
            }
        }
        void fill_lastrow(){
            for (int j = 0; j < size-1; j++)
            {
                int sum =0;
                int i;
                for (i = 0; i < size; i++)
                {
                    sum+=array[i][j];
                }
                array[i-1][j] = 45 - sum;
            }
            
        }
        void fill_last_element(){
            int sum=0;
            for (int i = 0; i < size-1; i++)
            {
                sum += array[i][8];
            }
            array[8][8] = 45-sum;
        }
        void show(){
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    cout<<array[i][j]<<" ";
                }
                cout<<endl;
                
            }
            
        }
        int get_size(){return size;}
};  
int main(){
    safe2darray obj(8);
    obj.input();
    if (obj.is_sudoku()){
        return 0;
    }
    obj.append_array(1);
    //cout<<"Sudoku is solved"<<endl;
    obj.fill_lastcol();
    obj.fill_lastrow();
    obj.fill_last_element();
    obj.show();

}