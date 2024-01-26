class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int N = size(nums);
        int lo = 0, hi = N - 1;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(lo == mid) {
                int cntBetween = nums[hi] - nums[lo] - 1;
                if(cntBetween >= k) {
                    return nums[lo] + k;
                }
                assert(hi == N - 1);
                k -= cntBetween;
                break;
            }
            int cntBetween = nums[mid] - nums[lo] - 1 - (mid - lo - 1);
            if(cntBetween >= k) {
                hi = mid;
            } else {
                k -= cntBetween;
                lo = mid;
            }
        }
        return nums.back() + k;
    }
};