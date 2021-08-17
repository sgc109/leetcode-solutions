class Solution {
    int cnt1[26], cnt2[26];
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        for(char c : s) {
            cnt1[c - 'a']++;
        }
        for(char c : t) {
            cnt2[c - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(cnt1[i] != cnt2[i]) return false;
        }
        return true;
    }
};