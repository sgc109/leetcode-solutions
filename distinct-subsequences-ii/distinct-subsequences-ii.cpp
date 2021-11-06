/*
dp[i][j]: s[i] 까지 고려했을 때, s[i] 포함 여부(j)에 따른 distinct 한 subsequence 의 수
*/

class Solution {
    const int MOD = 1e9 + 7;
    int dp[2][2];
    int sum[26];
    int mod(int val) {
        if(val < 0) {
            val += MOD;
        }
        while(val >= MOD) {
            val -= MOD;
        }
        return val;
    }
public:
    int distinctSubseqII(string s) {
        int N = s.size();
        dp[0][0] = 1;
        for(int i = 1; i <= N; ++i) {
            int alphaIdx = s[i-1] - 'a';
            int cur = i % 2;
            int prv = (i+1) % 2;
            dp[cur][0] = mod(dp[prv][0] + dp[prv][1]);
            dp[cur][1] = mod(dp[cur][0] - sum[alphaIdx]);
            sum[alphaIdx] = mod(dp[cur][1] + sum[alphaIdx]);
        }
        
        int target = N % 2;
        return mod(dp[target][0] + dp[target][1] - 1);
    }
};
