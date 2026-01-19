#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>nums1 = {1,2,3,0,0,0};
    vector<int>nums2 = {2,5,6};
    int m = nums1.size()-nums2.size();
    int n = nums2.size();
    int idx = m + n -1;
    int p1 = m-1;
    int p2 = n-1; 
    while(m>0 && n>0){
        if(nums1[p1]>nums2[p2]){
            nums1[idx] = nums1[p1];
            p1--;
            idx--;
        }
        else{
            nums1[idx] = nums2[p2];
            p2--;
            idx--;
        }
}
while(p2>=0){
    nums1[idx] = nums2[p2];
    p2--;
    idx--;
}
cout<<"Merged array: ";
for(int i=0;i<nums1.size();i++){
    cout<<nums1[i]<<" ";
}
return 0;
}