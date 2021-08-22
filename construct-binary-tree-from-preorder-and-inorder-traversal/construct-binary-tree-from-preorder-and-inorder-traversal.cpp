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
/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
    unordered_map<int, int> index;
    TreeNode* dfs(
        int pos,
        int l, 
        int r, 
        vector<int>& preorder, 
        vector<int>& inorder
    ) {
        if(l > r) return nullptr;
        int num = preorder[pos];
        TreeNode* cur = new TreeNode(num);
        if(l < r) {
            int mid = index[num];
            cur->left = dfs(pos + 1, l, mid - 1, preorder, inorder);
            cur->right = dfs(pos + 1 + (mid - l), mid + 1, r, preorder, inorder);
        }
        return cur;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return dfs(0, 0, inorder.size() - 1, preorder, inorder);
    }
};