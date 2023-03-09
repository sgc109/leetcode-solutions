class Solution {
    const int INF = 0x3c3c3c3c;
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> G = vector<vector<vector<int>>>(2, vector<vector<int>>(n, vector<int>()));
        for(auto e : redEdges) {
            int from = e[0];
            int to = e[1];
            G[0][from].push_back(to);
        }
        for(auto e : blueEdges) {
            int from = e[0];
            int to = e[1];
            G[1][from].push_back(to);
        }
        vector<vector<int>> dist = vector<vector<int>>(2, vector<int>(n, INF));
        dist[0][0] = 0;
        dist[1][0] = 0;
        queue<pair<int,int>> Q;
        Q.push({0, 0});
        Q.push({1, 0});
        while(!Q.empty()) {
            auto p = Q.front();
            Q.pop();
            int prvColor = p.first;
            int curIdx = p.second;
            int curDist = dist[prvColor][curIdx];
            
            int nxtColor = 1 - prvColor;
            for(auto nxtIdx : G[nxtColor][curIdx]) {
                if(dist[nxtColor][nxtIdx] != INF) {
                    continue;
                }
                dist[nxtColor][nxtIdx] = curDist + 1;
                Q.push({nxtColor, nxtIdx});
            }
        }
        vector<int> ans(n);
        for(int i = 0; i < n; ++i) {
            int minDist = min(dist[0][i], dist[1][i]);
            if(minDist == INF) {
                ans[i] = -1;
            } else {
                ans[i] = minDist;
            }
        }
        return ans;
    }
};