/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool dfs(TreeNode* cur, TreeNode* target, vector<TreeNode*>& path) {
        if(!cur) {
            return false;
        }
        path.push_back(cur);
        if(cur == target) {
            return true;;
        }
        if(dfs(cur->left, target, path)) {
            return true;
        }
        if(dfs(cur->right, target, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        dfs(root, p, path1);
        dfs(root, q, path2);
        int pos = 0;
        while(pos < path1.size() && pos < path2.size()) {
            if(path1[pos] != path2[pos]) {
                break;
            }
            ++pos;
        }
        return path1[pos - 1];
    }
};