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
    int parseNum(string& s, int& idx) {
        bool isNegative = false;
        if(s[idx] == '-') {
            isNegative = true;
            ++idx;
        }
        int ret = 0;
        while(idx < s.size() && isdigit(s[idx])) {
            ret = ret * 10 + s[idx] - '0';
            ++idx;
        }
        return isNegative ? -ret : ret;
    }
// 0123456789012345
// 4(2(3)(1))(6(5))
//                ^
/*

*/
    TreeNode* buildTree(string& s, int& idx) {
        if(!isdigit(s[idx]) && s[idx] != '-') {
            return nullptr;
        }
        int val = parseNum(s, idx); // 4, 2, 3, 1
        auto ret = new TreeNode(val);
        if(idx < s.size() && s[idx] == '(') {
            ++idx;
            ret->left = buildTree(s, idx);
        }
        if(idx < s.size() && s[idx] == '(') {
            ++idx;
            ret->right = buildTree(s, idx);
        }
        ++idx;
        return ret;
    }
public:
    TreeNode* str2tree(string s) {
        int idx = 0;
        return buildTree(s, idx);
    }
};