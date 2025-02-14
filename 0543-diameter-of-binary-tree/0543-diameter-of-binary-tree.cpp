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
     // cur = 1
     // dist = 0
     // ans = 0
    int dfs(TreeNode* cur, int& ans) {
        if(!cur) {
            return 0;
        }
        
        int leftMaxDist = dfs(cur->left, ans); // 0
        int rightMaxDist = dfs(cur->right, ans); // 0

        int maxDist = max(leftMaxDist, rightMaxDist); // 0
        ans = max(ans, leftMaxDist + rightMaxDist); // 0
        
        return maxDist + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) { // 1
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};