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
    int diameter = 0; // Global variable to store diameter length

    // Helper function to compute height and update diameter
    int height(TreeNode* node) {
        if (node == nullptr)
            return 0;

        // Recursively get height of left and right subtrees
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Update the diameter if the path through this node is larger
        diameter =
            max(diameter,
                leftHeight +
                    rightHeight); // If we have to consider nodes as part of
                                  // diameter, then we add 1 and if diameter is
                                  // considered as edges then we don't add 1

        // Return height of this subtree
        return 1 + max(leftHeight, rightHeight);
    }

    // Function to get the diameter
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};