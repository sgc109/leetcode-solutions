class Solution {
    vector<int> colors;
    
    bool dfs(int cur, int color, vector<vector<int>>& g) {
        for(int nxt : g[cur]) {
            if(colors[nxt] != -1) {
                if(colors[nxt] == color) {
                    return false;
                }
                continue;
            }
            colors[nxt] = !color;
            bool res = dfs(nxt, !color, g);
            if(!res) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        colors = vector<int>(N, -1);
        for(int i = 0; i < N; ++i) {
            if(colors[i] == -1) {
                colors[i] = 0;
                bool res = dfs(i, 0, graph);
                if(!res) {
                    return false;
                }
            }
        }
        return true;
    }
};