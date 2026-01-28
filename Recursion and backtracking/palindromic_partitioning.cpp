#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<string>>ans;
    bool ispalind(string s){
        string s2 = s;
        reverse(s2.begin() , s2.end());
        return s == s2;
    }
    void solve(string s , vector<string>&partitions){
        if(s.size() == 0){
            ans.push_back(partitions);
            return;
        }
        for(int i = 0 ; i<s.size() ; i++){
            string part = s.substr(0 , i+1);
            if(ispalind(part)){
                partitions.push_back(part);
                solve(s.substr(i+1) , partitions);
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>partitions;
        solve(s , partitions);
        return ans;
    }
};
int main(){
    string s;
    cin>> s;
    Solution obj;
    vector<vector<string>>result = obj.partition(s);
    for(auto &vec : result){
        for(auto &val : vec){
            cout<< val << " ";
        }
        cout<< endl;
    }
    return 0;
}
