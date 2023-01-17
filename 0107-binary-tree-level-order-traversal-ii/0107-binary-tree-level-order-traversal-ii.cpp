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
    void dfs(TreeNode* cur, int depth, vector<vector<int>>& ans) {
        if(cur == nullptr) return;
        if(ans.size() <= depth) {
            ans.push_back(vector<int>());
        }
        dfs(cur->left, depth + 1, ans);
        dfs(cur->right, depth + 1, ans);
        ans[depth].push_back(cur->val);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret = vector<vector<int>>();
        dfs(root, 0, ret);
        reverse(begin(ret), end(ret));
        return ret;
    }
};