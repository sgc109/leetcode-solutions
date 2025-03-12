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
    unordered_map<TreeNode*, TreeNode*> parents;
    unordered_set<TreeNode*> visited;
    vector<int> ans;
    void buildParents(TreeNode* cur) {
        if(cur->left) {
            parents[cur->left] = cur;
            buildParents(cur->left);
        }
        if(cur->right) {
            parents[cur->right] = cur;
            buildParents(cur->right);
        }
    }
    void dfs(TreeNode* cur, int dist) {
        if(!cur || visited.count(cur)) {
            return;
        }
        if(dist == 0) {
            ans.push_back(cur->val);
        }
        visited.insert(cur);
        dfs(cur->left, dist - 1);
        dfs(cur->right, dist - 1);
        dfs(parents[cur], dist - 1);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParents(root);
        dfs(target, k);
        return ans;
    }
};
