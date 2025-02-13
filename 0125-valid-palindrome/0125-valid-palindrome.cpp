class Solution {
    bool isLower(char c) {
        return 'a' <= c && c <= 'z';
    }

    bool isUpper(char c) {
        return 'A' <= c && c <= 'Z';
    }

    bool isNumeric(char c) {
        return '0' <= c && c <= '9';
    }
public:
    bool isPalindrome(string s) { // " "
        string newS = ""; // ""
        for(char c : s) { // ' '
            if(isLower(c) || isNumeric(c)) {
                newS += c;
            } else if(isUpper(c)) {
                newS += (char)(c - 'A' + 'a');
            }
        }
        int N = newS.size(); // 0
        for(int i = 0; i < N / 2; ++i) {
            if(newS[i] != newS[N - i - 1]) {
                return false;
            }
        }
        return true;
    }
};