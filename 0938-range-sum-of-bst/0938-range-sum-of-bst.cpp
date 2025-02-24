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
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        stack<TreeNode*> stack;
        stack.push(root);
        int ans = 0;
        while(!stack.empty()) {
            auto cur = stack.top();
            stack.pop();
            if(low <= cur->val && cur->val <= high) {
                ans += cur->val;
            }
            if(cur->left && low <= cur->val) {
                stack.push(cur->left);
            }
            if(cur->right && cur->val <= high) {
                stack.push(cur->right);
            }
        }
        return ans;
    }
};