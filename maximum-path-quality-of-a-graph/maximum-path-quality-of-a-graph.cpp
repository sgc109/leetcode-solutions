class Solution {
    int N;
    vector<pair<int,int>> G[2003];
    vector<int> values;
    int maxTime;
    int ans = 0;
    void go(int cur, int timeTaken, int sum, vector<int>& visitCnt) {
        if(visitCnt[cur] == 0) {
            sum += values[cur];
        }
        ++visitCnt[cur];
        if(cur == 0) {
            ans = max(ans, sum);
        }
        for(auto& p : G[cur]) {
            int nxt = p.first;
            int t = p.second;
            if(timeTaken + t > maxTime) continue;
            go(nxt, timeTaken + t, sum, visitCnt);
        }
        --visitCnt[cur];
    }
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        this->N = values.size();
        this->values = values;
        this->maxTime = maxTime;
        for(auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            G[u].emplace_back(v, t);
            G[v].emplace_back(u, t);
        }
        vector<int> visitCnt(N, 0);
        go(0, 0, 0, visitCnt);
        return ans;
    }
};