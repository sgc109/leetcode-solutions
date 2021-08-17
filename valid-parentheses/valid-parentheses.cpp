class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> match;
        match[')'] = '(';
        match['}'] = '{';
        match[']'] = '[';
        
        vector<char> stk;
        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                stk.push_back(c);
            } else {
                if(stk.size() == 0 || match[c] != stk.back()) return false;
                stk.pop_back();
            }
        }
        return stk.size() == 0;
    }
};
