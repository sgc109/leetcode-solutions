class WordDictionary {
    unordered_set<string> dict;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        dict.insert(word);
        int len = word.size();
        for(int i = 0; i < len; ++i) {
            string s = word.substr(0, i) + "." + word.substr(i+1, len);
            dict.insert(s);
        }
    }
    
    bool search(string word) {
        int cntDots = 0;
        int dotPos = -1;
        for(int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if(c == '.') {
                ++cntDots;
                dotPos = i;
            }
        }
        if(cntDots <= 1) {
            return dict.count(word) > 0;
        }
        for(int i = 0; i < 26; ++i) {
            string s = word.substr(0, dotPos) + (char)('a'+i) + word.substr(dotPos+1, word.size());
            if(dict.count(s) > 0) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */