class Solution {
    vector<vector<int>> dp;
public:
/*
N = 9
9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 0 9
9 9 9 9 9 9 9 9 0
*/
    bool isValidPalindrome(string s, int k) { // s = "aaabaabaa", k = 1
        int N = s.size();
        dp = vector<vector<int>>(2, vector<int>(s.size(), 0));
        
        for(int i = N - 1; i >= 0; --i) {
            for(int j = i + 1; j < N; ++j) {
                if(s[i] == s[j]) {
                    dp[i & 1][j] = dp[(i + 1) & 1][j - 1];
                } else {
                    dp[i & 1][j] = min(dp[(i + 1) & 1][j], dp[i & 1][j - 1]) + 1;
                }
            }
        }

        return dp[0][N - 1] <= k;
    }
};