class Solution {
    int n;
    vector<vector<int>> tree;
    vector<bool> hasApple;
    int dfs(int cur, int parent) {
        int ret = 0;
        if(parent != -1 && tree[cur].size() == 1) {
            return hasApple[cur] * 2;
        }
        for(int next : tree[cur]) {
            if(next != parent) {
                ret += dfs(next, cur);
            }
        }
        if(parent == -1) { // cur is root
            return ret;
        }
        return ret > 0 ? ret + 2 : (hasApple[cur] ? 2 : 0);
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        this->n = n;
        this->hasApple = hasApple;
        this->tree = vector<vector<int>>(n, vector<int>());
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        return dfs(0, -1);
    }
};