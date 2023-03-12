class Solution {
    bool check(string& timeStr) {
        return stoi(timeStr.substr(0, 2)) < 24 && stoi(timeStr.substr(3, 2)) < 60;
    }
    
    int go(string& str, int pos) {
        if(str.size() == pos) {
            return check(str);
        }
        if(str[pos] == ':' || ('0' <= str[pos] && str[pos] <= '9')) {
            return go(str, pos + 1);
        }
        int ans = 0;
        for(int i = 0; i <= 9; ++i) {
            str[pos] = '0' + i;
            ans += go(str, pos + 1);
        }
        str[pos] = '?';
        return ans;
    }
public:
    int countTime(string time) {
        return go(time, 0);
        
    }
};