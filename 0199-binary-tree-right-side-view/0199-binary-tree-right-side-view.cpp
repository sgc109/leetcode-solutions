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


      1
    2   3
     5   4

        1
      2   3
    4 
   5 

     1
       3
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) { // 1
        vector<int> ans; // []
        if(!root) {
            return ans;
        }
        queue<pair<TreeNode*,int>> q; // []
        q.push({root, 0});
        while(!q.empty()) {
            auto [cur, level] = q.front(); // (3,1)
            q.pop();
            if(ans.size() == level) {
                ans.push_back(cur->val);
            }
            if(cur->right) {
                q.push({cur->right, level + 1});
            }
            if(cur->left) {
                q.push({cur->left, level + 1});
            }
        }
        return ans;
    }
};