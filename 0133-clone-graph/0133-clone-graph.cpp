/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> oldToNew;
    Node* dfs(Node* curNode) {
        if(oldToNew.count(curNode)) {
            return oldToNew[curNode];
        }
        oldToNew[curNode] = new Node(curNode->val);
        for(auto nextNode : curNode->neighbors) {
            (oldToNew[curNode]->neighbors).push_back(dfs(nextNode));
        }

        return oldToNew[curNode];
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) {
            return node;
        }
        return dfs(node);
    }
};