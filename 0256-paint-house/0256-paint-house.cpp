class Solution {
    int dp[103][3] = {0, };
public:
    int minCost(vector<vector<int>>& costs) {
        int N = costs.size();
        
        for(int i = 1; i <= N; ++i) {
            for(int j = 0; j < 3; ++j) {
                dp[i][j] = costs[i-1][j] + min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
            }
        }
        
        return min({dp[N][0], dp[N][1], dp[N][2]});
    }
};