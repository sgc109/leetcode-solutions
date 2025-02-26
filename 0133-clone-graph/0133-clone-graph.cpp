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
    unordered_map<Node*, Node*> map;
public:
    Node* cloneGraph(Node* node) {
        if(!node) {
            return node;
        }
        queue<Node*> q;
        q.push(node);
        map[node] = new Node(node->val);
        while(!q.empty()) {
            Node* cur = q.front();
            Node* newCur = map[cur];
            q.pop();
            for(Node* adj : cur->neighbors) {
                bool notVisited = false;
                if(!map.count(adj)) {
                    map[adj] = new Node(adj->val);
                    notVisited = true;
                }
                auto newAdj = map[adj];
                (newCur->neighbors).push_back(newAdj);
                if(notVisited) {
                    q.push(adj);
                }
            }
        }
        return map[node];
    }
};
