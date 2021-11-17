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
    int cntLeft = 0;
    int cntRight = 0;
    
    int dfs(TreeNode* cur, int x) {
        if(cur == nullptr) return 0;
        int left = dfs(cur->left, x);
        int right = dfs(cur->right, x);
        if(cur->val == x) {
            cntLeft = left;
            cntRight = right;
        }
        return 1 + left + right;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        dfs(root, x);
        if(cntLeft > n - cntLeft) return true;
        if(cntRight > n - cntRight) return true;
        int rest = n - (cntLeft + cntRight + 1);
        return rest > n - rest;
    }
};