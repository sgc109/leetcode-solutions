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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> childToParent;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            auto cur = queue.front();
            queue.pop();
            if(cur->left) {
                childToParent[cur->left] = cur;
                queue.push(cur->left);
            }
            if(cur->right) {
                childToParent[cur->right] = cur;
                queue.push(cur->right);
            }  
        }
        unordered_set<TreeNode*> visited;
        
        while(p || q) {
            if(p && visited.count(p)) {
                return p;
            }
            visited.insert(p);
            if(q && visited.count(q)) {
                return q;
            }
            visited.insert(q);
            if(p) {
                p = childToParent[p];
            }
            if(q) {
                q = childToParent[q];
            }
        }
        return nullptr;
    }
};