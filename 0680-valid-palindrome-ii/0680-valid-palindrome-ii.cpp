/*
bcaacbc
^     ^
*/

class Solution {
    bool checkPalin(string& s, int l, int r) { // s = bcaacbc, l = 3, r = 4
        while(l < r) {
            if(s[l] != s[r]) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
public:
    bool validPalindrome(string s) { // bcaacbc
        int l = 0; // 0
        int r = s.size() - 1; // 6
        while(l < r) {
            if(s[l] != s[r]) { // b != c
                return checkPalin(s, l + 1, r) || checkPalin(s, l, r - 1);
            }
            ++l;
            --r;
        }
        return true;
    }
};