class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minVal = prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            maxProfit = max(maxProfit, prices[i] - minVal);
            minVal = min(minVal, prices[i]);
        }

        return maxProfit;
    }
};