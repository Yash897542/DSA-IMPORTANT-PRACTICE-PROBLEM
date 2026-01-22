#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    vector<vector<int>>ans;
    void solve(int index , int n , int k , vector<int>&temp){
        if(k == 0){
            ans.push_back(temp);
            return;
        }
        if(index > n){
            return;
        }
        temp.push_back(index);
        solve(index+1 , n ,k-1 , temp);
        temp.pop_back();
        solve(index+1 , n , k ,temp);
    }
    vector<vector<int>> combine(int n , int k){
        vector<int>temp;
        solve(1 , n , k , temp);
        return ans;
    }
};
int main(){
    int n = 4, k = 2;
    solution obj;
    vector<vector<int>>res = obj.combine(n,k);
    for(int i = 0 ; i<res.size() ; i++){
        cout<<"[";
        for(int j = 0 ; j<res[i].size() ; j++){
            cout<<res[i][j];
            if(j != res[i].size()-1){
                cout<<',';
            }
        }
        cout<<"]";
        if(i != res.size()-1){
            cout<<',';
        }
    }
    return 0;
}