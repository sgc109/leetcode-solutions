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
    unordered_map<int, int> counts;
    unordered_map<int, int> maxIds;
    int maxLevel = -1;
    bool dfs(TreeNode* cur, int id, int level) {
        if(!cur) {
            return true;
        }
        if(id > 100) {
            return false;
        }
        maxLevel = max(maxLevel, level);
        counts[level]++;
        maxIds[level] = max(maxIds[level], id);
        
        return dfs(cur->left, id * 2, level + 1) && dfs(cur->right, id * 2 + 1, level + 1);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        bool canBeValid = dfs(root, 1, 0);
        if(!canBeValid) {
            return false;
        }
        for(int i = 0; i < maxLevel; ++i) {
            if(counts[i] != (1 << i) || maxIds[i] != (1 << (i + 1)) - 1) {
                return false;
            }
        }
        return maxIds[maxLevel] == ((1 << maxLevel) + counts[maxLevel] - 1);
    }
};