#include <iostream>

using namespace std;
bool isPath(int** board, int r, int c, int n){
    // checking column
    for (int i=r-1;i>=0;i--){
        if (board[i][c]==1){
            return false;
        }
    }
    //checking upper left diagonal
    for (int i=r-1,j=c-1;i>=0 && j>=0; i--,j--){
        if (board[i][j]==1){
            return false;
        }
    }
    // checking upper right diagonal
    for (int i=r-1,j=c+1;i>=0 && j<n; i--,j++){
        if (board[i][j]==1){
            return false;
        }
    }
    return true;
}
void Queenplacer(int** board, int r, int c, int n){
    if (r==n){
        cout<<"We have got a solution"<<endl;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return;        
    }
    for (int j=0;j<n;j++){
        if (isPath(board,r,j,n)){
            board[r][j] = 1;
            Queenplacer(board,r+1,c,n);
            board[r][j] = 0;
            //return;
        }
    }
    return;
}
void putQueen(int** board, int n){
    Queenplacer(board,0,0,n);
    return;
}
int main(){
    int **board = new int*[4];
    for (int i=0;i<4;i++){
        board[i] = new int[4];
        for (int j=0;j<4;j++){
            board[i][j] = 0;
        }
    }
    putQueen(board,4);
}