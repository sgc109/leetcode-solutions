class Solution {
    bool dp[101][101];
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }
        for(int i = 0; i <= s1.size(); i++) {
            for(int j = 0; j <= s2.size(); j++) {
                dp[i][j] = ((i > 0 && s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) 
                            || (j > 0 && s2[j - 1] == s3[i + j - 1] && dp[i][j - 1])
                            || (i == 0 && j == 0));
            }
        }
        
        return dp[s1.size()][s2.size()];
    }
};
