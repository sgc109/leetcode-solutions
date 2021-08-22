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
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        while(nodes.size() > 0) {
            vector<int> forPush;
            vector<TreeNode*> nextNodes;
            for(auto node : nodes) {
                forPush.push_back(node->val);
                if(node->left != nullptr) {
                    nextNodes.push_back(node->left);
                }
                if(node->right != nullptr) {
                    nextNodes.push_back(node->right);
                }
            }
            ret.push_back(forPush);
            nodes = nextNodes;
        }
        
        return ret;
    }
};