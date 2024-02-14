typedef long long ll;

class Solution {
    const ll BASE = 5;
    const ll MOD = 1e9 + 7;
    vector<ll> powers;
    bool compare(vector<int>& a, vector<int>& b) {
        if(a.size() != b.size()) {
            return false;
        }
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int N = nums.size();
        int M = pattern.size();
        powers.resize(M + 1);
        powers[0] = 1;
        for(int i = 1; i <= M; ++i) {
            powers[i] = powers[i - 1] * BASE % MOD;
        }
        vector<int> trans(N - 1);
        for(int i = 0; i < N - 1; ++i) {
            if(nums[i] < nums[i + 1]) {
                trans[i] = 1;
            } else if(nums[i] == nums[i + 1]) {
                trans[i] = 0;
            } else {
                trans[i] = -1;
            }
        }
        ll hash = 0;
        for(int i = 0; i < M; ++i) {
            hash = hash * BASE + pattern[i] + 3;
            hash %= MOD;
        }
        ll cmpHash = 0;
        for(int i = 0; i < M; ++i) {
            cmpHash = cmpHash * BASE + trans[i] + 3;
            cmpHash %= MOD;
        }
        int ans = 0;
        for(int i = 0; i < trans.size() - M + 1; ++i) {
            if(hash == cmpHash) {
                ++ans;
            }
            if(i == (trans.size() - M)) {
                break;
            }
            cmpHash -= powers[M - 1] * (trans[i] + 3) % MOD;
            cmpHash += MOD;
            cmpHash *= BASE;
            cmpHash += trans[i + M] + 3;
            cmpHash %= MOD;
        }
        
        return ans;
    }
};
