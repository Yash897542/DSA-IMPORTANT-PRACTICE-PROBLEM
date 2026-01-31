#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int minpos = -1;
        int maxpos = -1;
        int probpos = -1;
        for(int i = 0 ; i<n ; i++){
                if(nums[i] == minK){
                minpos = i;
            }
            if(nums[i] == maxK){
                maxpos = i;
            }
            if(nums[i] < minK || nums[i] > maxK){
                probpos = i;
            }
            int smaller = min(minpos , maxpos);
            int temp = smaller - probpos;
            ans += (temp<=0)?0 : temp;
        }
        return ans;
    }
};
int main(){
    int n ;
    cin>> n;
    vector<int>nums(n);
    for(int i = 0 ; i < n ; i++){
        cin>> nums[i];
    }
    int minK , maxK ;
    cin>> minK >> maxK;
    Solution obj;
    long long result = obj.countSubarrays(nums , minK , maxK);
    cout<< result << endl;
    return 0;
}