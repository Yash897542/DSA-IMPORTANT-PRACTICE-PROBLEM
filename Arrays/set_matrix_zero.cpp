#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>temp = matrix;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0 ; k<m ; k++){
                        temp[i][k] = 0;
                    }
                    for(int k = 0 ; k<n ; k++){
                        temp[k][j] = 0;
                    }
                }
                }
            }
            matrix = temp;       
    }
};
int main(){
    int n , m;
    cin>>n >> m;
    vector<vector<int>>matrix(n , vector<int>(m));
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            cin>> matrix[i][j];
        }
    }
    Solution obj;
    obj.setZeroes(matrix);
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            cout<< matrix[i][j] << " ";
        }
        cout<< endl;
    }
}