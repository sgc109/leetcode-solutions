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
    bool compare(TreeNode* t1, TreeNode* t2) {
        if((t1 == nullptr) != (t2 == nullptr)) return false;
        if(t1 == nullptr) return true;
        if(t1->val != t2->val) return false;
        return compare(t1->left, t2->left) 
            && compare(t1->right, t2->right);
    }
    
    bool dfs(TreeNode* cur, TreeNode* target) {
        if(cur == nullptr) return false;
        return dfs(cur->left, target) ||
            dfs(cur->right, target) ||
            compare(cur, target);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};
