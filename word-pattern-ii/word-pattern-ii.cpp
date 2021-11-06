class Solution {
    bool solve(int idxPattern, int idxStr, vector<string>& dict, unordered_set<string>& selected, string& pattern, string& s) {
        if(idxPattern == pattern.size() || 
           idxStr == s.size()) {
            return idxPattern == pattern.size() &&
                idxStr == s.size();
        }
        int alphaIdx = pattern[idxPattern] - 'a';
        if(dict[alphaIdx] != "") {
            int len = dict[alphaIdx].size();
            if(s.size() - idxStr < len) return false;
            if(dict[alphaIdx] != s.substr(idxStr, len)) return false;
            return solve(idxPattern + 1, idxStr + len, dict, selected, pattern, s);
        }

        string cur = "";
        for(int i = 0; idxStr + i < s.size(); ++i) {
            cur += s[idxStr + i];
            if(selected.find(cur) != selected.end()) continue;
            dict[alphaIdx] = cur;
            selected.insert(cur);
            if(solve(idxPattern + 1, idxStr + i + 1, dict, selected, pattern, s)) return true;
            dict[alphaIdx] = "";
            selected.erase(cur);
        }
        
        return false;
    }
public:
    bool wordPatternMatch(string pattern, string s) {
        if(pattern.size() > s.size()) return false;
        vector<string> dict(26, "");
        unordered_set<string> selected;
        
        return solve(0, 0, dict, selected, pattern, s);
    }
};