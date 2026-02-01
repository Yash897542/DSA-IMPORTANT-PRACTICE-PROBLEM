#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxlen = 0;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]] <= k){
                maxlen = max(maxlen , j-i+1);
            }
             while(mp[nums[j]] > k){
             mp[nums[i]]--;
             i++;
            }
            j++;
        }
        return maxlen;
    }
};
int main(){
    int n ;
    cin>> n;
    vector<int>nums(n);
    for(int i = 0 ; i < n ; i++){
        cin>> nums[i];
    }
    int k ;
    cin>> k ;
    Solution obj;
    int result = obj.maxSubarrayLength(nums , k);
    cout<< result << endl;
    return 0;
}