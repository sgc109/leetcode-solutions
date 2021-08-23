class Trie {
    bool isEnd;
    vector<Trie*> nexts;
public:
    /** Initialize your data structure here. */
    Trie() {
        nexts = vector<Trie*>(26, nullptr);
        isEnd = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        insert(word, 0);
    }
    
    void insert(string& word, int pos) {
        if(pos == word.size()) {
            isEnd = true;
            return;
        }
        int nxtPos = word[pos] - 'a';
        if(nexts[nxtPos] == nullptr) {
            nexts[nxtPos] = new Trie();
        }
        nexts[nxtPos]->insert(word, pos + 1);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search(word, 0);
    }
    
    bool search(string& word, int pos) {
        if(pos == word.size()) {
            return isEnd;
        }
        int nxtPos = word[pos] - 'a';
        if(nexts[nxtPos] == nullptr) {
            return false;
        }
        return nexts[nxtPos]->search(word, pos + 1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWith(prefix, 0);
    }
    
    bool startsWith(string& prefix, int pos) {
        if(pos == prefix.size()) {
            return true;
        }
        int nxtPos = prefix[pos] - 'a';
        if(nexts[nxtPos] == nullptr) {
            return false;
        }
        return nexts[nxtPos]->startsWith(prefix, pos + 1);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */