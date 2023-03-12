class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        int N = columnTitle.size();
        for(int i = 0; i < N; ++i) {
            int x = columnTitle[i] - 'A' + 1;
            ans = ans * 26 + x;
        }
        return ans;
    }
};