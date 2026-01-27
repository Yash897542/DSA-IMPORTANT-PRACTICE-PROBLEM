#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
class solution{
    public :
    vector<vector<int>> result;
    unordered_set<int>s;
    void solve(vector<int>&nums , vector<int>&temp){
        if(temp.size() == nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i = 0 ; i<nums.size() ; i++){
            if(s.find(nums[i]) == s.end()){
                s.insert(nums[i]);
                temp.push_back(nums[i]);
                solve(nums , temp);
                temp.pop_back();
                s.erase(nums[i]);
            }
        }
    }
};
int main(){
    int n;
    cin>> n;
    vector<int>nums(n);
    for(int i = 0 ; i<n ; i++){
        cin>> nums[i];
    }
    solution obj;
    vector<int>temp;
    obj.solve(nums , temp);
    for(auto &vec : obj.result){
        for(auto &val : vec){
            cout<< val << " ";
        }
        cout<< endl;
    }
    return 0;
}
