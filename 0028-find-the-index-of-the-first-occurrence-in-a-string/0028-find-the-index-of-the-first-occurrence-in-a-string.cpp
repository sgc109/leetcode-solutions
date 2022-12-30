typedef long long ll;
class Solution {
    ll pow;
    ll mod = 1e9 + 7;
    ll base = 29;
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        pow = 1;
        for(int i = 0; i < m - 1; ++i) {
            pow = pow * base % mod;
        }
        ll hash = 0;
        for(int i = 0; i < m; ++i) {
            hash = hash * base + needle[i] - 'a' + 1;
            hash %= mod;
        }
        ll targetHash = hash;
        hash = 0;
        for(int i = 0; i < m; ++i) {
            hash = hash * base + haystack[i] - 'a' + 1;
            hash %= mod;
        }
        if(hash == targetHash) {
            return 0;
        }
        for(int i = m; i < n; ++i) {
            hash = (hash - (haystack[i - m] - 'a' + 1) * pow % mod + mod) % mod;
            hash = hash * base % mod;
            hash = (hash + haystack[i] - 'a' + 1) % mod;
            if(hash == targetHash) {
                return i - m + 1;
            }
        }
        return -1;
    }
};