class Solution {
    int dp[20][20];
    int countBsts(int l, int r) { // [l, r)
        assert(l <= r);
        if(l >= r-1) return 1;
        int& cache = dp[l][r];
        if(cache != -1) return dp[l][r];
        int ret = 0;
        for(int k = l; k < r; ++k) {
            ret += countBsts(l, k) * countBsts(k+1, r);
        }
        return cache = ret;
    }
public:
    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        return countBsts(0, n);
    }
};