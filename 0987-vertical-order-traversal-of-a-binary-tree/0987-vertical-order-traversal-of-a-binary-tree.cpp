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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // 1. BFS

        // key: row, col | value: val
        map<pair<int,int>, multiset<int>> map1;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(q.size() > 0) {
            auto cur = q.front();
            q.pop();
            auto curNode = cur.first;
            int curRow = cur.second.first;
            int curCol = cur.second.second;

            map1[{curRow, curCol}].insert(curNode->val);

            if(curNode->left != nullptr) {
                q.push({curNode->left, {curRow + 1, curCol - 1}});
            }
            if(curNode->right != nullptr) {
                q.push({curNode->right, {curRow + 1, curCol + 1}});
            }
        }

        // 2. convert map1 -> map2

        // key: col | value: val
        map<int, vector<int>> map2;

        for(auto it : map1) {
            int col = it.first.second;
            for(int val : it.second) {
                map2[col].push_back(val);
            }
        }

        // 3. convert map2 -> 2d vector
        vector<vector<int>> ans;

        for(auto it : map2) {
            ans.push_back(it.second);
        }

        return ans;
    }
};