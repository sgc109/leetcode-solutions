typedef long long ll;

class Solution {
    ll dp[100003];
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    long long countVowels(string word) {
        int N = word.size();
        dp[0] = isVowel(word[0]) ? 1 : 0;
        for(int i = 1; i < N; ++i) {
            char ch = word[i];
            if(!isVowel(ch)) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = dp[i-1] + i + 1;
            }
        }
        
        ll sum = 0;
        for(int i = 0; i < N; ++i) {
            sum += dp[i];
        }
        return sum;
    }
};