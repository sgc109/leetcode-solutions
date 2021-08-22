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
typedef long long ll;
class Solution {
    bool isValidBST(TreeNode* root, ll lo, ll hi) {
        if(root == nullptr) {
            return true;
        }
        if(root->val <= lo || root->val >= hi) {
            return false;
        }
        return isValidBST(root->left, lo, root->val)
            && isValidBST(root->right, root->val, hi);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, -1e18, 1e18);
    }
};