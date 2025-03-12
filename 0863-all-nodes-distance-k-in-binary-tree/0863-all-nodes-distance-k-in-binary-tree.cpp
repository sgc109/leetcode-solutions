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
    unordered_set<TreeNode*> discovered;
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
    void bfs(TreeNode* root, int dist) {
        queue<pair<TreeNode*,int>> q;
        q.push({root, dist});
        discovered.insert(root);
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            TreeNode* cur = front.first;
            int curDist = front.second;
            if(curDist == 0) {
                ans.push_back(cur->val);
            }
            if(cur->left && !discovered.count(cur->left)) {
                q.push({cur->left, curDist - 1});
                discovered.insert(cur->left);
            }
            if(cur->right && !discovered.count(cur->right)) {
                q.push({cur->right, curDist - 1});
                discovered.insert(cur->right);
            }
            if(parents[cur] && !discovered.count(parents[cur])) {
                q.push({parents[cur], curDist - 1});
                discovered.insert(parents[cur]);
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
