// Monotonic Stack
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        vector<int> ans(N);
        vector<int> stk;
        for(int i = N-1; i >= 0; --i) {
            int t = temperatures[i];
            while(!stk.empty() && t >= temperatures[stk.back()]) {
                stk.pop_back();
            }
            if(stk.size() == 0) {
                ans[i] = 0;
            } else {
                ans[i] = stk.back() - i;
            }
            stk.push_back(i);
        }
        return ans;
    }
};
