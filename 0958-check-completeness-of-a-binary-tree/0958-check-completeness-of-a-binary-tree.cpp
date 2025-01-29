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
const int INF = 101;
class Solution {
    int dfs(TreeNode* cur, int id) {
        if(!cur) {
            return -1;
        }
        if(id >= INF) {
            return INF;
        }
        return max({id, dfs(cur->left, id * 2), dfs(cur->right, id * 2 + 1)});
    }
    bool dfs2(TreeNode* cur, int id, int maxId) {
        if(!cur) {
            return id > maxId;
        }
        return dfs2(cur->left, id * 2, maxId) && dfs2(cur->right, id * 2 + 1, maxId);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int maxId = dfs(root, 1);
        if(maxId == INF) {
            return false;
        }
        return dfs2(root, 1, maxId);
    }
};