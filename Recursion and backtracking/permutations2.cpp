#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>>ans;
    void solve( unordered_map<int , int>&mp , vector<int>&temp , vector<int>& nums ){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(auto &it : mp){
            int num = it.first;
            int &count = it.second;
            if(count == 0){
                continue;
            }
            temp.push_back(num);
            count--;
            solve(mp , temp , nums);
            temp.pop_back();
            count++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int , int>mp;
        vector<int>temp;
        for(int i = 0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        solve(mp , temp , nums);
        return ans;
        
    }
};
int main(){
    int n;
    cin>> n;
    vector<int>nums(n);
    for(int i = 0 ; i<n ; i++){
        cin>> nums[i];
    }
    Solution obj;
    vector<vector<int>>result = obj.permuteUnique(nums);
    for(auto &vec : result){
        for(auto &val : vec){
            cout<< val << " ";
        }
        cout<< endl;
    }
    return 0;
}