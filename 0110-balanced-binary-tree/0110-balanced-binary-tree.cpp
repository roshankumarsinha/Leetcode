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
    int height(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        if (leftHeight == -1) {
            return -1;
        }
        if (rightHeight == -1) {
            return -1;
        }
        int diff = abs(leftHeight - rightHeight);
        if (diff > 1) {
            return - 1;
        }
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        if (height(root) == -1) {
            return false;
        } else {
            return true;
        }
    }
};