typedef long long ll;

class Solution {
    bool possi(int limit, int max, vector<int>& nums) {
        ll acc = 0;
        for(int& num : nums) {
            acc += (num - 1) / limit;
        }
        return acc <= max;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int max = *max_element(begin(nums), end(nums));
        int lo = 1, hi = max;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(possi(mid, maxOperations, nums)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};