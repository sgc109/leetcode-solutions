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
    void connect(Node* a, Node* b) {
        a->right = b;
        b->left = a;
    }

    pair<Node*, Node*> convert(Node* cur) {
        Node* left = cur;
        Node* right = cur;
        if(cur->left) {
            auto leftHeadAndTail = convert(cur->left);
            connect(leftHeadAndTail.second, cur);
            left = leftHeadAndTail.first;
        }
        if(cur->right) {
            auto rightHeadAndTail = convert(cur->right);
            connect(cur, rightHeadAndTail.first);
            right = rightHeadAndTail.second;
        }
        return {left, right};
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) {
            return root;
        }
        auto headAndTail = convert(root);
        connect(headAndTail.second, headAndTail.first);
        return headAndTail.first;
    }
};