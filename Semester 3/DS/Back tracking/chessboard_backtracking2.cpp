#include <bits/stdc++.h>
using namespace std;
#define squares 4

int board[squares][squares]; // you can pick any matrix size you want
int sol_count = 0;
                 
bool isPossible(int n,int row,int col){ // check whether 
                      					// placing queen possible or not

	// Same Column
	for(int i=row-1;i>=0;i--){
		if(board[i][col] == 1){
		  return false;
		}
	}

	//Upper Left Diagonal
	for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--){
	    if(board[i][j] ==1){
	      return false;
	    }
  }

	// Upper Right Diagonal
	for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++){
		if(board[i][j] == 1){
		  return false;
		}
	}

  return true;
}

void nQueenRecursive(int n,int row){
  if(row==n){
    // We have reached some solution.
    // Print the board matrix
    // return

	sol_count++;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout << board[i][j] << " ";
      }
      cout<<endl;
    }
    cout<<endl;
    return;
  }

  // Place at all possible positions and move to smaller problem
  for(int j=0;j<n;j++){

    if(isPossible(n,row,j)){  	// if no attack, proceed
      board[row][j] = 1;      	// mark row, column with 1
      nQueenRecursive(n,row+1); // call function to continue further
    }
    
    board[row][j] = 0;      // unmark to backtrack
  }
  return;
}

void placeNQueens(int n){

	// allocate squares*squares memory 
	// and initialize all cells with zeroes
	memset(board,0,squares*squares*sizeof(int));
	
	nQueenRecursive(n,0);     	// call the backtracking function 
                     			// and print solutions
}

int main(){
    
    placeNQueens(squares);
    cout << "Solutions found: " << sol_count;
    return 0;
}

// time complexity is 2^n
// space complexity is 2^n

