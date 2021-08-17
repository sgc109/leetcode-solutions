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
        reverse(begin(path1), end(path1));
        reverse(begin(path2), end(path2));
        for(auto pp : path1) {
            cout << pp->val << ' ';
        }
        cout << endl;
        for(auto pp : path2) {
            cout << pp->val << ' ';
        }
        int i;
        for(i = 1; i < path1.size() && i < path2.size(); i++) {
            if(path1[i] != path2[i]) break;
        }
        return path1[i - 1];
    }
};