#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool check_right(char** board, string temp, int r, int c, int m, int n){
    int check=0;
    for (int i = c,j=0; j < temp.size(), i<m; i++,j++)
    {
        if (board[r][i]==temp[j] || board[r][i]=='+'){
            check++;
        }
        else if (board[r][i]=='*'){
            char ch = temp[temp.size()-1];
            while(i<m){
                if (ch==board[r][i]){
                    return true;
                }
                i++;
            }
        }
    }
    if (check==temp.size()){
        return true;
    }
    else
    {
        return false;
    }
    
}
bool check_left(char** board, string temp, int r, int c, int m, int n){
    int check=0;
    for (int i = c,j = 0; i>-1 ; i--,j++)
    {
        if (board[r][i]==temp[j]||board[r][i]=='+'){
            check++;
        }
    }
    if (check==temp.size()){
        return true;
    }
    else{
        return false;
    }
    
}
bool check_down(char** board, string temp, int r, int c, int m, int n){
    int check=0;
    for(int i=r,j=0;j<temp.size(),i<n;i++,j++){
        if (board[i][c]==temp[j] || board[i][c]=='+'){
            check++;
        }
        else if (board[i][c]=='*'){
            char ch = temp[temp.size()-1];
            while(i<n){
                if (ch==board[i][c]){
                    return true;
                }
                i++;
            }
        }
    }
    if (check==temp.size()){
        return true;
    }
    else{
        return false;
    }
}
bool check_up(char** board, string temp, int r, int c, int m, int n){
    int check = 0;
    for (int i=r,j=0;j<temp.size(),i>-1;i--,j++){
        if (board[i][c]==temp[j] || board[i][c]=='+'){
            check++;
        }
        else if (board[i][c]=='*'){
            char ch = temp[temp.size()-1];
            while(i>-1){
                if (ch==board[r][i]){
                    return true;
                }
                i--;
            }
        }
    }
    if (check==temp.size()){
        return true;
    }
    else{
        return false;
    }
}
void find_word(char** board, string temp, int r, int c){
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j]==temp[0]|| board[i][j]=='+'){
                if (j<c){
                    if (check_right(board,temp,i,j,c,r)){
                        cout<<i<<" "<<j<<" "<<"R"<<endl;
                        //return;
                    }
                }
                if (j>-1){
                    if (check_left(board,temp,i,j,c,r)){
                        cout<<i<<" "<<j<<" "<<"L";
                        //return;
                    }
                }
                if (i>0){
                    if (check_up(board,temp,i,j,c,r)){
                        cout<<i<<" "<<j<<" "<<"U"<<endl;
                       // return;
                    }
                }
                if (i<r){
                    if (check_down(board,temp,i,j,c,r)){
                        cout<<i<<" "<<j<<" "<<"D"<<endl;
                        //return;
                    }
                }   
            }
        }
        
    }
    
}
int main(){
    char **puzzle;
    int m,n;
    cin>>m>>n;  // n = rows // m = column
    if (m<0 || n<0){
        return 0;
    }
    puzzle = new char*[m];
    for (int i = 0; i < m; i++)
    {
        puzzle[i] = new char[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>puzzle[i][j];
        }
        
    }
    int p;
    cin>>p;
    vector<string> words;
    for (int i = 0; i < p+1; i++)
    {
        //fflush(stdin);
        string temp;
        getline(cin,temp);
        //int len = temp.size();
        //words.push_back(temp);
        // for (int i = 0; i < temp.size(); i++)
        // {
        //     if (temp[i]==' '){
        //         for (int j = i; j < temp.size(); j++)
        //         {
        //             temp[j] = temp[j+1];
        //         }
                
        //     }
        // }
         string to_put = "";
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i]!=' '){
                to_put+=temp[i];
            }
        }
        words.push_back(to_put);
        
    }
    
    // for (int i = 0; i < p+1; i++)
    // {
    //     cout<<words[i]<<endl;
    // }
    
    for (int i = 0; i < p+1; i++)
    {
       
        find_word(puzzle,words[i],n,m);
    }
    
}