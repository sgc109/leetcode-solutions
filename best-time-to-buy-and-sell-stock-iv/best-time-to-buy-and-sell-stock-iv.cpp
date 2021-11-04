class Solution {
    const int MAX_DAY = 1002;
    const int NONE_DAY = MAX_DAY;
    const int INF = 987654321;
    int N, K;
    int dp[1003][2][103];
    vector<int> prices;
    int go(int today, int bought, int cntTx) {
        if(cntTx > K) return -INF;
        if(today == N) return 0;
        int& cache = dp[today][bought][cntTx];
        if(cache != -1) return cache;
        
        int profit = 0;        
        if(bought == 0) {
            profit = max(profit, go(today+1, bought, cntTx));
            profit = max(profit, go(today+1, !bought, cntTx) - prices[today]);
        } else {
            profit = max(profit, go(today+1, bought, cntTx));
            profit = max(profit, go(today+1, !bought, cntTx+1) + prices[today]);
        }
        
        return cache = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        this->N = prices.size();
        this->prices = prices;
        this->K = k;
        return go(0, 0, 0);
    }
};