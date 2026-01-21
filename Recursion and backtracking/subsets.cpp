#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<vector<int>>result;
void findsubset(int i , vector<int>&nums , vector<int>&temp){
    if(i>=nums.size()){
        result.push_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    findsubset(i+1 , nums , temp);
    temp.pop_back();
    findsubset(i+1 , nums , temp);
}
int main(){
    vector<int>nums = {1,2,3};
    vector<int>temp;
    findsubset(0 , nums , temp);
    cout<<"all subsets are:"<<endl;
    for(int i = 0 ; i<result.size() ; i++){
        cout<<"[";
        for(int j = 0 ; j<result[i].size() ; j++){
            cout<<result[i][j];
            if(j!=result[i].size()-1){
                cout<<",";
            }
        }
        cout<<"]"<<endl;
    }
    return 0;
}