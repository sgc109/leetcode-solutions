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

    5
   / \
  5   5


 */
class Solution {
    double minDiff = 2e9 + 1; // 3.428571
    int minTarget; // 1
    void dfs(TreeNode* cur, double target) { // cur = 1, target = 4.428571
        if(!cur) {
            return;
        }
        double diff = abs(target - cur->val); // 3.428571
        if(diff == 0) {
            minTarget = cur->val;
            return;
        }

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
    int closestValue(TreeNode* root, double target) { // root = 1, target = 4.428571
        dfs(root, target);
        return minTarget;
    }
};