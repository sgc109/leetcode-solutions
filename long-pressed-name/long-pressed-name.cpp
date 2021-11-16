class Solution {
    void transform(vector<pair<char,int>>& v, string& s) {
        int cnt = 0;
        char prv = -1;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != prv) {
                if(cnt > 0) {
                    v.emplace_back(prv, cnt);
                }
                cnt = 1;
                prv = s[i];
            } else {
                ++cnt;
            }
        }
        if(cnt > 0) {
            v.emplace_back(prv, cnt);
        }
    }
public:
    bool isLongPressedName(string name, string typed) {
        vector<pair<char,int>> nameChars, typedChars;
        transform(nameChars, name);
        transform(typedChars, typed);
        if(nameChars.size() != typedChars.size()) return false;
        for(int i = 0; i < nameChars.size(); ++i) {
            auto namePair = nameChars[i];
            auto typedPair = typedChars[i];
            if(namePair.first != typedPair.first) return false;
            if(namePair.second > typedPair.second) return false;
        }
        return true;
    }
};