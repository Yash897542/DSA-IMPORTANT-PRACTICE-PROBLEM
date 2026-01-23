#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
  public:
    vector<string>result;
    bool issafe(int i , int j , vector<vector<int>>&maze , int n){
        return i>=0 && j>=0 && i<n && j<n && maze[i][j] ==1;
    }
    void solve(int i , int j , vector<vector<int>>&maze, string path){
        int n = maze.size();
        if(!issafe(i , j , maze , n)){
            return;
        }
        if(i == maze.size()-1 && j == maze.size()-1){
            result.push_back(path);
            return;
        }
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0){
            return;
        }
        maze[i][j] = 0;
        
        path.push_back('D');
        solve(i+1 , j , maze , path);
        path.pop_back();
        
        path.push_back('L');
        solve(i , j-1 , maze , path);
        path.pop_back();
        
        path.push_back('R');
        solve(i , j+1 , maze, path);
        path.pop_back();
        
        
        path.push_back('U');
        solve(i-1 , j , maze , path);
        path.pop_back();
        
        maze[i][j] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        string path = "";
        solve(0 , 0 , maze , path);
        return result;
    }
};
int main(){
    int n;
    cin>> n;
    vector<vector<int>>maze(n , vector<int>(n));
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            cin>> maze[i][j];
        }
    }
    Solution obj;
    vector<string>res = obj.ratInMaze(maze);
    cout<<"[";
    for(int i = 0 ; i<res.size() ; i++){
        for(int j = 0 ; j<res[i].length() ; j++){
            cout<<res[i][j];
        }
        if(i != res.size()-1){
            cout<<",";
        }
    }
    cout<<"]";
    return 0;

}