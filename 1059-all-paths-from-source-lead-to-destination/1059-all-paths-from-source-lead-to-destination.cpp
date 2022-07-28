class Solution {
    vector<vector<int>> G;
    queue<int> q;
    vector<int> in;
    vector<bool> fromSrc;
    vector<bool> visited;
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        in = vector<int>(n, 0);
        fromSrc = vector<bool>(n, false);
        visited = vector<bool>(n, false);
        G = vector<vector<int>>(n, vector<int>());
        
        for(auto e : edges) {
            int u = e[0], v = e[1];
            G[u].push_back(v);
            in[v]++;
        }
        
        for(int i = 0; i < n; ++i) {
            if(in[i] == 0) {
                q.push(i);
            }
        }
        fromSrc[source] = true;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = true;
            
            for(int nxt : G[cur]) {
                fromSrc[nxt] = fromSrc[nxt] || fromSrc[cur];
                in[nxt]--;
                if(in[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }
        
        for(int i = 0; i < n; ++i) {
            if(fromSrc[i] && (!visited[i] || (G[i].size() == 0 && i != destination))) {
                return false;
            }
        }
        
        return true;
    }
};