typedef long long ll;

class Solution {
    int reverse(int origin) {
        string strNum = to_string(origin);
        ::reverse(strNum.begin(), strNum.end());
        return stoi(strNum);
    }

    ll calcAllCombs(ll size) {
        return size * (size - 1) / 2;
    }
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> counter;
        for(int num : nums) {
            int diff = num - reverse(num);
            counter[diff]++;
        }
        ll mod = 1e9 + 7;
        ll ans = 0;
        for(auto it : counter) {
            ans = (ans + calcAllCombs(it.second)) % mod;
        }
        return ans;
    }
};