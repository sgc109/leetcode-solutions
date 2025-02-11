/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) { // p = 4, q = 5
        // {4, 2, 5, 3}
        unordered_map<int, Node*> nodesInRouteToRoot;
        Node* cur = p; // 3
        while(cur) {
            nodesInRouteToRoot[cur->val] = cur;
            cur = cur->parent;
        }
        cur = q;
        while(q) { // cur = 5
            if(nodesInRouteToRoot.count(cur->val)) {
                return nodesInRouteToRoot[cur->val];
            }
            cur = cur->parent;
        }
        // It's impossible to reach here
        return nullptr;
    }
};