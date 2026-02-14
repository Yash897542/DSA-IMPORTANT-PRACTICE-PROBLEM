#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n , 0);
        vector<int>right(n , 0);
        stack<int>s;
        for(int i = n-1 ; i>=0 ; i--){
            while(s.size()>0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            right[i] = s.empty()? n : s.top();
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }

        for(int i = 0 ; i<n ; i++){
            while(s.size()>0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        int ans = 0;
        for(int i = 0 ; i<n ; i++){
            int width = right[i]-left[i]-1;
            int area = heights[i]*width;
            ans = max(ans , area);
        }
        return ans;
        
    }
};
int main(){
    Solution s;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << s.largestRectangleArea(heights) << endl; // Output: 10
    return 0;
}