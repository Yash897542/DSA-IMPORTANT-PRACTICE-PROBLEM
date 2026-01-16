#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
    int maximum_array_sum(vector<int>&arr){
        int currentsum = 0;
        int maxsum = INT_FAST16_MIN;
        for(int value : arr){
            currentsum += value;
            maxsum = max(maxsum , currentsum);
            if(currentsum<0){
                currentsum = 0;
            }
        }
        return maxsum;

    }
};
int main(){
    vector<int>arr = {-2,1,-3,4,-1,2,1,-5,4};
    solution obj;
    int result = obj.maximum_array_sum(arr);
    cout<<"The maximum subarray sum is: "<<result<<endl;
    return 0;
}