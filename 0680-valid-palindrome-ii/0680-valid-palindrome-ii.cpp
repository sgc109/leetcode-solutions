/*
bcaacbc
^     ^
*/

class Solution {
    bool isPalin(string &s, int l, int r) { // l = 2, r = 4
        if (l >= r) {
            return true;
        }
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
public:
    bool validPalindrome(string s) { // s = "abcbda"
        int l = 0;                         // 0
        int r = s.size() - 1;              // 1
        while (l < r) {
            if (s[l] == s[r]) {
                ++l;
                --r;
            } else {
                return isPalin(s, l + 1, r) || isPalin(s, l, r - 1);
            }
        }
        return true;
    }
};