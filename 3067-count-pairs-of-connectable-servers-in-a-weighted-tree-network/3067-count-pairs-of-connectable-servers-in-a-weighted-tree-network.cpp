class Solution {
    int N;
    vector<vector<pair<int,int>>> G;
    int K;
    int dfs(int root, int dad, int cur, int untilDist) {
        int cntDivisible = 0;
        if(untilDist > 0 && untilDist % K == 0) {
            ++cntDivisible;
        }
        
        vector<int> nextCntDivisibles;
        for(auto p : G[cur]) {
            int next = p.first;
            if(next == dad) {
                continue;
            }
            int dist = p.second;
            int res = dfs(root, cur, next, untilDist + dist);
            cntDivisible += res;
            nextCntDivisibles.push_back(res);
        }
        
        
        if(root == cur) {
            int ret = 0;
            for(int i = 0; i < size(nextCntDivisibles); ++i) {
                for(int j = i + 1; j < size(nextCntDivisibles); ++j) {
                    ret += nextCntDivisibles[i] * nextCntDivisibles[j];
                }
            }
            return ret;
        } else {
            return cntDivisible;
        }
    }
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        N = edges.size() + 1;
        K = signalSpeed;
        G = vector<vector<pair<int,int>>>(N, vector<pair<int,int>>());
        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            int d = e[2];
            G[u].emplace_back(v, d);
            G[v].emplace_back(u, d);
        }
        vector<int> ans;
        for(int i = 0; i < N; ++i) {
            int res = dfs(i, -1, i, 0);
            ans.push_back(res);
        }
        return ans;
    }
};