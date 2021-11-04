class Solution {
    int dp[103][2][2];
public:
    int rob(vector<int>& nums) {
        memset(dp, 0xc7, sizeof(dp));
        int ans = nums[0];
        dp[0][0][0] = 0;
        dp[0][1][1] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            int rob = 0;
            int notRob = 0;
            for(int j = 0; j < 2; ++j) {
                int rob=0, notRob=0;
                // if rob
                if(!(i == nums.size() - 1 && j == 1)) {
                    dp[i][1][j] = dp[i-1][0][j] + nums[i];
                    ans = max(ans, dp[i][1][j]);
                }
                
                // if not
                dp[i][0][j] = max(dp[i-1][0][j], dp[i-1][1][j]);
                ans = max(ans, dp[i][0][j]);
            }
        }
        
        return ans;
    }
};