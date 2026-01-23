#include<iostream>
#include<vector>
#include<string>
using namespace std;
class solution{
    public :
    bool isvalid(string &curr , int n ){
        int count = 0;
        for(char ch : curr){
            if(ch == '('){
                count ++;
            }
            else{
                count--;
            }
            if(count<0){
                return false;
            }
        }
        return count == 0;
    }
    vector<string>ans;
    void solve(string &curr , int n){
        if(curr.length() == 2*n){
            if(isvalid(curr,n)){
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr ,n);
        curr.pop_back();
        curr.push_back(')');
        solve(curr ,n);
        curr.pop_back();

        }
    vector<string> generateparenthesis(int n ){
        string curr = "";
        solve(curr , n);
        return ans;
    }
};
int main(){
    int n ;
    cin>> n;
    solution obj;
    vector<string>res = obj.generateparenthesis(n);
    cout<<"[";
    for(int i = 0 ; i<res.size() ; i++){
        if(i != 0){
            cout<<",";
        }
        for(int j = 0 ; j<res[i].length() ; j++){
            cout<<res[i][j];
        }
    }
    cout<<"]";
    return 0;
}