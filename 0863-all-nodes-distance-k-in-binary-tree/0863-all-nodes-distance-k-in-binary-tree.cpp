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
    unordered_map<TreeNode*, TreeNode*> parents;
    unordered_set<TreeNode*> visited;
    vector<int> ans;
    void buildParents(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left) {
                parents[cur->left] = cur;
                q.push(cur->left);
            }
            if(cur->right) {
                parents[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }
    void bfs(TreeNode* cur, int dist) {
        queue<pair<TreeNode*,int>> q;
        q.push({cur, dist});
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            TreeNode* cur = front.first;
            int curDist = front.second;
            if(visited.count(cur)) {
                continue;
            }
            visited.insert(cur);
            if(curDist == 0) {
                ans.push_back(cur->val);
            }
            if(cur->left) {
                q.push({cur->left, curDist - 1});
            }
            if(cur->right) {
                q.push({cur->right, curDist - 1});
            }
            if(parents[cur]) {
                q.push({parents[cur], curDist - 1});
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParents(root);
        bfs(target, k);
        return ans;
    }
};
