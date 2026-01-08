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
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        // If both are null then return true, as empty tree are considered
        // identical
        if (r1 == nullptr && r2 == nullptr)
            return true;

        // If any one of the tree is null and other one not then return false
        if (r1 == nullptr || r2 == nullptr)
            return false;

        // Use two queues for level order traversal
        queue<TreeNode*> q1, q2;
        q1.push(r1);
        q2.push(r2);

        while (!q1.empty() && !q2.empty()) {
            TreeNode* node1 = q1.front();
            TreeNode* node2 = q2.front();
            q1.pop();
            q2.pop();

            // Check if the current nodes are identical
            if (node1->val != node2->val)
                return false;

            // Check the left children
            if (node1->left && node2->left) {
                q1.push(node1->left);
                q2.push(node2->left);
            } else if (node1->left ||
                       node2->left) { // If one has left subtree, but other
                                      // doesn't have then, they are not
                                      // identical
                return false;
            }

            // Check the right children
            if (node1->right && node2->right) {
                q1.push(node1->right);
                q2.push(node2->right);
            } else if (node1->right ||
                       node2->right) { // If one has right subtree, but other
                                       // doesn't have then, they are not
                                       // identical
                return false;
            }
        }

        // If both queues are empty, the trees are identical
        return q1.empty() && q2.empty();
    }
};