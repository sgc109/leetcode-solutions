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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int dist = p.second;
            ans = max(ans, dist);
            auto cur = p.first;
            if(cur->left != nullptr) {
                q.push({cur->left, dist + 1});
            }
            if(cur->right != nullptr) {
                q.push({cur->right, dist + 1});
            }
        }
        return ans;
    }
};