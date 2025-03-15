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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        auto curP = p;
        auto curQ = q;
        while(curP != curQ) {
            if(curP->parent) {
                curP = curP->parent;
            } else {
                curP = q;
            }
            if(curQ->parent) {
                curQ = curQ->parent;
            } else {
                curQ = p;
            }
        }
        return curP;
    }
};