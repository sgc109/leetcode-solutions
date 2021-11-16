class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int prvCnt = 0;
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(i > 0 && s[i] != s[i-1]) {
                ans += min(prvCnt, cnt);
                prvCnt = cnt;
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        ans += min(prvCnt, cnt);
        return ans;
    }
};