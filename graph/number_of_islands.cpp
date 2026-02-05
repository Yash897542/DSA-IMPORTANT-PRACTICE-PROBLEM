#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void dfs(int i , int j , vector<vector<bool>>&vis ,vector<vector<char>>& grid , int n , int m  ){
        if(i < 0 || j<0 || i>=n || j>=m|| vis[i][j] || grid[i][j] != '1' ){
            return;
        }
        vis[i][j] = true;
        dfs(i-1 , j , vis , grid , n , m);
        dfs(i , j+1 , vis , grid , n , m);
        dfs(i+1 , j , vis , grid , n , m);
        dfs(i , j-1 , vis , grid , n , m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int island = 0;
        vector<vector<bool>>vis(n , vector<bool>(m , false));
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i , j , vis , grid , n , m);
                    island++;
                }
            }
        }
        return island;
        
    }
};
int main(){
    int n , m;
    cin>>n >> m;
    vector<vector<char>>grid(n , vector<char>(m));
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            cin>> grid[i][j];
        }
    }
    Solution obj;
    cout<< obj.numIslands(grid);
}
