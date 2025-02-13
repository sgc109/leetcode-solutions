/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    void connect(Node* node1, Node* node2) {
        node1->right = node2;
        node2->left = node1;
    }
    pair<Node*, Node*> dfs(Node* cur) {
        pair<Node*, Node*> curPair = {cur, cur};
        if(cur->left) {
            auto leftPair = dfs(cur->left);
            curPair.first = leftPair.first;
            connect(leftPair.second, cur);
        }
        if(cur->right) {
            auto rightPair = dfs(cur->right);
            curPair.second = rightPair.second;
            connect(cur, rightPair.first);
        }
        return curPair;
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) {
            return root;
        }
        auto pair = dfs(root);
        connect(pair.second, pair.first);
        return pair.first;
    }
};