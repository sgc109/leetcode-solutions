class Solution {
    string reverseAndSwap(string& s) {
        string ret = "";
        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] == 'R') ret += 'L';
            else if(s[i] == 'L') ret += 'R';
            else ret += s[i];
        }
        return ret;
    }
    bool matchL(string& start, string& end) {
        int N = start.size();
        int cntLinStart = 0;
        for(int i = N - 1; i >= 0; --i) {
            if(start[i] == 'R') {
                if(cntLinStart > 0) return false;
            }
            if(end[i] == 'R') {
                if(cntLinStart > 0) return false;
            }
            if(start[i] == 'L') ++cntLinStart;
            if(end[i] == 'L') {
                if(cntLinStart == 0) return false;
                --cntLinStart;
            }
        }
        return cntLinStart == 0;
    }
public:
    bool canTransform(string start, string end) {
        if(!matchL(start, end)) return false;
        string s = reverseAndSwap(start);
        string e = reverseAndSwap(end);
        return matchL(s, e);
    }
};