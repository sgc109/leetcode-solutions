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
    unordered_map<Node*, NodeCopy*> oldToNew;
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if(!root) {
            return nullptr;
        }
        if(oldToNew.count(root)) {
            return oldToNew[root];
        }
        oldToNew[root] = new NodeCopy(root->val);
        oldToNew[root]->left = copyRandomBinaryTree(root->left);
        oldToNew[root]->right = copyRandomBinaryTree(root->right);
        oldToNew[root]->random = copyRandomBinaryTree(root->random);
                
        return oldToNew[root];
    }
};