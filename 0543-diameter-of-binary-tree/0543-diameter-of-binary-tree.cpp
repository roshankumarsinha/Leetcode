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
    int ans=0;
    int fun(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int val1=fun(root->left);
        int val2=fun(root->right);
        ans=max(ans,val1+val2);
        return max(val1,val2)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        fun(root);
        return ans;
    }
};