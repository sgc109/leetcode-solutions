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
    int maxLevelSum(TreeNode* root) {
        vector<int> sums;
        queue.push({root, 0});
        while(!queue.empty()) {
            auto cur = queue.front();
            queue.pop();
            auto node = cur.first;
            if(node == nullptr) continue;
            int dist = cur.second;
            if(sums.size() <= dist) {
                sums.push_back(0);
            }
            sums[dist] += node->val;
            queue.push({node->left, dist + 1});
            queue.push({node->right, dist + 1});
        }
        int maxNum = -1000000001;
        int idx = -1;
        for(int i = 0; i < sums.size(); ++i) {
            if(sums[i] > maxNum) {
                maxNum = sums[i];
                idx = i;
            }
        }
        
        return idx + 1;
    }
};