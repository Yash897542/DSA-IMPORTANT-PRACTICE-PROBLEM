#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public :
    vector<vector<int>> mergeintervals(vector<vector<int>>& intervals){
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> merged;
        for(auto interval : intervals){
            if(merged.empty() || merged.back()[1] < interval[0]){
                merged.push_back(interval);
            }
            else{
                merged.back()[1] = max(merged.back()[1] , interval[1]);
            }
        }
        return merged;
    }
};
int main(){
    int n;
    cin>> n;
    vector<vector<int>> intervals(n , vector<int>(2));
    for(int i = 0 ; i<n ; i++){
        cin>> intervals[i][0] >> intervals[i][1];
    }
    solution obj;
    vector<vector<int>> result = obj.mergeintervals(intervals);
    for(auto interval : result){
        cout<< interval[0] << " " << interval[1] << endl;
    }
    return 0;
}