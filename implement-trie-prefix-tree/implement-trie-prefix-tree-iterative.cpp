class Trie {
    bool isEnd;
    vector<Trie*> nexts;
public:
    /** Initialize your data structure here. */
    Trie() {
        this->isEnd = false;
        this->nexts = vector<Trie*>(26, nullptr);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur = this;
        for(char ch : word) {
            int idx = ch - 'a';
            if(cur->nexts[idx] == nullptr) {
                cur->nexts[idx] = new Trie();
            }
            cur = cur->nexts[idx];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur = this;
        for(char ch : word) {
            int idx = ch - 'a';
            if(cur->nexts[idx] == nullptr) {
                return false;
            }
            cur = cur->nexts[idx];
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur = this;
        for(char ch : prefix) {
            int idx = ch - 'a';
            if(cur->nexts[idx] == nullptr) {
                return false;
            }
            cur = cur->nexts[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
