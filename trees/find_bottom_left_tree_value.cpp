#include<iostream>
#include<vector>
#include<queue>
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
int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>que;
        int node;
        int bottomleft;
        que.push(root);
        while(que.size()!=0){
            int n = que.size();
            while(n--){
                TreeNode*node = que.front();
                que.pop();
                bottomleft = node->val;
                if(node->right){
                    que.push(node->right);
                }
                if(node->left){
                    que.push(node->left);
                }
            }
            }
            return bottomleft;
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);

    Solution obj;
    int result = obj.findBottomLeftValue(root);

    cout << "Bottom Left Value of the Binary Tree: " << result << endl;

    return 0;
}   
        
