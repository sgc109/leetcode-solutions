class Solution {
public:
    string removeDuplicates(string s) {
        int l = 0, r = 1;
        while(r < s.size()) {
            if(l >= 0 && s[l] == s[r]) {
                --l;
                ++r;
            } else {
                ++l;
                s[l] = s[r];
                ++r;
            }
        }
        return s.substr(0, l + 1);
    }
};