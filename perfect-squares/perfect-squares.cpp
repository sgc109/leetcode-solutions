class Solution {
    int dp[10001];
public:
    int numSquares(int n) {
        fill(dp, dp+n+1, 10000);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j*j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
};