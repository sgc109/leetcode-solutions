typedef long long ll;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < n) return uniquePaths(n, m);
        m--, n--;
        int sum = m + n;
        ll ans = 1;
        for(int i = 0; i < n; i++) {
            ans = (ans * (sum - i) / (i + 1));
        }
        return ans;
    }
};
