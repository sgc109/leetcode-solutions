class Solution {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    bool isVowel(char c) {
        return vowels.count(tolower(c));
    }
public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string word;
        string ans = "";
        int seq = 1;
        while(getline(ss, word, ' ')) {
            if(seq > 1) {
                ans += ' ';
            }
            if(isVowel(word[0])) {
                ans += word;
                ans += "ma";
            } else {
                ans += word.substr(1);
                ans += word[0];
                ans += "ma";
            }
            ans += string(seq, 'a');
            ++seq;
        }
        return ans;
    }
};