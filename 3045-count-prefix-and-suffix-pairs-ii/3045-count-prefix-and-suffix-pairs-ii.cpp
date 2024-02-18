typedef long long ll;

class Solution {
    ll MOD = 1e9 + 9;
    ll BASE = 29;
    ll pow[100003];
    unordered_map<ll, pair<unordered_map<ll, int>, int>> map;
    
    ll hash(string& str) {
        ll ret = 0;
        for(auto ch : str) {
            ret = ret * BASE + ch - 'a' + 1;
            ret %= MOD;
        }
        return ret;
    }
    
    void calcPowers() {
        pow[0] = 1;
        for(int i = 1; i <= 100000; ++i) {
            pow[i] = pow[i - 1] * BASE % MOD;
        }
    }
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        calcPowers();
        int N = size(words);
        
        ll ans = 0;
        for(int i = N - 1; i >= 0; --i) {\
            string curStr = words[i];
            
            ll h = hash(curStr);
            ans += map[h].second;
            
            ll curH = 0;
            for(int j = 0; j < size(curStr); ++j) {
                curH = curH * BASE + curStr[j] - 'a' + 1;
                curH %= MOD;
                map[curH].first[i]++;
            }
            curH = 0;
            for(int j = size(curStr) - 1; j >= 0; --j) {
                curH += pow[size(curStr) - 1 - j] * (curStr[j] - 'a' + 1);
                curH %= MOD;
                map[curH].first[i]++;
                if(map[curH].first[i] == 2) {
                    map[curH].second++;
                }
            }
        }
        return ans;
    }
};