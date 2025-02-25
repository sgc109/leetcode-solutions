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
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int prevVal;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            auto curNode = cur.first;
            int curLevel = cur.second;
            if(ans.size() == curLevel - 1) {
                ans.push_back(prevVal);
            }
            prevVal = curNode->val;
            if(curNode->left) {
                q.push({curNode->left, curLevel + 1});
            }
            if(curNode->right) {
                q.push({curNode->right, curLevel + 1});
            }
        }
        ans.push_back(prevVal);
        return ans;
    }
};