#include<iostream>
#include<vector>
#include<algorithm>
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
    int search(vector<int>& inorder , int left , int right , int value){
        for(int i = left ; i<=right ; i++){
            if(inorder[i] == value){
                return i;
            }
        }
        return -1;
    }
    TreeNode * helper(vector<int>& preorder , vector<int>& inorder , int left , int right , int &preindex){
        if(left>right){
            return NULL;
        }
        TreeNode*root = new TreeNode(preorder[preindex]);
        int index = search(inorder , left , right ,preorder[preindex]);
        preindex++;

       root->left = helper(preorder , inorder , left , index-1 , preindex);
       root->right = helper(preorder , inorder , index+1 , right , preindex);
       return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex = 0;
        return helper(preorder , inorder , 0 , inorder.size()-1 , preindex);
        
    }
};
int main(){
    vector<int>preorder = {3,9,20,15,7};
    vector<int>inorder = {9,3,15,20,7};
    Solution obj;
    TreeNode*root = obj.buildTree(preorder , inorder);
    cout<<"The root of the constructed binary tree is: "<<root->val<<endl;
    return 0;
}