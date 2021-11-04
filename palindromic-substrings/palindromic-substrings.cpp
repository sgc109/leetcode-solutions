class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int size = s.size();
        for(int i = 0; i < size; ++i) {
            int len = 0;
            while(i-len >= 0 && i+len < size && s[i-len] == s[i+len]) {
                ++ans;
                ++len;
            }
        }
        for(int i = 0; i < size - 1; ++i) {
            int len = 1;
            while(true) {
                int l = i - len + 1;
                int r = i + len;
                if(0 > l || r >= size || s[l] != s[r]) break;
                ++ans;
                ++len;
            }
        }
        return ans;
    }
};