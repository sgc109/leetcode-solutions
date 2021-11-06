class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        unordered_set<string> selected;
        int prv = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ') {
                int len = i - prv;
                string word = s.substr(prv, len);
                words.push_back(word);
                prv = i + 1;
            }
        }
        words.push_back(s.substr(prv, s.size() - prv));
        if(words.size() != pattern.size()) return false;
        vector<string> mapping(26, "");
        for(int i = 0; i < pattern.size(); ++i) {
            char ch = pattern[i];
            string word = words[i];
            if(mapping[ch - 'a'] == "") {
                if(selected.find(word) != selected.end()) return false;
                mapping[ch - 'a'] = word;
                selected.insert(word);
            } else if(mapping[ch - 'a'] != word) {
                return false;   
            }
        }
        return true;
    }
};