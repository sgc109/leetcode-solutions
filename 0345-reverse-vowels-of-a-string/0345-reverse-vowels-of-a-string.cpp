class Solution {
    bool isVowel(char c, unordered_set<char>& vowelSet) {
        return vowelSet.count(c) != 0;
    }
public:
    string reverseVowels(string str) {
        unordered_set<char> vowelSet;
        for(char c : "aeiouAEIOU") {
            vowelSet.insert(c);
        }

        vector<char> vowels;
        for(char c : str) {
            if(isVowel(c, vowelSet)) {
                vowels.push_back(c);
            }
        }

        string ans = "";
        for(char c : str) {
            if(isVowel(c, vowelSet)) {
                ans += vowels.back();
                vowels.pop_back();
            } else {
                ans += c;
            }
        }

        return ans;
    }
};