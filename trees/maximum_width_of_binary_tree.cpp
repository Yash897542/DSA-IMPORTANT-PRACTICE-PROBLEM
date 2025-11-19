#include<iostream>
#include<queue>
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , unsigned long long>>q;
        q.push({root , 0});
        int maximum = 0;
        while(q.size()>0){
            int currentlevel = q.size();
            unsigned long long st = q.front().second;
            unsigned long long end = q.back().second;
            maximum = max(maximum , (int)(end - st +1));
            for(int i = 0 ; i<currentlevel ; i++){
                auto curr = q.front();
                q.pop();
                if(curr.first->left){
                    q.push({curr.first->left , curr.second*2 + 1});
                    
                }
                if(curr.first->right){
                    q.push({curr.first->right , curr.second*2 + 2});
                }
            }
        }
       return maximum; 
    }
};
int main(){
    TreeNode*root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2); 
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    Solution obj;
    int maxWidth = obj.widthOfBinaryTree(root);
    cout<<"The maximum width of the binary tree is: "<<maxWidth<<endl;
    return 0;
}
