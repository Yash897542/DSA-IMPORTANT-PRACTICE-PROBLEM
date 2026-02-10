#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int maximum = INT_MIN;
        int minimum = INT_MAX;
        int i = 0;
        int j = 0;
        int l = 1;
        while(j<n){
            maximum = nums[j];
            minimum = nums[i];
            if(i<n && maximum > (long long)k*minimum){
                i++;
                minimum = nums[i];
            }
            l = max(l , j-i+1);
            j++;
        }
        return n-l;
        
    }
};
int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    cout << s.minRemoval(nums, k) << endl; // Output: 2
    return 0;
}