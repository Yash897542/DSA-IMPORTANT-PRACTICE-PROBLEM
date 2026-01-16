#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class solution{
    public:
    int maximum_subarray_sum_equals_k(vector<int>&arr , int k){
        int n = arr.size();
        int count = 0;
        for(int i = 0 ; i<n ; i++){
            int sum = 0;
            for(int j = i ; j<n ; j++){
                sum += arr[j];
                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }

};
int main(){
    vector<int>arr = {1,1,1};
    int k = 2;
    solution obj;
    int result = obj.maximum_subarray_sum_equals_k(arr ,k);
    cout<<"The number of subarrays with sum equal to k is "<<result<<endl;
    return 0;
}