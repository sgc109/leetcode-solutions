/*
1 2 4 3 5 6
*/

class Solution {
    unordered_map<char, int> priorities;
    bool compare(string& s1, string& s2) {
        int i = 0;
        while(i < s1.size() && i < s2.size()) {
            if(priorities[s1[i]] < priorities[s2[i]]) {
                return true;
            } else if(priorities[s1[i]] > priorities[s2[i]]) {
                return false;
            }
            ++i;
        }
        return s1.size() <= s2.size();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.size(); ++i) {
            priorities[order[i]] = i;
        }
        for(int i = 0; i < words.size() - 1; ++i) {
            auto& word1 = words[i];
            auto& word2 = words[i + 1];
            if(!compare(word1, word2)) {
                return false;
            }
        }
        return true;
    }
};