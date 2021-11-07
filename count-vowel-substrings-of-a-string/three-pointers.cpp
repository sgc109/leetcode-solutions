class Solution {
    unordered_map<char,int> count;
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    int countVowelSubstrings(string word) {
        int N = word.size();
        int ans = 0;
        int l = 0, m = 0, r = 0;
        int vowelCnt = 0;
        for(r = 0; r < N; ++r) {
            char ch = word[r];
            if(!isVowel(ch)) {
                count['a'] = count['e'] = count['i'] = count['o'] = count['u'] = 0;
                vowelCnt = 0;
                l = m = r + 1;
            } else {
                int& target = count[ch];
                ++target;
                if(target == 1) {
                    ++vowelCnt;
                }
                while(vowelCnt == 5) {
                    char ch = word[m++];
                    int& target = count[ch];
                    --target;
                    if(target == 0) {
                        --vowelCnt;
                    }
                }
                ans += m - l;
            }
        }
        return ans;
    }
};
