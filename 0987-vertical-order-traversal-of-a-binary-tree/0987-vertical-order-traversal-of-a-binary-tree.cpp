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
    struct Position {
        TreeNode* node;
        int col;
        bool operator<(const Position& rhs) const {
            return node->val > (rhs.node)->val;
        }  
    };
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        priority_queue<Position> pq;
        int minCol = INT_MAX;
        int maxCol = INT_MIN;
        unordered_map<int, vector<int>> colToVals;
        pq.push(Position{root, 0});
        while(!pq.empty()) {
            vector<Position> nextPositions;
            while(!pq.empty()) {
                auto cur = pq.top();
                pq.pop();
                colToVals[cur.col].push_back((cur.node)->val);
                if((cur.node)->left) {
                    nextPositions.push_back(Position{(cur.node)->left, cur.col - 1});
                }
                if((cur.node)->right) {
                    nextPositions.push_back(Position{(cur.node)->right, cur.col + 1});
                }
                minCol = min(minCol, cur.col);
                maxCol = max(maxCol, cur.col);
            }
            for(auto position : nextPositions) {
                pq.push(position);
            }
        }
        vector<vector<int>> ans;
        for(int i = minCol; i <= maxCol; ++i) {
            ans.push_back(colToVals[i]);
        }
        return ans;
    }
};