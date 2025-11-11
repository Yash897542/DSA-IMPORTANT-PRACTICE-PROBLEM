#include <iostream>
using namespace std;

/**
 * @brief Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    // Constructors
    TreeNode(int x){
        int val = x;
        left = nullptr;
        right = nullptr;
    }
};

/**
 * @brief Recursively counts the total number of nodes in a binary tree.
 * @param root A pointer to the root node.
 * @return The total number of nodes.
 */
int countNodes(TreeNode* root) {
    // Base case: An empty tree (or subtree) has 0 nodes
    if (root == nullptr) {
        return 0;
    }
    
    // Recursive step: 
    // The total count is 1 (for the current node)
    // plus the count from the left subtree
    // plus the count from the right subtree.
    return 1 + countNodes(root->left) + countNodes(root->right);
}

/**
 * @brief Main function to demonstrate the countNodes function.
 */
int main() {
    // --- Example Usage ---
    
    // Create a simple tree:
    //     1
    //    / \
    //   2   3
    //  /
    // 4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    // Call the function to count the nodes
    int total_nodes = countNodes(root);
    
    // Print the result
    std::cout << "The number of nodes in the tree is: " << total_nodes << std::endl; // Output: 4
    
    // --- Clean up allocated memory ---
    // (Note: For a simple example, we skip recursive deletion,
    // but in a real application, you'd delete all nodes properly)
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}