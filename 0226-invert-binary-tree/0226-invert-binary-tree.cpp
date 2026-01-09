/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            TreeNode* temp = nullptr;
            TreeNode* temp1 = nullptr;
            if (curr->left) {
                temp = curr->left;
                q.push(temp);
            }
            if (curr->right) {
                temp1 = curr->right;
                q.push(temp1);
            }
            curr->left = temp1;
            curr->right = temp;
            
        }
        return root;
    }
};