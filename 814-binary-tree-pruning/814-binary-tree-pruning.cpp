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
    bool containingOne(TreeNode* cur) {
        if(cur == nullptr) return false;
        bool left = containingOne(cur->left);
        if(!left) cur->left = nullptr;
        bool right = containingOne(cur->right);
        if(!right) cur->right = nullptr;
        return cur->val == 1 || left || right;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool atLeast1One = containingOne(root);
        return !atLeast1One ? nullptr : root;
    }
};