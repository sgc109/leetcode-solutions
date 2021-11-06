class Solution {
    int count[26];
public:
    bool canPermutePalindrome(string s) {
        for(char ch : s) {
            ++count[ch - 'a'];
        }
        int cntOdd = 0;
        for(int i = 0; i < 26; ++i) {
            if(count[i] % 2 == 1) {
                ++cntOdd;
            }
        }
        
        return cntOdd <= 1;
    }
};