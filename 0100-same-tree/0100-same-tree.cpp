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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr && q != nullptr) {
            return false;
        }
        if (p != nullptr && q == nullptr) {
            return false;
        }
        queue<TreeNode*> pQ;
        queue<TreeNode*> qQ;
        pQ.push(p);
        qQ.push(q);
        while(!pQ.empty() && !qQ.empty()) {
            TreeNode* pCurr = pQ.front();
            TreeNode* qCurr = qQ.front();
            cout<<pCurr->val<<" "<<qCurr->val<<"\n";
            pQ.pop();
            qQ.pop();
            if (pCurr->val != qCurr->val) {
                return false;
            }
            if (pCurr->left && qCurr->left) {
                pQ.push(pCurr->left);
                qQ.push(qCurr->left);
            }
            if (pCurr->right && qCurr->right) {
                pQ.push(pCurr->right);
                qQ.push(qCurr->right);
            }
            if (pCurr->left && !qCurr->left) {
                return false;
            }
            if (!pCurr->left && qCurr->left) {
                return false;
            }
            if (pCurr->right && !qCurr->right) {
                return false;
            }
            if (!pCurr->right && qCurr->right) {
                return false;
            }
        }
        return pQ.empty() && qQ.empty();
        
    }
};