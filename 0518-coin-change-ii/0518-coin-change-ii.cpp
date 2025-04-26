class Solution {
    typedef long long ll;

    vector<vector<ll>> dp;
    ll truncateToInt(ll num) {
        while(num >= 1ll << 32) {
            num -= 1ll << 32;
        }
        return num;
    }
public:
    int change(int amount, vector<int>& coins) {
        dp = vector<vector<ll>>(coins.size() + 1, vector<ll>(amount + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= coins.size(); ++i) {
            for(int j = 0; j <= amount; ++j) {
                dp[i][j] = dp[i - 1][j];
                if(j >= coins[i - 1]) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                    dp[i][j] = truncateToInt(dp[i][j]);
                }
            }
        }
        return dp[coins.size()][amount];
    }
};