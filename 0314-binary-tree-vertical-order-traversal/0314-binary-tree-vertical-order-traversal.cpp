/*
Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

 

Example 1:

   3
  / \
 9  20
   /  \
  15   7

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Example 2:

      3
     / \
    9   8
   / \ / \
  4  0 1  7

Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]
Example 3:


                 1
                / \
               2   3
              / \ / \
             4 10 9 11
             \  
              5        
               \
                6

Input: root = [1,2,3,4,10,9,11,null,5,null,null,null,null,null,null,null,6]
Output: [[4],[2,5],[1,10,9,6],[3],[11]]
*/

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
    vector<vector<int>> verticalOrder(TreeNode* root) { // [3,9,8,4,0,1,7]
        if(!root) {
            return {};
        }
        queue<pair<TreeNode*, int>> queue; // [7]
        unordered_map<int, vector<int>> colToVals; // {0 -> [3, 0, 1], -1 -> [9], 1 -> [8], -2 -> [4], 2 -> [7]}
        
        queue.push({root, 0});
        int minCol = 101; // -2
        int maxCol = -101; // 2
        while(!queue.empty()) {
            auto cur = queue.front(); // 
            queue.pop();
            auto curNode = cur.first; // 9
            auto colNum = cur.second; // -1
            minCol = min(minCol, colNum);
            maxCol = max(maxCol, colNum);
            colToVals[colNum].push_back(curNode->val);
            if(curNode->left) {
                queue.push({curNode->left, colNum - 1});
            }
            if(curNode->right) {
                queue.push({curNode->right, colNum + 1});
            }
        }
        
        //Output: [[4],[9],[3,0,1],[8],[7]]
        vector<vector<int>> ans; // [[4], [9], [3, 0, 1], [8], [7]]
        for(int i = minCol; i <= maxCol; ++i) {
            ans.push_back(colToVals[i]);
        }

        return ans;
    }
};
