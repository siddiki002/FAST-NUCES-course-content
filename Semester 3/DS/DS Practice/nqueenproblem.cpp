#include <iostream>

using namespace std;
int no_of_sol = 0;
bool isPossible(int** board, int r, int c, int n){
    // checking column
    for (int i = r-1; i >=0; i--)
    {
        if(board[i][c]==1){
            return false;
        }
    }
    // upper left diagonal
    for (int i=r-1,j=c-1;j>=0 && i>=0;i--,j--){
        if (board[i][j]==1){
            return false;
        }
    }
    // upper right diagonal
    for (int i=r-1,j=c+1;i>=0 && j<n;i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
    
}
void nQueenrecursive(int** board, int n, int r)
{
    if (r==n){
        cout<<"Printing board"<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
            
        }
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (isPossible(board,r,j,n)){
            board[r][j]=1;
            nQueenrecursive(board,n,r+1);
            }
            board[r][j] = 0;
    }
    return;
    
}
void putqueen(int** board, int n){
    nQueenrecursive(board,n,0);
    //cout<<"Number of solutions are: "<<no_of_sol<<endl;
}
int main(){
    int n;
    cin>>n;
    int **board = new int*[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    board[0][1]=1;
    putqueen(board,n);
    return 0;
    
}