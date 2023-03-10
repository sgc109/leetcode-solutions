class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, char> mapping;
        unordered_map<char, char> revMapping;
        
        for(int i = 0; i < t.size(); ++i) {
            char from = s[i];
            char to = t[i];
            if(mapping.count(from) == 0) {
                 if(revMapping.count(to) == 0) {
                    mapping[from] = to;
                    revMapping[to] = from;
                 } else {
                     return false;
                 }
            } else if(mapping[from] != to) {
                return false;
            }
        }
        return true;
    }
};