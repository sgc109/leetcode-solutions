class Solution {
    int dp[33][3003];
public:
    int lastStoneWeightII(vector<int>& stones) {
        int N = stones.size();
        dp[0][stones[0]] = 1;
        
        for(int i = 0; i < N - 1; ++i) {
            for(int j = 0; j <= 3000; ++j) {
                if(dp[i][j]) {
                    dp[i + 1][j + stones[i + 1]] = 1;
                    dp[i + 1][abs(j - stones[i + 1])] = 1;
                }
            }
        }
        
        int ans = 3000;
        for(int i = 0; i <= 3000; ++i) {
            if(dp[N - 1][i]) {
                return i;
            }
        }
        return -1; // unreachable;
    }
};