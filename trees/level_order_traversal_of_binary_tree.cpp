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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int level = q.size();
            vector<int>levels;
            for(int i = 0 ; i<level ; i++){
                TreeNode*curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                levels.push_back(curr->val);
            }
            ans.push_back(levels);
        }
        return ans;
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution obj;
    vector<vector<int>> result = obj.levelOrder(root);

    cout << "Level Order Traversal of the Binary Tree:" << endl;
    for ( int i = 0; i < result.size(); i++)
    {
     for(int j = 0 ; j<result[i].size() ; j++){
        cout<< result[i][j]<< " ";
     }
        cout<<endl;
    }
    
    return 0;
}