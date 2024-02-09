class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 0; i < prices.size() - 1; ++i) {
            ans += max(0, prices[i + 1] - prices[i]);
        }
        return ans;
    }
};