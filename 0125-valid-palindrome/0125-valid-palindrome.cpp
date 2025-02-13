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

    bool isAlphaNumeric(char c) {
        return isLower(c) || isUpper(c) || isNumeric(c);
    }

    char toLower(char c) {
        if(isUpper(c)) {
            return (char)(c - 'A' + 'a');
        }
        return c;
    }
public:
    // "A man, a plan, a canal: Panama"
    //                   ^            
    bool isPalindrome(string s) {
        int l = 0; // 0
        int r = s.size() - 1; // 29
        while(l < r) {
            while(l < r && !isAlphaNumeric(s[l])) {
                ++l;   
            }
            while(l < r && !isAlphaNumeric(s[r])) {
                --r;
            } 
            if(l == r) {
                return true;
            }
            if(toLower(s[l]) != toLower(s[r])) {
                return false;
            }
            ++l;
            --r;
        }
        
        return true;
    }
};