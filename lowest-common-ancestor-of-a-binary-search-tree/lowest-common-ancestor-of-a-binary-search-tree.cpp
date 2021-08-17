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
    vector<TreeNode*> getPath(TreeNode* cur, TreeNode* target) {
        if(cur == target) return vector<TreeNode*>({target});
        if(cur == nullptr) return vector<TreeNode*>();
        vector<TreeNode*> left = getPath(cur->left, target);
        vector<TreeNode*> right = getPath(cur->right, target);
        vector<TreeNode*> ret;
        if(left.size() == 0 && right.size() == 0) return left;
        if(left.size() == 0) {
            ret = right;
        }
        else {
            ret = left;
        }
        ret.push_back(cur);
        return ret;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1 = getPath(root, p);
        vector<TreeNode*> path2 = getPath(root, q);
        int pos1 = path1.size() - 1;
        int pos2 = path2.size() - 1;
        while(pos1 >= 0 && pos2 >= 0) {
            if(path1[pos1] != path2[pos2]) {
                return path1[pos1 + 1];
            }
            pos1--, pos2--;
        }
        if(pos1 == -1) return path1[0];
        return path2[0];
    }
};
