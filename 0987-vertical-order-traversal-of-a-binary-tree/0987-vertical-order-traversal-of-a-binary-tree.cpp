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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> buckets;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto [curNode, coord] = q.front();
            auto [row, col] = coord;
            q.pop();
            buckets[col][row].insert(curNode->val);
            if(curNode->left) {
                q.push({curNode->left, {row + 1, col - 1}});
            }
            if(curNode->right) {
                q.push({curNode->right, {row + 1, col + 1}});
            }
        }
        vector<vector<int>> ans;
        for(auto [_, rows] : buckets) {
            vector<int> tmp;
            for(auto [_, vals] : rows) {
                tmp.insert(tmp.end(), vals.begin(), vals.end());
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};