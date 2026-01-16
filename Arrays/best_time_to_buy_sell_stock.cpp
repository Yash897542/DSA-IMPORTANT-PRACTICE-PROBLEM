#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int bestbuy=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>bestbuy){
                maxprofit=max(maxprofit,prices[i]-bestbuy);
            }
            bestbuy=min(bestbuy,prices[i]);
        }
        return maxprofit;
        
    }
};
int main(){
    vector<int>prices={7,1,5,3,6,4};
    Solution obj;
    int result=obj.maxProfit(prices);
    cout<<"The maximum profit is: "<<result<<endl;
    return 0;
}