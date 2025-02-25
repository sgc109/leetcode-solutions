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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) {
            return {};
        }
        unordered_map<int,int> levelToVal;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int maxLevel = 0;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            auto curNode = cur.first;
            int curLevel = cur.second;
            levelToVal[curLevel] = curNode->val;
            maxLevel = max(maxLevel, curLevel);
            if(curNode->left) {
                q.push({curNode->left, curLevel + 1});
            }
            if(curNode->right) {
                q.push({curNode->right, curLevel + 1});
            }
        }
        vector<int> ans;
        for(int i = 0; i <= maxLevel; ++i) {
            ans.push_back(levelToVal[i]);
        }
        return ans;
    }
};