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
    void dfs(TreeNode* cur, double target, double& minDiff, int& ans) {
        double diff = abs(cur->val - target);
        if(minDiff > diff || (minDiff == diff && cur->val < ans)) {
            ans = cur->val;
            minDiff = diff;
        }
        if(cur->left && target <= cur->val) {
            dfs(cur->left, target, minDiff, ans);
        }
        if(cur->right && cur->val <= target) {
            dfs(cur->right, target, minDiff, ans);
        }
    }
public:
    int closestValue(TreeNode* root, double target) {
        int ans;
        double minDiff = INT_MAX;
        dfs(root, target, minDiff, ans);
        return ans;
    }
};