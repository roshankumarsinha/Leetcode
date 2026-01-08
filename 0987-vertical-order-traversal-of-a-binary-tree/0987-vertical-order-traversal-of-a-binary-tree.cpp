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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result; // Vector to store the nodes of the tree
        if (root == NULL) {
            return result;
        }

        map<int, map<int, vector<int>>> nodes; // Map to store the nodes at each
                                               // horizontal distance and depth

        queue<pair<TreeNode*, pair<int, int>>>
            q; // Queue to store the nodes of the tree along with their
               // horizontal distance and depth
        q.push({root, {0, 0}}); // Push the root node along with its horizontal
                                // distance and depth, or we can write as
                                // q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty()) {
            TreeNode* current = q.front().first; // Get the current node
            int hd = q.front().second.first; // Get the horizontal distance of
                                             // the current node
            int depth = q.front().second.second; // Get the depth or level of
                                                 // the current node
            q.pop();                             // Pop the front element

            nodes[hd][depth].push_back(
                current->val); // Store the current node in the map

            if (current->left) {
                q.push({current->left,
                        {hd - 1,
                         depth + 1}}); // Push the left child along with its
                                       // horizontal distance and depth, as
                                       // horizontal distance of left child will
                                       // be -1 but depth will increase by 1
            }
            if (current->right) {
                q.push(
                    {current->right,
                     {hd + 1,
                      depth + 1}}); // Push the right child along with its
                                    // horizontal distance and depth, as
                                    // horizontal distance of right child will
                                    // be +1 but depth will increase by 1
            }
        }

        for (auto it :
             nodes) { // Iterate through the map, it is a pair of horizontal
                      // distance and a map of depth and vector of nodes
            vector<int> column;
            for (auto itr : it.second) { // Iterate through the map of depth and
                                         // vector of nodes
                sort(itr.second.begin(), itr.second.end());
                for (int val : itr.second) {
                    column.push_back(val);
                }
            }
            result.push_back(column);
        }

        return result;
    }
};