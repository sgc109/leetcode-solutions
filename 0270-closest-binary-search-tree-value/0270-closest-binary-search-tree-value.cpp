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
    double minDiff = 2e9 + 1;
    int minTarget;
    void dfs(TreeNode* cur, double target) {
        if(!cur) {
            return;
        }
        double diff = abs(target - cur->val);

        if(diff < minDiff || (diff == minDiff && cur->val < minTarget)) {
            minDiff = diff;
            minTarget = cur->val;
        }
        if(cur->val < target) {
            dfs(cur->right, target);
        } else {
            dfs(cur->left, target);
        }
    }
public:
    int closestValue(TreeNode* root, double target) {
        dfs(root, target);
        return minTarget;
    }
};