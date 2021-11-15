class Solution {
    int dp[20];
    int countBsts(int len) {
        assert(len >= 0);
        if(len <= 1) return 1;
        int& cache = dp[len];
        if(cache != -1) return dp[len];
        int ret = 0;
        for(int k = 0; k < len; ++k) {
            ret += countBsts(k) * countBsts(len-k-1);
        }
        return cache = ret;
    }
public:
    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        return countBsts(n);
    }
};
