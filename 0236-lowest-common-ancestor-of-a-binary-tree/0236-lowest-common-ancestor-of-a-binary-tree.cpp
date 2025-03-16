/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* dfs(TreeNode* cur, TreeNode* p, TreeNode* q) {
        if(cur == p || cur == q || cur == nullptr) {
            return cur;
        }
        auto left = dfs(cur->left, p, q);
        auto right = dfs(cur->right, p, q);
        if(!left) {
            return right;
        } else if(!right) {
            return left;
        } else {
            return cur;
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};