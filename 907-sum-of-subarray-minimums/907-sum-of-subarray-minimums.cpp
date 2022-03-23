typedef long long ll;

class Solution {
    int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int N = arr.size();
        vector<int> left(N);
        vector<int> right(N);
        
        stack<int> stk;
        
        for(int i = N-1; i >= 0; --i) {
            while(!stk.empty() && arr[i] <= arr[stk.top()]) {
                left[stk.top()] = i + 1;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()) {
            left[stk.top()] = 0;
            stk.pop();
        }
        
        for(int i = 0; i < N; ++i) {
            while(!stk.empty() && arr[i] < arr[stk.top()]) {
                right[stk.top()] = i - 1;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()) {
            right[stk.top()] = N-1;
            stk.pop();
        }
        
        ll ans = 0;
        for(int i = 0; i < N; ++i) {
            ans = (ans + (ll)(right[i] - i + 1) * (i - left[i] + 1) * arr[i]) % MOD;
        }
        
        return ans;
    }
};