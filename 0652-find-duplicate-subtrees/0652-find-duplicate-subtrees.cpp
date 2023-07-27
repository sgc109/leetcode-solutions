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
    int newId = 1;
    unordered_map<string, int> triplet2id;
    unordered_map<string, int> counters;
    vector<TreeNode*> ans;
    int dfs(TreeNode* cur) {
        if(cur == nullptr) {
            return 0;
        }
        int leftId = dfs(cur->left);
        int rightId = dfs(cur->right);
        string key = to_string(leftId) + "," + to_string(rightId) + "," + to_string(cur->val);
        counters[key]++;
        if(counters[key] > 1) {
            if(counters[key] == 2) {
                ans.push_back(cur);
            }
            return triplet2id[key];
        }
        triplet2id[key] = newId;
        return newId++;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};