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
    vector<int> largestValues(TreeNode* root) {
        if(!root) {
            return vector<int>();
        }
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(q.size() > 0) {
            auto front = q.front();
            q.pop();
            auto curNode = front.first;
            int level = front.second;

            if(ans.size() == level) {
                ans.push_back(curNode->val);
            } else {
                ans.back() = max(ans.back(), curNode->val);
            }
            
            if(curNode->left) {
                q.push({curNode->left, level + 1});
            }
            if(curNode->right) {
                q.push({curNode->right, level + 1});
            }
        }

        return ans;
    }
};