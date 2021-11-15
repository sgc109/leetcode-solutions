class Solution {
    int convert(string& s) {
        int last = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '#') last = max(0, last-1);
            else s[last++] = s[i];
        }
        return last;
    }
public:
    bool backspaceCompare(string s, string t) {
        int lastS = convert(s);
        int lastT = convert(t);
        if(lastS != lastT) return false;
        for(int i = 0; i < lastS; ++i) {
            if(s[i] != t[i]) return false;
        }
        return true;
    }
};