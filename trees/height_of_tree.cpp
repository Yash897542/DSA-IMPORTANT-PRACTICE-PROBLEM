#include<iostream>
using namespace std;

struct TreeNode{
    int  val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        int val = x;
        left = NULL;
        right = NULL;
    }

};
int heightOfTree(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return 1 + max (leftHeight , rightHeight);
}
int main(){
    // Example Usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int height = heightOfTree(root);
    cout << "Height of the tree is: " << height << endl; // Output: 3

    return 0;
}