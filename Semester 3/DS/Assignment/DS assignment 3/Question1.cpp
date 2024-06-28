#include <iostream>

using namespace std;

int count1(int board[3][3]){
    int count1=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j]==1){
                count1++;
            }
        }
        
    }
    return count1;
    
}
int count2(int board[3][3]){
    int count2=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j]==2){
                count2++;
            }
        }
        
    }
    return count2;
}
bool ismovesleft(int board[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j]==0){
                return true;
            }
        }
        
    }
    return false;
    
}
int evaluate(int board[3][3],int player, int opponent){
    //checking rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            if (board[i][0]==player){
                return +10;
            }
            else if (board[i][0]==opponent){
                return -10;
            }
        }
    }
    //checking columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j]==board[1][j] && board[1][j]==board[2][j]){
            if (board[0][j]==player){
                return +10;
            }
            else if (board[0][j]==opponent){
                return -10;
            }
        }
    }
    // checking diagonals
    // left diagonal
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        if (board[0][0]==player){
            return +10;
        }
        else if (board[0][0]==opponent){
            return -10;
        }
    }
    // right diagonal
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        if (board[0][2]==player){
            return +10;
        }
        else if (board[0][2]==opponent){
            return -10;
        }
    }
    return 0;
    
}
int minmax(int board[3][3], int depth, bool is_max, int player, int opponent){
    int score = evaluate(board,player,opponent);
    if (score==10){
        return score;
    }
    if (score==-10){
        return score;
    }
    if (!ismovesleft(board)){
        return 0;
    }
    if (is_max){
        int best = -1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j]==0){
                    board[i][j] = player;

                    best = max(best,minmax(board,depth+1,!is_max,player,opponent));

                    board [i][j] = 0;
                }
            }
            
        }
        return best;
        
    }
    else
    {
        int best = 1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j]==0){
                    board[i][j] = opponent;

                    best = min(best,minmax(board,depth+1,!is_max,player,opponent));
                    board[i][j] = 0;
                }
            }
            
        }
        return best;
        
    }
}
void best_move(int board[3][3],int &brow, int &bcol, int player, int opponent){
    int best_val = -1000;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j]==0){
                board [i][j] = player;
                int temp = minmax(board,0,false,player,opponent);
                board [i][j] = 0;
                if (temp>best_val){
                    brow = i;
                    bcol = j;
                    best_val = temp;
                }
            }
        }
        
    }
    // cout<<"The value of best val is:"
    
}
void swap_players(int &player, int &opponent){
    int temp = player;
    player = opponent;
    opponent = temp;
}
int check_board(int board[3][3]){
    //checking rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            if (board[i][0]==1){
                return 1;
            }
            else if (board[i][0]==2){
                return 2;
            }
        }
    }
    // checking columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j]==board[1][j] && board[1][j]==board[2][j]){
            if (board[0][j]==1){
                return 1;
            }
            else if (board[0][j]==2){
                return 2;
            }
        }
    }
    // checking diagonals
    //left diagonal
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        if (board[0][0]==1){
            return 1;
        }
        else if (board[0][0]==2){
            return 2;
        }
    }
    //right diagonal
    if (board[0][2]==board[1][1] && board[1][1] == board[2][0]){
        if (board[0][2]==1){
            return 1;
        }
        else if (board[0][2]==2){
            return 2;
        }
    }
    return 3;
    
    
}
int main()
{
    int board[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>board[i][j];
        }
        
    }
    int no_1 = count1(board);
    int no_2 = count2(board);
    if (abs((no_2 - no_1))>1){
        cout<<"-1";
        return 0;
    }
    // int player = 1;
    // int opponent = 2;
    // int brow = -1;
    // int bcol = -1;
    // best_move(board,brow,bcol,player,opponent);
    // cout<<"Best move row is: "<<brow<<endl<<"Best move col is: "<<bcol<<endl;
    int i=0;
    int player,opponent;
    if (no_1 > no_2){    //turn is of player 2
        player = 2;
        opponent = 1;
    }       
    else{
        player = 1; opponent = 2;
    }
    while(1)
    {
        int brow = -1;
        int bcol = -1;
        best_move(board,brow,bcol,player,opponent);
        // cout<<brow<<endl<<bcol<<endl<<player<<endl<<opponent;
        // system("PAUSE");
        board[brow][bcol] = player;
        if (!ismovesleft(board)){
            cout<<"0";
            break;
        }
        int temp = check_board(board);
        if (temp!=3){
            cout<<temp;
            break;
        }
        swap_players(player,opponent);

        

    }
    
}