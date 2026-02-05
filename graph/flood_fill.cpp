#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color , int original){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j] == color || image[i][j] != original){
            return;
        }
        image[i][j] = color;
        dfs(image , i-1 , j , color , original);
        dfs(image , i , j+1 , color , original);
        dfs(image , i+1 , j , color , original);
        dfs(image , i , j-1 , color , original);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image , sr , sc , color , image[sr][sc]);
        return image;
    }
};
int main(){
    int n , m;
    cin>>n >> m;
    vector<vector<int>>image(n , vector<int>(m));
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            cin>> image[i][j];
        }
    }
    int sr , sc , color;
    cin>> sr >> sc >> color;
    Solution obj;
    vector<vector<int>>ans = obj.floodFill(image , sr , sc , color);
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            cout<< ans[i][j] << " ";
        }
        cout<< endl;
    }
}