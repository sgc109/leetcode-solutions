class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) { // word = "substitution", abbr = "s010n",
        int p1 = 0;                       // 1
        int p2 = 0;                       // 1
        int curNum = 0;                   // 0
        while (p1 < word.size() && p2 < abbr.size()) { // 12, 2
            if (isalpha(abbr[p2])) {
                if (word[p1] != abbr[p2]) {
                    return false;
                } else {
                    ++p1;
                    ++p2;
                }
                } else {
                if (curNum == 0 && abbr[p2] == '0') {
                    return false;
                }
                while (p2 < abbr.size() && isdigit(abbr[p2])) {
                    curNum = curNum * 10 + abbr[p2] - '0';
                    ++p2;
                }
                if (word.size() - p1 < curNum) {
                    return false;
                }
                p1 += curNum;
                curNum = 0;
            }
        }
        return p1 == word.size() && p2 == abbr.size();
    }
};