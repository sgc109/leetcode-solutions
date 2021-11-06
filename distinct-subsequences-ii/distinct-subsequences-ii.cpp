class Solution {
    const int MOD = 1e9 + 7;
    int dp[2001][2];
    int sum[26];
    int mod(int val) {
        if(val < 0) {
            val += MOD;
        }
        return val % MOD;
    }
public:
    int distinctSubseqII(string s) {
        int N = s.size();
        dp[0][0] = 1;
        for(int i = 1; i <= N; ++i) {
            int alphaIdx = s[i-1] - 'a';
            dp[i][0] = mod(dp[i-1][0] + dp[i-1][1]);
            dp[i][1] = mod(dp[i][0] - sum[alphaIdx]);
            sum[alphaIdx] = mod(dp[i][1] + sum[alphaIdx]);
        }
        
        return mod(dp[N][0] + dp[N][1] - 1);
    }
};