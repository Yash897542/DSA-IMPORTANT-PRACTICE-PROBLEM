#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(auto num : nums){
            if(i == 0 || i == 1 || num != nums[i-2]){
                nums[i] = num;
                i++;
            }
        }
        return i;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0 ; i<n ; i++){
        cin>> nums[i];
    }
    Solution obj;
    cout<< obj.removeDuplicates(nums);
}