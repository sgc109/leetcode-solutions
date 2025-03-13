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
    double minDiff = 2e9 + 1; // 3.428571
    int ans; // 1
    // root = [1], target = 4.428571
    void dfs(TreeNode* cur, double target) { // 1
        if(!cur) {
            return;
        }
        double diff = abs(cur->val - target); // 3.428571
        if(diff < minDiff || (diff == minDiff && cur->val < ans)) {
            minDiff = diff;
            ans = cur->val;
        }
        if(minDiff == 0.0) {
            return;
        } else if(cur->val < target) {
            dfs(cur->right, target);
        } else {
            dfs(cur->left, target);
        }
    }
public:
    int closestValue(TreeNode* root, double target) {
        dfs(root, target);
        return ans;
    }
};