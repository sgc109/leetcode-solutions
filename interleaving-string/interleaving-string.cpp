class Solution {
    int dp[103][103];
    int solve(int pos1, int pos2, string& s1, string& s2, string& s3) {
        if(pos1 > s1.size()) return false;
        if(pos2 > s2.size()) return false;
        if(pos1 + pos2 == s3.size()) return true;
        int& cache = dp[pos1][pos2];
        if(cache != -1) return cache;
        int ret = 0;
        if(pos1 < s1.size() 
           && s1[pos1] == s3[pos1 + pos2] 
           && solve(pos1 + 1, pos2, s1, s2, s3)) return cache = 1;
        if(pos2 < s2.size()
           && s2[pos2] == s3[pos1 + pos2]
           && solve(pos1, pos2 + 1, s1, s2, s3)) return cache = 1;
        
        return cache = 0;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s1, s2, s3);
    }
};