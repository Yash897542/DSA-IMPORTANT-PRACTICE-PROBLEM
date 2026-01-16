#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
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
class Solution{
    public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int height = 1;
        bst(root , height);
        if(height){
            return true;
        }
        else{
            return false;
        }
    }
    int bst(TreeNode* root , int &height){
        if(root == NULL){
            return 0;
        }
        int left = bst(root->left,height) + 1;
        int right = bst(root->right , height) + 1;
        if(abs(left-right) > 1){
           return height = 0;
        }
        else{
             return max(left , right);
           }
        }
    };
    int main(){
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->left->left->left = new TreeNode(8);
        Solution obj;
        bool result = obj.isBalanced(root);
        if(result){
            cout<<"The binary tree is balanced"<<endl;
        }
        else{
            cout<<"The binary tree is not balanced"<<endl;
        }
        return 0;
    }
