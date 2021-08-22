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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr) {
            return ret;
        }
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        int level = 0;
        while(!q.empty()) {
            vector<int> forPush;
            while(!q.empty() && q.front().first == level) {
                auto node = q.front().second;
                q.pop();
                forPush.push_back(node->val);
                if(node->left != nullptr) {
                    q.push({level + 1, node->left});
                }
                if(node->right != nullptr) {
                    q.push({level + 1, node->right});
                }
            }
            ret.push_back(forPush);
            level++;
        }
        
        return ret;
    }
};
