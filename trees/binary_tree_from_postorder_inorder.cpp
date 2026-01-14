#include<iostream>
#include<vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
class Solution { 
public:
     TreeNode* solve(vector<int>& inorder , vector<int>& postorder , int Instart , int Inend , int Poststart ,int Postend){
        if(Instart > Inend){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[Postend]);
        int i = Instart;
        for(; i<=Inend ; i++){
            if(inorder[i] == root->val){
                break;
            }
        }
            int leftsize = i-Instart;
            int rightsize = Inend-i;
            root->left = solve(inorder , postorder , Instart , i-1 ,Poststart , Poststart+leftsize-1 );
            root->right = solve(inorder , postorder , i+1 , Inend , Postend-rightsize , Postend-1);

            return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        
        int Instart = 0;
        int Inend = n-1;

        int Poststart = 0;
        int Postend = n-1;
        return solve(inorder , postorder , Instart , Inend , Poststart , Postend);
    }
};
int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution obj;
    TreeNode* root = obj.buildTree(inorder, postorder);

    // Simple output to verify the root value
    cout << "Root of the constructed Binary Tree: " << root->val << endl;

    return 0;
}
        