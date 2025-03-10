class Solution {
public:
/*
        01234567890123456789
word = "appe"
            ^

        0123456
abbr = "a2ea"
           ^
*/
    bool validWordAbbreviation(string word, string abbr) {
        int p1 = 0; // 19
        int p2 = 0; // 6
        while(p1 < word.size() && p2 < abbr.size()) { // 20, 7
            if(isalpha(abbr[p2])) {
                if(word[p1] != abbr[p2]) {
                    return false;
                }
                ++p1;
                ++p2;
            } else {
                if(abbr[p2] == '0') {
                    return false;
                }
                int curNum = 0; // 2
                while(p2 < abbr.size() && isdigit(abbr[p2])) {
                    curNum = curNum * 10 + abbr[p2] - '0';
                    ++p2;
                }
                if(word.size() - p1 < curNum) {
                    return false;
                }
                p1 += curNum;
            }
        }
        return p1 == word.size() && p2 == abbr.size();
    }
};