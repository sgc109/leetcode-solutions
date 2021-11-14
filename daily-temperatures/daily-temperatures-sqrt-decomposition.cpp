// Sqrt decomposition
// Time complexity: O(N * root(T))
// Space complexity: O(N + root(T))

class Solution {
    const int MAX_IDX = 100001;
    int minIdx[111];
    int sqrtMinIdx[12];
    
    int query(int l) { // inclusive
        int sq = (l+9) / 10;
        int ans = MAX_IDX;
        for(int i = l; i < sq*10; ++i) {
            ans = min(ans, minIdx[i]);
        }
        for(int i = sq; i <= 10; ++i) {
            ans = min(ans, sqrtMinIdx[i]);
        }
        return ans;
    }
    
    void update(int idx, int val) {
        minIdx[idx] = val;
        sqrtMinIdx[idx/10] = val;
    }
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        
        fill(minIdx, minIdx+111, MAX_IDX);
        fill(sqrtMinIdx, sqrtMinIdx+12, MAX_IDX);
        
        vector<int> ans(N);
        for(int i = N-1; i >= 0; --i) {
            int t = temperatures[i];
            int q = query(t + 1);
            ans[i] = (q == MAX_IDX ? 0 : q - i);
            update(t, i);
        }
        return ans;
    }
};
