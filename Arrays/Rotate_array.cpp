#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(n == 0){
            return ;
        }
        reverse(nums.begin(),nums.end());
        reverse(nums.begin() , nums.begin() + k);
        reverse(nums.begin() + k , nums.end());
    }
};
int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    s.rotate(nums , k);
    for(int i : nums){
        cout << i << " ";
    }
    cout << endl; // Output: [5, 6, 7, 1, 2, 3, 4]
    return 0;
}