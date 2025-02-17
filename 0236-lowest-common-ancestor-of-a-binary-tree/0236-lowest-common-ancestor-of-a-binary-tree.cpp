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
    vector<TreeNode*> rootToP; // [3, 5]
    vector<TreeNode*> rootToQ; // [3, 1]
    TreeNode *p, *q; // 5, 1
     // cur = 3, 1
     // fromRoot = [3, 1]
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

        if(rootToP.size() > 0 && rootToQ.size() > 0) {
            return;
        }

        dfs(cur->left, fromRoot);
        dfs(cur->right, fromRoot);

        fromRoot.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { // 3, 5, 1
        this->p = p;
        this->q = q;
        
        vector<TreeNode*> fromRoot;
        dfs(root, fromRoot);
        int i;
        for(i = 0; i < min(size(rootToP), size(rootToQ)); ++i) { // i = 1
            if(rootToP[i]->val != rootToQ[i]->val) {
                break;
            }
        }
        return rootToP[i - 1];
    }
};
