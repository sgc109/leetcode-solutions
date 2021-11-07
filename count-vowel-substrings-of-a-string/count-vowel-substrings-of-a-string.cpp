class Solution {
    int count[26] = {0, };
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
        bool found = false;
        int vowelCnt = 0;
        for(r = 0; r < N; ++r) {
            char ch = word[r];
            if(!isVowel(ch)) {
                if(found) {
                    memset(count, 0, sizeof(count));
                    vowelCnt = 0;
                    found = false;
                }
                l = r + 1;
            } else {
                if(!found) {
                    found = true;
                }
                int& target = count[ch - 'a'];
                ++target;
                if(target == 1) {
                    ++vowelCnt;
                }
                while(vowelCnt == 5) {
                    ans += nextConso[r] - r;
                    char ch = word[l++];
                    int& target = count[ch - 'a'];
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