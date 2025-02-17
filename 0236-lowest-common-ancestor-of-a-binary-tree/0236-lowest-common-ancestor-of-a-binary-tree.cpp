/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<TreeNode*> rootToP;
    vector<TreeNode*> rootToQ;
    TreeNode *p, *q;
    void dfs(TreeNode* cur, vector<TreeNode*>& fromRoot) {
        if(!cur) {
            return;
        }
        fromRoot.push_back(cur);
        if(cur == p) {
            rootToP = fromRoot;
        } else if(cur == q) {
            rootToQ = fromRoot;
        }

        dfs(cur->left, fromRoot);
        dfs(cur->right, fromRoot);

        fromRoot.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        
        vector<TreeNode*> fromRoot;
        dfs(root, fromRoot);
        int i;
        for(i = 0; i < min(size(rootToP), size(rootToQ)); ++i) {
            if(rootToP[i]->val != rootToQ[i]->val) {
                break;
            }
        }
        return rootToP[i - 1];
    }
};
