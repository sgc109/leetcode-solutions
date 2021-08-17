/*
dp[i][j]: s[..j] 에 있는 t[..i] 의 subsequence 의 개수
Answer: dp[N][M] (N: len(t), N: len(s))
*/ 
typedef long long ll;

class Solution {
public:
    int numDistinct(string s, string t) {
        int N = t.size();
        int M = s.size();
        
        if(N > M) return 0;
        
        vector<vector<ll>> dp = vector<vector<ll>>(2, vector<ll>(M + 1, 0));
        
        for(int i = 0; i <= M - N; i++) {
            dp[0][i] = 1;
        }
        for(int i = 1; i<= N; i++) {
            for(int j = 1; j <= M - (N - i); j++) {
                dp[i & 1][j] = dp[i & 1][j - 1];
                if(t[i - 1] == s[j - 1]) {
                    dp[i & 1][j] += dp[~i & 1][j - 1];
                }
                
            }
            if(i == 1) {
                dp[~i & 1][0] = 0;
            }
        }
        return dp[N & 1][M];
    }
};
