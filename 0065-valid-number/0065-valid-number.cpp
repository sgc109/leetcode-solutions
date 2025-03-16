/*

(+/-)(0-9)(.)(0-9)(e/E 0-9)
*/

class Solution {
public: // "-123.456e789"
    bool isNumber(string s) {
        unordered_map<string,int> dfa[] = {
            {{"digit", 1}, {"sign", 2}, {"dot", 3}}, // state = 0
            {{"digit", 1}, {"dot", 4}, {"e", 5}}, // state = 1 (final)
            {{"digit", 1}, {"dot", 3}}, // state = 2
            {{"digit", 4}}, // state = 3
            {{"digit", 4}, {"e", 5}}, // state = 4 (final)
            {{"sign", 6}, {"digit", 7}}, // state = 5
            {{"digit", 7}}, // state = 6
            {{"digit", 7}} // state = 7 (final)
        };
        int state = 0;
        string group;
        for(char c : s) {
            if(isdigit(c)) {
                group = "digit";
            } else if(c == '+' || c == '-') {
                group = "sign";
            } else if(c == '.') {
                group = "dot";
            } else if(tolower(c) == 'e') {
                group = "e";
            } else {
                return false;
            }
            if(dfa[state].find(group) == dfa[state].end()) {
                return false;
            }
            state = dfa[state][group];
        }
        return state == 1 || state == 4 || state == 7;
    }
};