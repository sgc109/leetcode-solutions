class Solution {
    int dp[103][2];
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        for(int i = 1; i <= N; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i - 1];
        }
        return max(dp[N][0], dp[N][1]);
    }
};