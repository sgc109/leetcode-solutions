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
    pair<TreeNode*, int> dfs(TreeNode* cur) {
        TreeNode* ret = cur;
        int deepest = 0;
        vector<TreeNode*> children({cur->left, cur->right});
        for(auto child: children) {
            if(child == nullptr) {
                continue;
            }
            auto [childAns, depth] = dfs(child);
            if(deepest == depth) {
                ret = cur;
            } else if(deepest < depth) {
                ret = childAns;
                deepest = depth;
            }
        }
        return {ret, deepest + 1};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};