#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
class Solution {
public:
    int maximum;
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        } 
        int left = solve(root->left);
        int right = solve(root->right);
        int neeche_wala_accha = left + right + root->val;
        int koi_ek_accha = max(left, right) + root->val;
        int sirf_root_accha = root->val;
        maximum = max({maximum , neeche_wala_accha , koi_ek_accha , sirf_root_accha});
        return max(koi_ek_accha , sirf_root_accha);
    }
    int maxPathSum(TreeNode* root) {
        maximum = INT_MIN;
        solve(root);
        return maximum;
    }
};
int main(){
    Solution s;
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << s.maxPathSum(root) << endl; // Output: 42
    return 0;
}