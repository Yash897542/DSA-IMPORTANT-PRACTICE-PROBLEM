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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int level = q.size();
            TreeNode* curr = NULL;
            for(int i = 0 ; i<level ; i++){
                curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ans.push_back(curr->val);
        }
        
        return ans;
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution obj;
    vector<int> result = obj.rightSideView(root);

    cout << "Right Side View of the Binary Tree: ";
    for(int i = 0 ; i<result.size() ; i++){
        cout<< result[i]<< " ";
    }
    cout<< endl;

    return 0;
}