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
    Node* lowestCommonAncestor(Node* p, Node * q) { // p = 5, q = 4
        // {5 -> ptr5, 4 -> ptr4, 3 -> ptr3, 2 -> ptr2}
        unordered_map<int, Node*> nodesInRouteToRoot;
        while(p && q) { // p = null, q = 5
            if(p == q) {
                return p;
            }
            if(nodesInRouteToRoot[p->val]) {
                return nodesInRouteToRoot[p->val];
            }
            if(nodesInRouteToRoot[q->val]) {
                return nodesInRouteToRoot[q->val];
            }
            nodesInRouteToRoot[p->val] = p;
            nodesInRouteToRoot[q->val] = q;
            p = p->parent;
            q = q->parent;
        }
        while(p) {
            if(nodesInRouteToRoot[p->val]) {
                return nodesInRouteToRoot[p->val];
            }
            p = p->parent;
        }
        while(q) {
            if(nodesInRouteToRoot[q->val]) {
                return nodesInRouteToRoot[q->val];
            }
            q = q->parent;
        }
        // It's impossible to reach here
        return nullptr; // dummy
    }
};