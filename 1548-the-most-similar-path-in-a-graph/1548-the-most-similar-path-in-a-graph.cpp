class Solution {
    const int INF = 987654321;

    int N; // # of nodes in graph
    vector<vector<int>> graph;
    vector<vector<int>> dp;
    vector<string> names;
    vector<string> targetPath;
    vector<vector<int>> parent;

    void connect(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // cur: current node id in graph
    // idx: index in targetPath
    int dfs(int cur, int idx) {
        if(idx == size(targetPath)) {
            return 0;
        }
        if(dp[cur][idx] != -1) {
            return dp[cur][idx];
        }

        int ans = INF;
        for(int next : graph[cur]) {
            int nextEditDist = dfs(next, idx + 1);
            if(nextEditDist < ans) {
                ans = nextEditDist;
                parent[cur][idx] = next;
            }
        }
        return dp[cur][idx] = ans + (names[cur] != targetPath[idx]);
    }
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        // 0. initialization
        N = n;
        this->names = names;
        this->targetPath = targetPath;

        graph = vector<vector<int>>(n, vector<int>());
        dp = vector<vector<int>>(n, vector<int>(size(targetPath), -1));
        parent = vector<vector<int>>(n, vector<int>(size(targetPath), -1));

        // 1. Build graph
        for(auto edge : roads) {
            int u = edge[0];
            int v = edge[1];
            connect(u, v);
        }

        // 2. Calculate the answer
        int ans = INF;
        int optimalStartNode = -1;
        for(int i = 0; i < n; ++i) {
            int minEditDist = dfs(i, 0);
            if(minEditDist < ans) {
                ans = minEditDist;
                optimalStartNode = i;
            }
        }

        vector<int> path;
        int cur = optimalStartNode;
        int idx = 0;
        for(int i = 0; i < size(targetPath); ++i) {
            path.push_back(cur);
            cur = parent[cur][i];
        }

        return path;
    }
};