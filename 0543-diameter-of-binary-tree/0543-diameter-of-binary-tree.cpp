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
    int dfs(TreeNode* cur, int dist, int& ans) {
        if(!cur) {
            return 0;
        }
        
        int leftMaxDist = dfs(cur->left, dist + 1, ans);
        int rightMaxDist = dfs(cur->right, dist + 1, ans);

        int maxDist = max(leftMaxDist, rightMaxDist);
        ans = max(ans, leftMaxDist + rightMaxDist);
        ans = max(ans, maxDist + dist);
        
        return maxDist + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
};