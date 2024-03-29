class Solution {
    int MOD = 1e9 + 7;
    int mod(int x) {
        if(x >= MOD) {
            return x - MOD;
        }
        return x;
    }
public:
    int numOfSubarrays(vector<int>& arr) {
        int N = arr.size();
        vector<vector<int>> dp(N + 1, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = 0;
        for(int i = 0; i < N; ++i) {
            if(arr[i] & 1) {
                dp[i + 1][0] = dp[i][1];
                dp[i + 1][1] = dp[i][0] + 1;
            } else {
                dp[i + 1][0] = dp[i][0] + 1;
                dp[i + 1][1] = dp[i][1];
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= N; ++i) {
            ans = mod(ans + dp[i][1]);
        }
        return ans;
    }
};