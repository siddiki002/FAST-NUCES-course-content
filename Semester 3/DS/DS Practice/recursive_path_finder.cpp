#include <iostream>

using namespace std;
//int answer[6][2];
bool issafe(int maze[][4],int row, int col){
    if (row<4 && col<4 && maze[row][col]==0){
        return true;
    }
    return false;
}
bool recursive_path_finder(int maze[][4],int row, int col){
    if (row==3 && col==3){
        cout<<row<<" "<<col<<endl;
        return true;
    }
    if (issafe(maze,row,col)){
        cout<<row<<" "<<col<<endl;
        if (recursive_path_finder(maze,row+1,col)){
            //cout<<row<<" "<<col<<endl;
            return true;
        }
        if (recursive_path_finder(maze,row,col+1)){
            //cout<<row<<" "<<col<<endl;
            return true;
        }
    }
    return false;
}

int main(){
    int maze[4][4]={{0,1,1,1},
                    {0,1,1,1},
                    {0,0,1,1},
                    {1,0,0,2}
                   };
    recursive_path_finder(maze,0,0);
    
}
