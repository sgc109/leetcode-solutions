class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(i & 1) ans[i] = ans[i - 1] + 1;
            else {
                int lowest = i & -i;
                ans[i] = ans[i - 1] - (int)log2(lowest) + 1;
            }
        }
        return ans;
    }
};