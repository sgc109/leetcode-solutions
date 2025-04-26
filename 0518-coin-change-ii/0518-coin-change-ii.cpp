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
        dp = vector<vector<ll>>(2, vector<ll>(amount + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= coins.size(); ++i) {
            for(int j = 0; j <= amount; ++j) {
                dp[i & 1][j] = dp[~i & 1][j];
                if(j >= coins[i - 1]) {
                    dp[i & 1][j] += dp[i & 1][j - coins[i - 1]];
                    dp[i & 1][j] = truncateToInt(dp[i & 1][j]);
                }
            }
        }
        return dp[coins.size() & 1][amount];
    }
};