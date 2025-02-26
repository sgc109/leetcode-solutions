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
    unordered_map<Node*, Node*> oldToNew; // {1 -> 1', 2 -> 2', 3 -> 3', 4 -> 4'}
    void dfs(Node* cur) { // 1
        auto newCur = oldToNew[cur]; // 3'
        for(auto adjNode : cur->neighbors) { // 4
            bool notYetVisited = false; // false
            if(!oldToNew.count(adjNode)) {
                notYetVisited = true;
                oldToNew[adjNode] = new Node(adjNode->val);
            }
            auto newAdjNode = oldToNew[adjNode]; // 3'
            (newCur->neighbors).push_back(newAdjNode);
            if(notYetVisited) {
                dfs(adjNode);
            }
        }
    }
public: // [[2,4], [1,3], [2,4], [1,3]]
    Node* cloneGraph(Node* node) { // [[2,4],[1,3],[2,4],[1,3]]
        if(!node) {
            return node;
        }

        auto newNode = new Node(node->val);
        oldToNew[node] = newNode;
        
        dfs(node);
        return newNode;
    }
};