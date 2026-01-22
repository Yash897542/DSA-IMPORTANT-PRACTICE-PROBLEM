#include<iostream>
#include<vector>
#include<string>
using namespace std;
class solution{
    public :
    bool issafe(vector<string>&board , int row , int col , int n){
        for(int i = row-1 ; i>=0 ; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = row-1 , j = col-1 ; i>=0 && j>=0 ; i-- , j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = row-1 , j = col+1 ; i>=0 && j<n ; i-- , j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = 0 ; i<n ; i++){
            if(board[row][i] == 'Q'){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>>ans;
    void solve(vector<string>&board , int row , int n){
        if(row >= n){
            ans.push_back(board);
            return;
        }
        for(int col = 0 ; col<n ; col++){
            if(issafe(board , row , col , n)){
                board[row][col] = 'Q';
                solve(board , row+1 , n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>>solveNqueens(int n){
        vector<string>board(n , string(n , '.'));
        solve(board , 0 , n);
        return ans;
    }
};
int main(){
    int n ;
    cin>> n ;
    solution obj;
    vector<vector<string>>res = obj.solveNqueens(n);
    for(int i = 0 ; i<res.size() ; i++){
        cout<<"[";
        for(int j = 0 ; j<res[i].size() ; j++){
            cout<<res[i][j];
            if(j != res[i].size()-1){
                cout<<',';
            }
        }
        cout<<"]";
        if(i != res.size()-1){
            cout<<',';
        }
    }
}