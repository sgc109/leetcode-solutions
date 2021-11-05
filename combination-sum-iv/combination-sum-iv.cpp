class Solution {
    long long dp[1003];
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp[0] = 1;
        for(int i = 1; i <= target; ++i) {
            for(int num : nums) {
                int prv = i - num;
                if(prv < 0) continue;
                dp[i] = (dp[i] + dp[prv]) % INT_MAX;
            }
        }
        return dp[target];
    }
};