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
    int ans = 0;
    unordered_map<ll,int> cntPaths;
    int dfs(TreeNode* curNode, ll prevSum, int targetSum) {
        if(curNode == nullptr) {
            return 0;
        }
        ll curSum = prevSum + curNode->val;
        
        int ans = cntPaths[curSum - targetSum];
        
        cntPaths[curSum]++;
        
        ans += dfs(curNode->left, curSum, targetSum);
        ans += dfs(curNode->right, curSum, targetSum);
        
        cntPaths[curSum]--;
        
        return ans;
        
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        cntPaths[0] = 1;
        return dfs(root, 0, targetSum);
    }
};


/*

cntPaths
{
  21: 1
  16: 1
  18: 1
}

acc[i] = acculation of the value of each node in a path from root to node i

sum[par..child] = acc[child] - acc[par[par]]


targetSum + cur.value



*/