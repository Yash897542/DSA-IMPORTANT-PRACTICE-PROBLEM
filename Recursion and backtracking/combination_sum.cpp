#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public :
    void findcombin(int i , vector<int>&arr , vector<vector<int>>&ans , vector<int>&combine , int target){
      if(target == 0){
          ans.push_back(combine);
          return ;
      }
      if(i >= arr.size() || target < 0){
          return ;
      }
      combine.push_back(arr[i]);
      findcombin(i , arr , ans , combine , target - arr[i]);
      combine.pop_back();
      findcombin(i+1 , arr , ans , combine , target);

    }
};
int main(){
    int n ;
    cin>> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++){
        cin>> arr[i];
    }
    int target ;
    cin>> target;
    solution obj;
    vector<vector<int>>ans;
    vector<int>combine;
    obj.findcombin(0 , arr , ans , combine , target);
    for(auto &v : ans){
        for(auto &num : v){
            cout<< num << " ";
        }
        cout<< endl;
    }
    return 0;
}
