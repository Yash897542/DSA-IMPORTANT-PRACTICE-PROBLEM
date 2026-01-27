#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>>res;
    void solve(int k, int n , int i, vector<int>&temp , vector<vector<int>>&res ){
        if(temp.size() == k){
            if(n == 0){
                    res.push_back(temp);
                }
            return;
        }
        if(n<0  || i>9){
            return;
        }
        temp.push_back(i);
        solve(k , n-i , i+1 ,temp , res);
        temp.pop_back();
        solve(k , n , i+1 , temp , res);
    }
    vector<vector<int>> combinationSum3(int k, int n ) {
        vector<int>temp;
        solve(k, n ,1,temp , res );
        return res;
        
    }
};
int main(){
    int k , n ;
    cin>> k >> n;
    Solution obj;
    vector<vector<int>>ans = obj.combinationSum3(k , n);
    for(auto &v : ans){
        for(auto &num : v){
            cout<< num << " ";
        }
        cout<< endl;
    }
    return 0;
}