#include<iostream>
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
class solution{
    public :
    TreeNode *nextright = NULL;
    void flatten(TreeNode* root){
        if(root == NULL){
            return;
        }
        flatten(root->right);
        flatten(root->left);
        
        root->left = NULL;
        root->right = nextright;
        nextright = root;
    }
};
int main(){
    TreeNode*root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5); 
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    solution obj;
    obj.flatten(root);
    cout<<"The flattened linked list is:"<<endl;
    TreeNode* curr = root;
    while(curr != NULL){
        cout<<curr->val<<" ";
        curr = curr->right;
    }
    return 0;
}