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
    TreeNode* dfs(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* backup = root->left;        
        root->left = dfs(root->right);
        root->right = dfs(backup);
        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }
};