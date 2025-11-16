#include <iostream>
#include<vector>
#include<string>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
class Solution {
public:
    void allpaths(TreeNode* root , string paths, vector<string>&ans){
        if(root->left == NULL && root->right == NULL){
            ans.push_back(paths);
            return;
        }
        if(root->left){
            allpaths(root->left , paths+"->"+to_string(root->left->val) , ans);
        }
        if(root->right){
            allpaths(root->right , paths+"->"+to_string(root->right->val) , ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string paths = to_string(root->val);
        vector<string>ans;
        allpaths(root , paths , ans);
        return ans;
    }
};
int main(){
    TreeNode*root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3); 
    root->left->right = new TreeNode(5);
    vector<string>result;
    Solution obj;
    result = obj.binaryTreePaths(root);
    cout<<"All root to leaf paths in the binary tree are: "<<endl;
    for(string path : result){
        cout<<path<<endl;
    }
    return 0;
}