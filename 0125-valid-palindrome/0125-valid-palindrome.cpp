class Solution {
public:
    // "A man, a plan, a canal: Panama"
    //                   ^            
    bool isPalindrome(string s) {
        int l = 0; // 0
        int r = s.size() - 1; // 29
        while(l < r) {
            while(l < r && !isalnum(s[l])) {
                ++l;   
            }
            while(l < r && !isalnum(s[r])) {
                --r;
            } 
            if(l == r) {
                return true;
            }
            if(tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            ++l;
            --r;
        }
        
        return true;
    }
};