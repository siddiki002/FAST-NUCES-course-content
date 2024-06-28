#include <iostream>
using namespace std;
#define size  4

bool issafe(int maze[][size], int x, int y){
    if(x<size && y<size && maze[x][y]==0){
        return true;
    }
    return false;
}

bool find_path_rec(int maze[][size], int row, int col){
    if(row==size-1 && col==size-1){
    	cout << row << " " << col << "\n";
    	return true;
    }
    
    if(issafe(maze, row, col)){
        cout << row << " " << col << "\n";
        if(find_path_rec(maze, row+1, col)){
            return true;
        }
        if(find_path_rec(maze, row, col+1)){
            return true;
        }
    }
    return false;
}

int main()
{
	int maze[size][size] = {{0,1,1,1},
						    {0,1,1,1},
						    {0,0,1,1},
						    {1,0,0,2}};
						    
	find_path_rec(maze, 0, 0);
}
