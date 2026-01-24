#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public :
    bool isvalid( vector<vector<char>>&board , int row , int col , char c){
        for(int i = 0 ; i<9 ; i++){
            if(board[i][col] == c) return false;
            if(board[row][i] == c) return false;
        }
        int startrow = 3*(row/3);
        int startcol = 3*(col/3);
        for(int i = startrow ; i<startrow+3 ; i++){
            for(int j = startcol ; j<startcol+3 ; j++){
                if(board[i][j] == c) return false;
            }
        }
        return true;
    }
    bool solve( vector<vector<char>>&board){
        for(int i = 0 ; i<9 ; i++){
            for(int j = 0 ; j<9 ; j++){
                if(board[i][j] == '.'){
                    for(char c = '1' ; c<='9' ; c++){
                        if(isvalid(board , i , j , c)){
                            board[i][j] = c;
                            if(solve(board)){
                                return true;
                            }
                             board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool sudukosolver(vector<vector<char>>&board){
        return solve(board);
    }
};
int main(){
    vector<vector<char>>board(9 , vector<char>(9));
    for(int i = 0 ; i<9 ; i++){
        for(int j = 0 ; j<9 ; j++){
            cin>> board[i][j];
        }
    }
    solution obj;
    if(obj.sudukosolver(board)){
        for(int i = 0 ; i<9 ; i++){
            for(int j = 0 ; j<9 ; j++){
                cout<< board[i][j] << " ";
            }
            cout<< endl;
        }
    }
    else{
        cout<< "No solution exists" << endl;
    }
    return 0;
}