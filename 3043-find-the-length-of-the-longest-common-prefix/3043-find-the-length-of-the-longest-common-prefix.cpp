class Solution {
    struct Trie {
        Trie* next[10] = {0, };
    };
    
    void insert(Trie* cur, string& str, int pos) {
        if(pos == size(str)) {
            return;
        }
        int digit = str[pos] - '0';
        if(!cur->next[digit]) {
            cur->next[digit] = new Trie();
        }
        insert(cur->next[digit], str, pos + 1);
    }
    
    int find(Trie* cur, string& str, int pos) {
        if(pos == size(str)) {
            return pos;
        }
        int digit = str[pos] - '0';
        if(!cur->next[digit]) {
            return pos;
        }
        return find(cur->next[digit], str, pos + 1);
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* root = new Trie();
        for(int num : arr1) {
            string strNum = to_string(num);
            insert(root, strNum, 0);
        }
        int ans = 0;
        for(int num : arr2) {
            string strNum = to_string(num);
            int longestPrefix = find(root, strNum, 0);
            ans = max(ans, longestPrefix);
        }
        
        return ans;
    }
};