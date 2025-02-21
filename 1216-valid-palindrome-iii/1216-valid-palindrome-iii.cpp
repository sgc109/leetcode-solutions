/*
abcdeca

abcdeca
acedcba

acdca

*/

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int N = s.size();
        vector<vector<int>> dp = vector<vector<int>>(2, vector<int>(N + 1, 0));
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                dp[(i + 1) % 2][j + 1] = s[i] == s[N - 1 - j] ? dp[i % 2][j] + 1 : max(dp[i % 2][j + 1], dp[(i + 1) % 2][j]);
            }
        }
        return N - dp[N % 2][N] <= k;
    }
};