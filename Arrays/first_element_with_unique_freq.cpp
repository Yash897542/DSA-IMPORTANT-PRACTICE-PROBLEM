#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int , int>freq;
        unordered_map<int , int>freqcount;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            freq[nums[i]]++;
        }

        for(auto & x : freq){
            freqcount[x.second]++;
        }

        for(int num : nums){
            if(freqcount[freq[num]] == 1){
                return num;
            }
        }
        return -1;
        
        
        
    }
};
int main(){
    Solution s;
    vector<int> nums = {1, 2, 2, 3, 3, 3};
    cout << s.firstUniqueFreq(nums) << endl; // Output: 1
    return 0;
}