class Solution {
    unordered_map<char,int> count;
    int nextConso[103];
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    int countVowelSubstrings(string word) {
        int N = word.size();
        int last = N;
        for(int i = N - 1; i >= 0; --i) {
            nextConso[i] = last;
            if(!isVowel(word[i])) last = i;
        }
        int ans = 0;
        int l = 0, r = 0;
        int vowelCnt = 0;
        for(r = 0; r < N; ++r) {
            char ch = word[r];
            if(!isVowel(ch)) {
                count['a'] = count['e'] = count['i'] = count['o'] = count['u'] = 0;
                vowelCnt = 0;
                l = r + 1;
            } else {
                int& target = count[ch];
                ++target;
                if(target == 1) {
                    ++vowelCnt;
                }
                while(vowelCnt == 5) {
                    ans += nextConso[r] - r;
                    char ch = word[l++];
                    int& target = count[ch];
                    --target;
                    if(target == 0) {
                        --vowelCnt;
                    }
                }
            }
        }
        return ans;
    }
};
