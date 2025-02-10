class Solution {
    bool isNum(char c) {
        return '0' <= c && c <= '9';
    }

    pair<int, int> parsePrefixNum(string& str, int pos) {
        assert(isNum(str[pos]));
        int i;
        for(i = pos; i < str.size(); ++i) {
            if(!isNum(str[i])) {
                break;
            }
        }
        int num = stoi(str.substr(pos, i - pos));
        return {num, i};
    }

    bool checkIsValid(string& word, int pos1, string& abbr, int pos2) {
        if(pos1 == word.size() && pos2 == abbr.size()) {
            return true;
        }
        if(pos1 == word.size() || pos2 == abbr.size()) {
            return false;
        }
        if(abbr[pos2] == '0') {
            return false;
        }
        if(!isNum(abbr[pos2])) {
            if(word[pos1] != abbr[pos2]) {
                return false;
            }
            return checkIsValid(word, pos1 + 1, abbr, pos2 + 1);
        } else {
            auto result = parsePrefixNum(abbr, pos2);
            int num = result.first;
            int nextIdx = result.second;
            if(word.size() - pos1 < num) {
                return false;
            }
            return checkIsValid(word, pos1 + num, abbr, nextIdx);
        }
    }
public:
    bool validWordAbbreviation(string word, string abbr) {
        return checkIsValid(word, 0, abbr, 0);
    }
};