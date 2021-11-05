class Solution {    
    int solve(char target, string& s, int k) {
        int l = 0;
        int diffCnt = 0;
        int sameCnt = 0;
        int ans = 0;
        for(int r = 0; r < s.size(); ++r) {
            diffCnt += (s[r] != target);
            ++sameCnt;
            while(diffCnt > k) {
                diffCnt -= (s[l++] != target);
                --sameCnt;
            }
            ans = max(ans, sameCnt);
        }
        
        return ans;
    }
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            char target = 'A' + i;
            ans = max(ans, solve(target, s, k));
        }
        return ans;
    }
};