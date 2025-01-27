class Solution {
    int counter[26];
public:
    string customSortString(string order, string s) {
        for(char c : s) {
            counter[c - 'a']++;
        }
        string ans = "";
        for(char c : order) {
            while(counter[c - 'a']) {
                ans += c;
                counter[c - 'a']--;
            }
        }
        for(int i = 0; i < 26; ++i) {
            while(counter[i]) {
                ans += ('a' + i);
                counter[i]--;
            }
        }
        return ans;
    }
};