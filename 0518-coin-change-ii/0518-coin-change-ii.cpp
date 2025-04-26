class Solution {
    vector<vector<int>> dp;
    int go(int amount, int coinIdx, vector<int>& coins) {
        if(coins.size() == coinIdx) {
            return amount == 0 ? 1 : 0;
        }
        if(dp[amount][coinIdx] != -1) {
            return dp[amount][coinIdx];
        }
        int ans = go(amount, coinIdx + 1, coins);
        if(amount >= coins[coinIdx]) {
            ans += go(amount - coins[coinIdx], coinIdx, coins);
        }
        return dp[amount][coinIdx] = ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        dp = vector<vector<int>>(amount + 1, vector<int>(coins.size() + 1, -1));
        return go(amount, 0, coins);
    }
};