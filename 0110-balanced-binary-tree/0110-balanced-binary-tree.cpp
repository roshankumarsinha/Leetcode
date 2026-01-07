/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // Helper function returns height if subtree is balanced, else -1
    int checkHeight(TreeNode* node) {
        if (node == nullptr)
            return 0;

        // Check height of left subtree
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1)
            return -1; // Left subtree is not balanced, so we have to pass -1 up
                       // the call stack

        // Check height of right subtree
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1)
            return -1; // Right subtree is not balanced, so we have to pass -1
                       // up the call stack

        // If height difference is more than 1, tree is unbalanced
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // Return height if balanced
        return 1 + max(leftHeight, rightHeight);
    }

    // Main function to check if the tree is balanced
    bool isBalanced(TreeNode* root) {
        if (checkHeight(root) == -1) {
            return false;
        } else {
            return true;
        }
    }
};