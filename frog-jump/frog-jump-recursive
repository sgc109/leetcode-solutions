/*
dp[i][j]: whether it is reachable to last position when previous position is i and current position is j
*/

class Solution {
    int dp[2001][2001];
    int N;
    vector<int> stones;
    unordered_map<int,int> index;
    bool solve(int prev, int cur) {
        if(cur == N - 1) return 1;
        int& cache = dp[prev][cur];
        if(cache != -1) return cache;
        int ret = 0;
        int dist = stones[cur] - stones[prev];
        for(int k = -1; k <= 1; k++) {
            int nxtPos = stones[cur] + dist + k;
            if(index.count(nxtPos) == 0 || index[nxtPos] == cur) continue;
            ret = ret || solve(cur, index[nxtPos]);
        }        
        return cache = ret;
    }
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        memset(dp, -1, sizeof(dp));
        this->stones = stones;
        N = stones.size();
        for(int i = 0; i < N; i++) {
            index[stones[i]] = i;
        }
        return solve(0, 1);
    }
};
