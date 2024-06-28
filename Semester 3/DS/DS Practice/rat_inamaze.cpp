#include <iostream>
#include<cstring>
using namespace std;
bool ispath(int **board, int r, int c, int n)
{
    if(r<n && c<n && board[r][c]==1){
        return true;
    }
    return false;
}

bool recursive_path_finder(int **board, int r, int c, int n, int **sol){
    if (r==n-1 && c==n-1){
        sol[r][c]=1;
        return true;
    }
    if (ispath(board,r,c,n)){
        sol[r][c]=1;
        if (recursive_path_finder(board,r+1,c,n,sol)){
            return true;
        }
        if (recursive_path_finder(board,r,c+1,n,sol)){
            return true;
        }
        sol[r][c]=0;
        return false;
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter size of board"<<endl;
    cin>>n;
    int **board = new int*[n];
    int **sol = new int*[n];
    for (int i=0;i<n;i++)
    {
        board[i] = new int[n];
    }
    for (int i=0;i<n;i++)
    {
        sol[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            sol[i][j] = 0;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>board[i][j];
        }
        
    }
    //memset(sol,0,n*n*sizeof(int));
    if(recursive_path_finder(board,0,0,n,sol)){
        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
    }
    
    
    

}