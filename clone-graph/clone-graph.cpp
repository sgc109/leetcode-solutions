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
    Node* newNodes[103];
    
    void dfs(Node* cur) {
        if(newNodes[cur->val] != nullptr) return;
        newNodes[cur->val] = new Node(cur->val);
        for(auto next : cur->neighbors) {
            dfs(next);
            (newNodes[cur->val]->neighbors).push_back(newNodes[next->val]);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return node;
        }
        
        dfs(node);
        
        return newNodes[node->val];
    }
};