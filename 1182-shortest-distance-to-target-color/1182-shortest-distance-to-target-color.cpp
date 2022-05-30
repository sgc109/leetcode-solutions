class Solution {
    const int INF = 987654321;
    int N;
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int N = colors.size();
        int M = queries.size();
        vector<vector<vector<int>>> mark = vector<vector<vector<int>>>(3, vector<vector<int>>(N, vector<int>()));
        
        for(int i = 0; i < M; ++i) {
            int idx = queries[i][0];
            int col = queries[i][1] - 1;
            mark[col][idx].push_back(i);
        }
        
        vector<int> ans(M, INF);
        
        for(int i = 0; i < 3; ++i) {
            int last = -1;
            for(int j = 0; j < N; ++j) {
                if(colors[j] - 1 == i) {
                    last = j;
                }
                if(last != -1) {
                    for(int idx : mark[i][j]) {
                        ans[idx] = min(ans[idx], j - last);
                    }
                }
            }
        }
        
        for(int i = 0; i < 3; ++i) {
            int last = N;
            for(int j = N-1; j >= 0; --j) {
                if(colors[j] - 1 == i) {
                    last = j;
                }
                if(last != N) {
                    for(int idx : mark[i][j]) {
                        ans[idx] = min(ans[idx], last - j);
                    }
                }
            }
        }
        for(int i = 0; i < M; ++i) {
            if(ans[i] == INF) ans[i] = -1;
        }
        return ans;
    }
};