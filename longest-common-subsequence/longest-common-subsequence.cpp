class Solution {
    int dp[1003][1003];
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N = text1.size();
        int M = text2.size();
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= M; ++j) {
                int pos1 = i - 1;
                int pos2 = j - 1;
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(text1[pos1] == text2[pos2]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
            }
        }
        return dp[N][M];
    }
};