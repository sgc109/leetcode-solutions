class Solution {
    bool isPeak(int idx, vector<int>& nums) {
        bool l = idx == 0 || nums[idx - 1] < nums[idx];
        bool r = (idx == nums.size() - 1) || nums[idx] > nums[idx + 1];
        return l && r;
    }
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        if(isPeak(lo, nums)) return lo;
        if(isPeak(hi, nums)) return hi;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(isPeak(mid, nums)) return mid;
            else if(nums[mid] < nums[mid+1]) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
    }
};