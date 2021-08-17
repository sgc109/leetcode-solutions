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
    bool dfs(TreeNode* t1, TreeNode* t2) {
        if((t1 == nullptr) != (t2 == nullptr)) return false;
        if(t1 == nullptr) return true;
        if(t1->val != t2->val) return false;
        return dfs(t1->left, t2->left) &&
            dfs(t1->right, t2->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
};