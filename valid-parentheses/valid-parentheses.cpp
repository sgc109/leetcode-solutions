class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> match;
        match[')'] = '(';
        match['}'] = '{';
        match[']'] = '[';
        
        stack<char> stk;
        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if(stk.empty() || match[c] != stk.top()) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};