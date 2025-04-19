/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if(!root) {
            return nullptr;
        }
        unordered_map<Node*, NodeCopy*> oldToNew;
        queue<Node*> q;
        q.push(root);
        oldToNew[root] = new NodeCopy(root->val);
        while(!q.empty()) {
            Node* curNode = q.front();
            q.pop();
            if(curNode->left) {
                if(!oldToNew.count(curNode->left)) {
                    oldToNew[curNode->left] = new NodeCopy(curNode->left->val);
                }
                q.push(curNode->left);
                oldToNew[curNode]->left = oldToNew[curNode->left];
            }
            if(curNode->right) {
                if(!oldToNew.count(curNode->right)) {
                    oldToNew[curNode->right] = new NodeCopy(curNode->right->val);
                }
                q.push(curNode->right);
                oldToNew[curNode]->right = oldToNew[curNode->right];
            }
            if(curNode->random) {
                if(!oldToNew.count(curNode->random)) {
                    oldToNew[curNode->random] = new NodeCopy(curNode->random->val);
                }
                oldToNew[curNode]->random = oldToNew[curNode->random];
            }
        }
        return oldToNew[root];
    }
};