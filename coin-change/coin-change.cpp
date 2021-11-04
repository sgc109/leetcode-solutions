class Solution {
    const int IMPOSS = 10001;
    int dp[10003];
public:
    int coinChange(vector<int>& coins, int amount) {
        for(int i = 0; i <= amount; i++) {
            dp[i] = IMPOSS;
        }
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int coin : coins) {
                if(i-coin < 0 || dp[i-coin] == IMPOSS) continue;
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
        return dp[amount] == IMPOSS ? -1 : dp[amount];
    }
};