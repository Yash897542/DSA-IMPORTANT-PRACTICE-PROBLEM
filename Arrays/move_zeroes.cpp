#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int insertPos = 0;

        // Step 1: Move all non-zero elements to the front
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[insertPos] = nums[i];
                insertPos++;
            }
        }

        // Step 2: Fill the remaining positions with zeros
        while (insertPos < n) {
            nums[insertPos] = 0;
            insertPos++;
        }
    }
};
int main(){
    Solution s;
    vector<int> nums = {0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    for(int i : nums){
        cout << i << " ";
    }
    cout << endl; // Output: [1, 3, 12, 0, 0]
    return 0;
}