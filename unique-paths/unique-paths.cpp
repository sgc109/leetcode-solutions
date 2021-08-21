typedef long long ll;

class Solution {
public:
    int uniquePaths(int m, int n) {
        m--, n--;
        int sum = m + n;
        int mn = min(m, n);
        vector<int> nums;
        ll ans = 1;
        for(int i = 0; i < mn; i++) {
            ans *= sum - i;
        }
        for(int i = mn; i >= 2; i--) {
            ans /= i;
        }
        return ans;
    }
};