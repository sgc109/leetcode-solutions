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
    int dfs(TreeNode* cur, int num) {
        if(!cur->left && !cur->right) {
            return num + cur->val;
        }
        int ret = 0;
        if(cur->left) {
            ret += dfs(cur->left, (num + cur->val) * 10);
        }
        if(cur->right) {
            ret += dfs(cur->right, (num + cur->val) * 10);
        }
        return ret;
    }
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};