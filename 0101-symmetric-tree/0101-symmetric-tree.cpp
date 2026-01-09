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
    TreeNode* invert(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        TreeNode* node = new TreeNode(root->val);

        // Recursively create mirrored children
        node->left = invert(root->right);
        node->right = invert(root->left);

        return node;
    }
    bool checkSymmetric(TreeNode* a, TreeNode* b) {
        if (!a && !b)
            return true;
        if (!a || !b)
            return false;
        if (a->val != b->val)
            return false;

        return checkSymmetric(a->left, b->left) &&
               checkSymmetric(a->right, b->right);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        TreeNode* invertedRoot = invert(root);
        return checkSymmetric(root, invertedRoot);
    }
};