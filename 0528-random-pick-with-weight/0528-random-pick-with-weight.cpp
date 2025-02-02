class Solution {
    vector<int> acc;
public:
    Solution(vector<int>& w) {
        acc = vector<int>(w.size());
        acc[0] = w[0];
        for(int i = 1; i < w.size(); ++i) {
            acc[i] = acc[i - 1] + w[i];
        }
    }
    
    int pickIndex() {
        int target = rand() % acc.back() + 1;
        return lower_bound(begin(acc), end(acc), target) - begin(acc);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */