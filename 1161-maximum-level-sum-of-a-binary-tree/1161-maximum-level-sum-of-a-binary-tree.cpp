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
    unordered_map<int, int> sumPerLevel;
    int maxLevel = -1;
    void dfs(TreeNode* cur, int level) {
        if(cur == nullptr) return;
        sumPerLevel[level] += cur->val;
        maxLevel = max(maxLevel, level);
        
        dfs(cur->left, level + 1);
        dfs(cur->right, level + 1);
    }
public:
    int maxLevelSum(TreeNode* root) {
        dfs(root, 1);
        
        int ansLevel;
        int ans = -1e9 - 1;
        for(int i = 1; i <= maxLevel; ++i) {
            if(ans < sumPerLevel[i]) {
                ans = sumPerLevel[i];
                ansLevel = i;
            }
        }
        
        return ansLevel;
    }
};