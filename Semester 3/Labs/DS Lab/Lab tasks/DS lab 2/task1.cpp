#include <iostream>

using namespace std;
bool check_array(int **arr, int rows, int col)
{
    if (rows!=col)
    {
        return false;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i==j)
            {
                if (arr[i][j]!=1)
                {
                    return false;
                }
            }
            else if (i!=j)
            {
                if (arr[i][j]!=0)
                {
                    return false;
                }
            }
        }
        
    }
    return true;
    
}
int main()
{
    int row, col;
    int **arr;
    cout<<"Enter number of rows"<<endl;
    cin>>row;
    cout<<"Enter number of columns: "<<endl;
    cin>>col;
    arr = new int*[col];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[row];
    }
    cout<<"Enter values: "<<endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    if (check_array(arr,row,col))
    {
        cout<<"The matrix is identity."<<endl;
    }
    else
    {
        cout<<"The matrix is not identity."<<endl;
    }
    
    
}