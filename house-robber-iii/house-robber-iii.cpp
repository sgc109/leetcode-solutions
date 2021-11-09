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
    struct TwoMaxForChild {
        int selected;
        int unselected;
    };
    TwoMaxForChild dfs(TreeNode* cur) {
        if(cur == nullptr) return TwoMaxForChild{0, 0};
        auto leftAns = dfs(cur->left);
        auto rightAns = dfs(cur->right);
        return TwoMaxForChild{
            cur->val + leftAns.unselected + rightAns.unselected,
            max(leftAns.selected, leftAns.unselected) + max(rightAns.selected, rightAns.unselected)
        };
    }
public:
    int rob(TreeNode* root) {
        auto ans = dfs(root);
        return max(ans.selected, ans.unselected);
    }
};