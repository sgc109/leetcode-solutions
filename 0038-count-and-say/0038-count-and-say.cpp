/*
1
11
21
1211
111221
312211
13112221
1113213211
31131211131221
13211311123113112211

*/
class Solution {
    string encode(string& s) {
        int cnt = 1;
        string ret = "";
        char prev = s[0];
        for(int i = 1; i < s.size(); ++i) {
            if(prev != s[i]) {
                ret += cnt + '0';
                ret += prev;
                cnt = 1;
                prev = s[i];
            } else {
                ++cnt;
            }
        }
        ret += cnt + '0';
        ret += prev;
        return ret;
    }
public:
    string countAndSay(int n) {
        string s = "1";
        while(--n) {
            s = encode(s);
        }
        return s;
    }
};