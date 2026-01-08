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
    int maxSum(TreeNode* root, int& maxi) {
        if (root == nullptr) {
            return 0;
        }
        int leftTree = max(0, maxSum(root->left, maxi));
        int rightTree = max(0, maxSum(root->right, maxi));
        maxi = max(maxi, (leftTree + rightTree + root->val));
        return max(leftTree, rightTree) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = root->val;
        return max(maxSum(root, maxi), maxi);
    }
};