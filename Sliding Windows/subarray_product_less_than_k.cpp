#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1){
            return 0;
        }
        int count = 0;
        int i = 0;
        int j = 0;
        int product = 1;
        while(j<n){
            product *= nums[j];
            while(product >= k){
                product /= nums[i];
                i++;
            }
            count += (j-i+1);
            j++;
        }
        return count;
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
    int result = obj.numSubarrayProductLessThanK(nums , k);
    cout<< result << endl;
    return 0;
}