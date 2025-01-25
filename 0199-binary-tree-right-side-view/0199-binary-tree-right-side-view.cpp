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
        if(root == nullptr) {
            return vector<int>();
        }
        vector<TreeNode*> list = {root};
        vector<int> ans;
        while(list.size() > 0) {
            ans.push_back(list.back()->val);
            vector<TreeNode*> tmpList;
            for(auto node : list) {
                if(node->left != nullptr) {
                    tmpList.push_back(node->left);
                }
                if(node->right != nullptr) {
                    tmpList.push_back(node->right);
                }
            }
            list = tmpList;
        }
        
        return ans;
    }
};