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
    vector<int> tree[503];

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) {
            return vector<int>({target->val});
        }
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> nodeToId;
        unordered_map<int, TreeNode*> idToNode;
        q.push(root);
        int id = 0;
        idToNode[id] = root;
        nodeToId[root] = id++;
        while(q.size() > 0) {
            auto curNode = q.front();
            int curId = nodeToId[curNode];
            q.pop();
            if(curNode->left != NULL) {
                idToNode[id] = curNode->left;
                nodeToId[curNode->left] = id;
                q.push(curNode->left);
                tree[curId].push_back(id);
                tree[id].push_back(curId);
                ++id;
            }
            if(curNode->right != NULL) {
                idToNode[id] = curNode->right;
                nodeToId[curNode->right] = id;
                q.push(curNode->right);
                tree[curId].push_back(id);
                tree[id].push_back(curId);
                ++id;
            }
        }
        int targetId = nodeToId[target];

        vector<int> dist(id, -1);
        vector<int> ans;
        queue<int> idQueue;
        dist[targetId] = 0;
        idQueue.push(targetId);
        while(idQueue.size() > 0) {
            auto curId = idQueue.front();
            idQueue.pop();
            int curDist = dist[curId];
            if(curDist == k) {
                ans.push_back(idToNode[curId]->val);
            }
            for(auto next : tree[curId]) {
                if(dist[next] != -1) {
                    continue;
                }
                idQueue.push(next);
                dist[next] = curDist + 1;
            }
        }
        return ans;
    }
};
