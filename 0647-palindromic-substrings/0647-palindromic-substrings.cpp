class Solution {
public:
    int countSubstrings(string s) {
        int N = s.size();
        
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            int l = i, r = i;
            while(0 <= l && r < N) {
                if(s[l] != s[r]) {
                    break;
                }
                ++ans;
                --l;
                ++r;
            }
        }
        for(int i = 0; i < N - 1; ++i) {
            int l = i, r = i + 1;
            while(0 <= l && r < N) {
                if(s[l] != s[r]) {
                    break;
                }
                ++ans;
                --l;
                ++r;
            }
        }
        return ans;
    }
};