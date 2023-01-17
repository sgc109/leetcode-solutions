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
    queue<pair<TreeNode*, int>> queue;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret = vector<vector<int>>();
        queue.push({root, 0});
        while(!queue.empty()) {
            auto cur = queue.front();
            queue.pop();
            auto node = cur.first;
            if(node == nullptr) continue;
            int dist = cur.second;
            if(ret.size() <= dist) {
                ret.push_back(vector<int>());
            }
            ret[dist].push_back(node->val);
            queue.push({node->left, dist + 1});
            queue.push({node->right, dist + 1});
        }
        reverse(begin(ret), end(ret));
        return ret;
    }
};