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
    ll MOD = 1e9+7;
    ll hashes[10003];
    bool compare(TreeNode* t1, TreeNode* t2) {
        if((t1 == nullptr) != (t2 == nullptr)) return false;
        if(t1 == nullptr) return true;
        if(t1->val != t2->val) return false;
        return compare(t1->left, t2->left) 
            && compare(t1->right, t2->right);
    }
    
    pair<ll, pair<int, bool>> find(TreeNode* cur, TreeNode* target, ll targetHash) {
        if(cur == nullptr) return {0, {0, false}};
        auto left = find(cur->left, target, targetHash);
        auto right = find(cur->right, target, targetHash);
        if(left.second.second || right.second.second) return {0, {0, true}};
        ll newHash = (hashes[right.second.first + 1] * left.first + right.first * 20002 + (cur->val + 10001)) % MOD;
        bool found = false;
        if(newHash == targetHash) {
            found = compare(cur, target);
        }
        return {newHash, {left.second.first + right.second.first + 1, found}};
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        hashes[0] = 1;
        for(int i = 1; i <= 10001; i++) {
            hashes[i] = hashes[i - 1] * 20002 % MOD;
        }
        auto p = find(subRoot, nullptr, -1);
        ll targetHash = p.first;
        auto ret = find(root, subRoot, targetHash);
        return ret.second.second;
    }
};